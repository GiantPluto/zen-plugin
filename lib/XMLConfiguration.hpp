//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Plugin Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef ZEN_PLUGIN_XML_CONFIGURATION_HPP_INCLUDED
#define ZEN_PLUGIN_XML_CONFIGURATION_HPP_INCLUDED

#include <Zen/PluginI_Configuration.hpp>

#include "XMLConfigurationElement.hpp"

#include <boost/function.hpp>

#include <string>
#include <map>
#include <list>
#include <utility>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Plugin {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class XMLConfiguration
:   public I_Configuration
{
    /// @name Types
    /// @{
public:
    typedef XMLConfigurationElement::ptr_type                       config_element_ptr_type;
    typedef std::multimap<std::string, config_element_ptr_type>     config_collection_type;
    typedef std::pair<config_collection_type::key_type, 
                      config_collection_type::mapped_type>          config_pair_type;

    typedef boost::function<void (config_element_ptr_type)>         element_event_type;
    typedef std::map<std::string, element_event_type>               element_event_map_type;
    /// @}

    /// @name I_Configuration implementation
    /// @{
public:
    //virtual config_list_ptr_type getConfigurationElements();
    virtual I_ConfigurationElement::const_ptr_type getConfigurationElement(const std::string& _name) const;
    /// @}

    /// @name XMLConfiguration implementation
    /// @{
public:
    void listenElement(const std::string& _name, element_event_type _function);

    bool parse(const boost::filesystem::path& _configFile);

    void dispatchEvent(config_element_ptr_type _pElement);
    /// @}

    /// @name 'Structors
    /// @{
public:
             XMLConfiguration();
    virtual ~XMLConfiguration();
    /// @}

    /// @name Member variables
    /// @{
private:
    config_collection_type  m_config;
    element_event_map_type  m_elementEvents;
    /// @}

};	// class XMLConfiguration

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Plugin
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_PLUGIN_XML_CONFIGURATION_HPP_INCLUDED
