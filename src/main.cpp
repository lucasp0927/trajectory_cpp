#include <iostream>
#include <glog/logging.h>
#include "ConfigParser.h"
#include "Fields.h"
#include "fileio.h"
//#include "boost/multi_array.hpp"

using namespace fileio;
int main(int argc, char* argv[])
{
  google::InitGoogleLogging(argv[0]);
  ConfigParser configparser;
  configparser.parse_command_line(argc, argv);

  // auto  data_out = read_complex_h5_file<3>("/home/lucaspeng/data/research/potential/Exy_60u_0_right_thick.h5","lattice");
  // print_multi_array(data_out);
  // auto  data_ted1 = read_double_h5_file<2>("/home/lucaspeng/data/research/potential/ted1.h5","ted1");
  // print_multi_array(data_ted1);
}
