#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H
//#include <iostream>
#include <memory>
#include <stdexcept>
#include <glog/logging.h>
#include <yaml-cpp/yaml.h>
#include <boost/program_options.hpp>
#include <assert.h>
#include "fileio.h"
#include "Fields.h"
#include "gtest/gtest.h"

namespace configparser
{
  using namespace fields;
  namespace po = boost::program_options;

  class ConfigParser
  {
  private:
    unsigned long dim;
    po::options_description* cmdline_opt;
    po::options_description* generic_opt;
    po::options_description* hidden_opt;
    po::variables_map vm;//variable map
    YAML::Node config;
    FRIEND_TEST(ConfigParserTest, functionTest_node_exist);
    YAML::Node fields_config;
    void check_config() const;
    FRIEND_TEST(ConfigParserTest, functionTest_node_exist);
    bool is_field_node(YAML::Node f) const;
    FRIEND_TEST(ConfigParserTest, functionTest_node_exist);
    inline bool node_exist(YAML::Node node, std::string key) const;
  public:
    ConfigParser(int const argc, char const* const argv[]);
    ~ConfigParser() = default;
    void parse_command_line(int const argc, char const* const argv[]);
    void parse_config_file(std::string filename);
    template <unsigned long DIM>
      std::shared_ptr<ScalarFieldNode<DIM>> generate_fields();
  };

  struct ConfigException: public std::runtime_error
  {
  ConfigException(std::string const& message): std::runtime_error(message)
      {}
  };

  inline bool ConfigParser::node_exist(YAML::Node node, std::string key) const
  {
    if (node[key])
      return true;
    else
      return false;
  }
}
#endif
