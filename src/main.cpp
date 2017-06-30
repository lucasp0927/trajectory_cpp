#include <iostream>
#include <glog/logging.h>
#include "ConfigParser.h"
#include "Fields.h"
#include "FieldTree.h"
#include "fileio.h"
using namespace std;

int main(int argc, char* argv[])
{
  google::InitGoogleLogging(argv[0]);
  ConfigParser configparser;
  configparser.parse_command_line(argc, argv);

  read_h5_file("test2.h5","test");
  /////
  //  AbstractField AF;
  //VectorField<3,dcomplex> FN;
  //  FieldTree<2> FT(&FN);
}
