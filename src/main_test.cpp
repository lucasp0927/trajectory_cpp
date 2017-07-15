#include <iostream>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include "ConfigParser.h"
#include "Fields.h"
#include "BasePhySystem.h"
#include "fileio.h"

using namespace fields;
using namespace physystem;
int main(int argc, char *argv[])
{
  ScalarFieldNode<2> sfn;
  NonInteractingPhySystem<2> NIPS(&sfn);
  std::srand(std::time(0));
  google::InitGoogleLogging(argv[0]);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
