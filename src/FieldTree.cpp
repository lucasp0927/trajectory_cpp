#include "FieldTree.h"
namespace fieldtree
{
  template <unsigned long DIM>
  FieldTree<DIM>::FieldTree()
  {
  }

  template <unsigned long DIM>
  FieldTree<DIM>::~FieldTree()
  {
    delete root;
  }

  //explicitly instantiating
  template class FieldTree<1>;
  template class FieldTree<2>;
  template class FieldTree<3>;
}
