#include "BasePhySystem.h"
namespace physystem
{
  template <unsigned long DIM>
  BasePhySystem<DIM>::BasePhySystem(FieldNode<DIM>* const f): fieldroot(f)
  {
    LOG(INFO) << "initializing BasePhySystem";
    LOG(INFO) << fieldroot;
  }

  template <unsigned long DIM>
  NonInteractingPhySystem<DIM>::NonInteractingPhySystem(FieldNode<DIM>* const f): BasePhySystem<DIM>(f)
  {
    LOG(INFO) << "initializing NonInteractingPhySystem";
    LOG(INFO) << this->fieldroot;
  }

  //explicitly instantiating
  template class BasePhySystem<1>;
  template class BasePhySystem<2>;
  template class BasePhySystem<3>;
  template class NonInteractingPhySystem<1>;
  template class NonInteractingPhySystem<2>;
  template class NonInteractingPhySystem<3>;
}
