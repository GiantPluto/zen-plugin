//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Plugin Framework
//
// Copyright (C) 2001 - 2018 Raymond A. Richards
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_PLUGIN_I_APPLICATION_HPP_INCLUDED
#define ZEN_PLUGIN_I_APPLICATION_HPP_INCLUDED

#include "Configuration.hpp"

// TODO Implement log_stream
// #include <Zen/Core/Utility/log_stream.hpp>

#include <list>
#include <memory>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen::Plugin {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class I_Configuration;

class PLUGIN_DLL_LINK I_Application
{
    /// @name Types
    /// @{
public:
    typedef std::shared_ptr<I_Application>                ptr_type;
    //typedef I_ConfigurationElement::config_list_type        config_list_type;
    //typedef I_ConfigurationElement::config_list_ptr_type    config_list_ptr_type;
    /// @}

    /// @name I_Application interface
    /// @{
public:
    /// Get the configuration elements that match the specified name.
    virtual const I_Configuration& getConfiguration() const = 0;

    virtual const std::string& getId() const = 0;
    virtual const std::string& getName() const = 0;
    virtual const std::string& getVersion() const = 0;
    virtual const std::string& getProviderName() const = 0;
    // TODO Implement logging
    // virtual Utility::log_stream& getLogStream() = 0;
    /// @}

    /// @{ 'Structors
protected:
             I_Application();
    virtual ~I_Application();
    /// @}

    // Not copyable nor assignable
    I_Application(const I_Application&) = delete;
    void operator=(const I_Application&) = delete;

};  // interface I_Application

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Zen::Plugin
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_PLUGIN_I_APPLICATION_HPP_INCLUDED

