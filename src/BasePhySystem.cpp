#include "BasePhySystem.h"
namespace physystem
{
  template <unsigned long DIM>
  BasePhySystem<DIM>::BasePhySystem(ScalarFieldNode<DIM>* const f): fieldroot(f)
  {
    LOG(INFO) << "initializing BasePhySystem";
  }

  template <template <unsigned long> class atomtype, unsigned long DIM>
  NonInteractingPhySystem<atomtype, DIM>::NonInteractingPhySystem(ScalarFieldNode<DIM>* const f, \
                                                        NonInteractingAtoms<atomtype,DIM>* const a): BasePhySystem<DIM>(f), atoms(a)
  {
    LOG(INFO) << "initializing NonInteractingPhySystem";
  }

  //explicitly instantiating
  template class NonInteractingPhySystem<PointParticle,1>;
  template class NonInteractingPhySystem<PointParticle,2>;
  template class NonInteractingPhySystem<PointParticle,3>;
}
