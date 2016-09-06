//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Plugin Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
// Copyright (C) 2008 - 2009 Matthew Alan Gray
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//     claim that you wrote the original software. If you use this software
//     in a product, an acknowledgment in the product documentation would be
//     appreciated but is not required.
//  2. Altered source versions must be plainly marked as such, and must not be
//     misrepresented as being the original software.
//  3. This notice may not be removed or altered from any source distribution.
//
//  Tony Richards trichards@indiezen.com
//  Matthew Alan Gray mgray@indiezen.org
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_PLUGIN_STARTUP_SHUTDOWN_MANAGER_HPP_INCLUDED
#define ZEN_PLUGIN_STARTUP_SHUTDOWN_MANAGER_HPP_INCLUDED

#include "../I_StartupShutdownManager.hpp"

#include <Zen/Core/Threading/ThreadPool.hpp>

#include <Zen/PluginI_Configuration.hpp>

#include <set>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Plugin {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class StartupShutdownManager
:   public I_StartupShutdownManager
{
    /// @name Types
    /// @{
public:
    typedef std::set<pParticipant_type>     Participants_type;
    /// @}

    /// @name Enums
    /// @{
public:
    enum ManagerStates
    {
        INITIALIZED,
        STARTING,
        STARTED,
        STOPPING,
        STOPPED
    };
    /// @}

    /// @name I_StartupShutdownManager implementation
    /// @{
public:
    virtual Zen::Threading::I_Condition* start();
    virtual void stop();
    virtual void installParticipant(pParticipant_type _pParticipant);
    /// @}

    /// @name StartupShutdownManager implementation
    /// @{
public:
    /// Install a participant.
    ///
    /// This is called by an InstallParticipantTask that is queued into m_installQueue
    ///
    /// @note Internal use only
    void handleInstallParticipant(pParticipant_type);

    /// Return the manager's shared thread pool
    ///
    /// This is called during the startup process for installed participants.
    ///
    /// @note Internal use only
    Threading::ThreadPool& getSharedThreadPool() { return m_sharedThreadPool; }
    /// @}

    /// @name Events
    /// @{
public:
    /// @}

    /// @name 'Structors
    /// @{
public:
             StartupShutdownManager();
    virtual ~StartupShutdownManager();
    /// @}

    /// @name Member variables
    /// @{
private:
    ManagerStates   m_currentState;

    /// ThreadPool that's shared among all of the participants.
    Threading::ThreadPool   m_sharedThreadPool;

    /// Queue of items that require installation
    /// plus the thread that is used to perform
    /// the installation.
    Threading::ThreadPool   m_installQueue;

    /// Queue of items that require graceful shutdown
    /// plus the thread that is use to perform
    /// the shutdown.
    Threading::ThreadPool   m_shutdownQueue;

    /// Guard for m_participants consistency
    Threading::I_Mutex*     m_pParticipantGuard;

    /// Collection of installed participants
    Participants_type       m_participants;
    /// @}

};  // class StartupShutdownManager

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Plugin
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_PLUGIN_STARTUP_SHUTDOWN_MANAGER_HPP_INCLUDED
