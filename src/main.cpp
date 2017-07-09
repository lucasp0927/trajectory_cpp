#include <iostream>
#include <glog/logging.h>
#include "ConfigParser.h"
#include "Fields.h"
#include "FieldTree.h"
#include "fileio.h"
#include "boost/multi_array.hpp"
using namespace std;

int main(int argc, char* argv[])
{
  google::InitGoogleLogging(argv[0]);
  ConfigParser configparser;
  configparser.parse_command_line(argc, argv);

  auto const* const data = read_complex_h5_file_4d("testc4.h5","test");
  print_multi_array(data);
  write_h5_file(data,"testc4out.h5","test");
  auto const* const data2 = read_complex_h5_file_4d("testc4out.h5","test");
  print_multi_array(data2);
  cout << (*data==*data2) << endl;
  delete data;
  delete data2;

  /////
  //  AbstractField AF;
  //VectorField<3,dcomplex> FN;
  //  FieldTree<2> FT(&FN);
}
