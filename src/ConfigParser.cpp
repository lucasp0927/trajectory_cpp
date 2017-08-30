#include "ConfigParser.h"
namespace configparser
{
  ConfigParser::ConfigParser(int const argc, char const* const argv[])
  {
    LOG(INFO) << "initializing ConfigParser";
    generic_opt = new po::options_description("Allowed options");
    hidden_opt = new po::options_description("Hidden options");
    cmdline_opt = new po::options_description("Commandline options");
    generic_opt->add_options()
      ("help", "produce help message")
      ("config,C", po::value<std::string>()->required(),"Configuration YAML file")
      ("inputfile,I", po::value<std::string>(),"Input file prefix")
      ("outputfile,O", po::value<std::string>(),"Output file prefix")
      ("procs,P",po::value<int>()->default_value(2),"processes number, default to 2")
      ("trajectory,T","Calculate trajectories")
      ("spectrum,S","Calculate spectrum")
      ("movie,M","Render movie")
      ;

    hidden_opt->add_options()
      ("trajinit","Just initialize TrajAnalyzer")
      ("moviedata","output movie potential data in a 3D array")
      ("irange", po::value<std::string>(), "range of scaning variable i, exp: 1:1:10")
      ;

    (*cmdline_opt).add(*generic_opt).add(*hidden_opt);
    parse_command_line(argc, argv);
    parse_config_file(vm["config"].as<std::string>());

    std::string const sim_type = config["simulation-type"].as<std::string>();
    if(sim_type=="1D")
      dim = 1;
    else if(sim_type=="2D")
      dim = 2;
    else if(sim_type=="3D")
      dim = 3;
    else
      throw ConfigException("Wrong simulation-type.");
  }

  void ConfigParser::parse_command_line(int const argc, char const* const argv[])
  {
    po::store(po::parse_command_line(argc, argv, *cmdline_opt), vm);
    if (vm.count("help")) {
      std::cout << *generic_opt << std::endl;
      return;
    }
    po::notify(vm); //check for error in user input.
  }

  void ConfigParser::parse_config_file(std::string filename)
  {
    LOG(INFO) << "Parse configure YAML file: "<<filename;
    config = YAML::LoadFile(filename);
    try{
      check_config();
    }
    catch (ConfigException& e){
      LOG(ERROR) << e.what();
      LOG(ERROR) << "Please correct configuration file: "<< filename;
    }
    fields_config = config["fields-config"];
    // std::string scaling = config["fields-config"]["field"]["scaling"].as<std::string>();
    // cout << scaling << endl;
  }

  bool ConfigParser::is_field_node(YAML::Node f) const
  {
    if (node_exist(f,"field-type") && node_exist(f,"dim")\
        && node_exist(f,"fields") && node_exist(f,"scaling"))
      return true;
    else
      return false;
  }

  void ConfigParser::check_config() const
  {
    //check if config has the right format.
    //TODO: check sub fields. and check values.
    std::string const required[] = {"simulation-type","fields-config","trajsolver-config","job-config"};
    for(std::string const &s : required)
      {
        if (!config[s])
          throw ConfigException(s+" not defined.");
      }

  }
  template <unsigned long DIM>
  std::shared_ptr<ScalarFieldNode<DIM>> ConfigParser::generate_fields()
  {
    assert(DIM==dim);
    std::shared_ptr<ScalarFieldNode<DIM>> ptr(new ScalarFieldNode<DIM>("test_field_yo",0));
    return ptr;
  }

  //explicit instantiating
  template std::shared_ptr<ScalarFieldNode<1>> ConfigParser::generate_fields();
  template std::shared_ptr<ScalarFieldNode<2>> ConfigParser::generate_fields();
  template std::shared_ptr<ScalarFieldNode<3>> ConfigParser::generate_fields();
}
