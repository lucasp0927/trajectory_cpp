#include "Atoms.h"
//use boost::object_pool?
namespace atoms
{
  template <unsigned long DIM>
  Atoms<DIM>::Atoms(unsigned int const atom_number):atom_number(atom_number)
  {
  }

  template <template <unsigned long> class atomtype, unsigned long DIM>
  NonInteractingAtoms<atomtype,DIM>::NonInteractingAtoms(unsigned int const atom_number): Atoms<DIM>(atom_number)
  {
    std::shared_ptr<atomtype<DIM>>   p1(new atomtype<DIM>());
    atoms.push_back(p1);

    LOG(INFO) << atoms.size();
  }
  //explicitly instantiating
  template class NonInteractingAtoms<PointParticle,1>;
  template class NonInteractingAtoms<PointParticle,2>;
  template class NonInteractingAtoms<PointParticle,3>;
}
