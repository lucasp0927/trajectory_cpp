#ifndef ATOMS_H
#define ATOMS_H
#include <memory>
#include <glog/logging.h>
#include "Atom.h"
#include <vector>
namespace atoms
{
  using namespace atom;
  template <unsigned long DIM>
    class Atoms
    {
    public:
      Atoms(unsigned int const atom_number);
      ~Atoms()=default;
      virtual void test(){LOG(INFO)<<"Atoms";};
    protected:
      unsigned int const atom_number;
    private:
    };

  template <template <unsigned long> class atomtype, unsigned long DIM>
    class NonInteractingAtoms: public Atoms<DIM>
    {
    public:
      NonInteractingAtoms(unsigned int const atom_number);
      ~NonInteractingAtoms()=default;
    protected:
      std::vector<std::shared_ptr<atomtype<DIM>>> atoms;
    private:
    };
}

#endif
