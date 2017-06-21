#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H
#include <iostream>
#include <glog/logging.h>
#include <yaml-cpp/yaml.h>
#include <boost/program_options.hpp>
namespace po = boost::program_options;

using namespace std;

class ConfigParser
{
  po::options_description* cmdline_opt;
  po::options_description* generic_opt;
  po::options_description* hidden_opt;
  po::variables_map vm;//variable map
  YAML::Node config;
  void parse_range(string s);
  public:
  ConfigParser();
  ~ConfigParser() = default;
  void parse_command_line(int argc, char* argv[]);
  void parse_config_file(string filename);
};

#endif
