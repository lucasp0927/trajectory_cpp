#ifndef BASEPHYSYSTEM_H
#define BASEPHYSYSTEM_H
#include <glog/logging.h>
#include "Fields.h"
#include "Atoms.h"
#include "Atom.h"
namespace physystem
{
  using namespace fields;
  using namespace atoms;
  using namespace atom;
  template <unsigned long DIM>
    class BasePhySystem
    {
    public:
      BasePhySystem(ScalarFieldNode<DIM>* const f);
      ~BasePhySystem()=default;
    protected:
      ScalarFieldNode<DIM>* const fieldroot;
    private:
    };


  template <template <unsigned long> class atomtype,unsigned long DIM>
    class NonInteractingPhySystem: public BasePhySystem<DIM>
    {
    public:
      NonInteractingPhySystem(ScalarFieldNode<DIM>* const f,NonInteractingAtoms<atomtype, DIM>* const a);
      ~NonInteractingPhySystem()=default;
    protected:
      NonInteractingAtoms<atomtype, DIM>* const atoms;
    private:

    };
}
#endif
