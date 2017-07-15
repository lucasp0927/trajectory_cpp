#ifndef BASEPHYSYSTEM_H
#define BASEPHYSYSTEM_H
#include <glog/logging.h>
#include "Fields.h"
namespace physystem
{
  using namespace fields;

  template <unsigned long DIM>
    class BasePhySystem
    {
    public:
      BasePhySystem(FieldNode<DIM>* const f);
      ~BasePhySystem()=default;
    protected:
      FieldNode<DIM>* const fieldroot;
    private:
    };


  template <unsigned long DIM>
    class NonInteractingPhySystem: public BasePhySystem<DIM>
    {
    public:
      NonInteractingPhySystem(FieldNode<DIM>* const f);
      ~NonInteractingPhySystem()=default;
    protected:

    private:

    };
}
#endif
