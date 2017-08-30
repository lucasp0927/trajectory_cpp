#include <memory>
#include <glog/logging.h>
#include "ConfigParser.h"
#include "Fields.h"
#include "fileio.h"
#include "Atoms.h"
#include "Atom.h"
//#include "boost/multi_array.hpp"

using namespace fileio;
using namespace fields;
using namespace configparser;
int main(int argc, char* argv[])
{
  google::InitGoogleLogging(argv[0]);
  ConfigParser cp(argc,argv);
  auto sfn_2d_ptr = cp.generate_fields<2>();
  LOG(INFO)<<sfn_2d_ptr->get_name();
  LOG(INFO)<<sfn_2d_ptr->get_freq();
  atoms::NonInteractingAtoms<atom::PointParticle,2> a(100);
  // auto  data_out = read_complex_h5_file<3>("/home/lucaspeng/data/research/potential/Exy_60u_0_right_thick.h5","lattice");
  // print_multi_array(data_out);
  // auto  data_ted1 = read_double_h5_file<2>("/home/lucaspeng/data/research/potential/ted1.h5","ted1");
  // print_multi_array(data_ted1);
}
