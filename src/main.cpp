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

  auto const* const data = read_complex_h5_file<4>("test/testc4.h5","test");
  print_multi_array(data);
  auto const* const data2 = read_double_h5_file<3>("test/test3.h5","test");
  print_multi_array(data2);

  write_h5_file(data,"test/testc4out.h5","test");
  write_h5_file(data2,"test/testc4out.h5","test2",true);
  auto const* const data_out = read_complex_h5_file<4>("test/testc4out.h5","test");
  print_multi_array(data_out);
  auto const* const data2_out = read_double_h5_file<3>("test/testc4out.h5","test2");
  print_multi_array(data2_out);
  std::cout << (*data==*data_out) << std::endl;
  std::cout << (*data2==*data2_out) << std::endl;
  delete data;
  delete data2;
  delete data_out;
  delete data2_out;

  /////
  //  AbstractField AF;
  //VectorField<3,dcomplex> FN;
  //  FieldTree<2> FT(&FN);
}
