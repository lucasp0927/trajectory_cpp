#include <iostream>
#include <glog/logging.h>
#include <gtest/gtest.h>
#include "ConfigParser.h"
#include "Fields.h"
#include "FieldTree.h"
#include "Atoms.h"
#include "Atom.h"
#include "BasePhySystem.h"
#include "fileio.h"

using namespace fields;
using namespace fieldtree;
using namespace atoms;
using namespace physystem;
int main(int argc, char *argv[])
{
  ScalarFieldNode<2> sfn("test", 0.0);
  FieldTree<2> ft;
  NonInteractingAtoms<PointParticle,2> atoms(100);
  NonInteractingPhySystem<PointParticle,2> NIPS(&ft,&atoms);
  std::srand(std::time(0));
  google::InitGoogleLogging(argv[0]);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
