#include <iostream>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include "ConfigParser.h"
#include "Fields.h"
#include "FieldTree.h"
#include "fileio.h"

using namespace std;

int main(int argc, char *argv[])
{
  srand(time(0));
  google::InitGoogleLogging(argv[0]);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
