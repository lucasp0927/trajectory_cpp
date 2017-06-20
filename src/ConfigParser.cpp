#include "ConfigParser.h"

ConfigParser::ConfigParser()
{
  LOG(INFO) << "initializing ConfigParser";
  generic_opt = new po::options_description("Allowed options");
  hidden_opt = new po::options_description("Hidden options");
  cmdline_opt = new po::options_description("Commandline options");
  generic_opt->add_options()
    ("help", "produce help message")
    ("config,C", po::value<string>()->required(),"Configuration YAML file")
    ("inputfile,I", po::value<string>(),"Input file prefix")
    ("outputfile,O", po::value<string>(),"Output file prefix")
    ("procs,P",po::value<int>()->default_value(2),"processes number, default to 2")
    ("trajectory,T","Calculate trajectories")
    ("spectrum,S","Calculate spectrum")
    ("movie,M","Render movie")
    ;

  hidden_opt->add_options()
    ("trajinit","Just initialize TrajAnalyzer")
    ("moviedata","output movie potential data in a 3D array")
    ("irange", po::value<string>(), "range of scaning variable i, exp: 1:1:10")
    ;

  (*cmdline_opt).add(*generic_opt).add(*hidden_opt);
}

void ConfigParser::parse_command_line(int argc, char* argv[])
{
  po::store(po::parse_command_line(argc, argv, *cmdline_opt), vm);
  if (vm.count("help")) {
    cout << *generic_opt << "\n";
    return;
  }
  po::notify(vm); //check for error in user input.

  parse_config_file(vm["config"].as<string>());
}

void ConfigParser::parse_config_file(string filename)
{
  LOG(INFO) << "Parse configure YAML file.";
  YAML::Node config = YAML::LoadFile(filename);
  string scaling = config["fields-config"]["field"]["scaling"].as<string>();
  cout << scaling << endl;
}

void ConfigParser::parse_range(string s)
{
  cout << "test "<< s << endl;
}
