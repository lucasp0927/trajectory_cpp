#ifndef BASEPHYSYSTEM_H
#define BASEPHYSYSTEM_H
#include <glog/logging.h>
#include "FieldTree.h"
#include "Atoms.h"
#include "Atom.h"
namespace physystem
{
  using namespace fieldtree;
  using namespace fields;
  using namespace atoms;
  using namespace atom;
  template <unsigned long DIM>
    class BasePhySystem
    {
    public:
      BasePhySystem(FieldTree<DIM>* const f);
      virtual ~BasePhySystem()=default;
    protected:
      FieldTree<DIM>* const fieldtree;
    private:
    };


  template <template <unsigned long> class atomtype,unsigned long DIM>
    class NonInteractingPhySystem: public BasePhySystem<DIM>
    {
    public:
      NonInteractingPhySystem(FieldTree<DIM>* const f,NonInteractingAtoms<atomtype, DIM>* const a);
      virtual ~NonInteractingPhySystem()=default;
    protected:
      NonInteractingAtoms<atomtype, DIM>* const atoms;
    private:

    };
}
#endif
