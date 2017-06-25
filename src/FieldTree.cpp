#include "FieldTree.h"
template <int DIM>
FieldTree<DIM>::FieldTree(FieldNode<DIM>* _root):root(_root)
{
}

template <int DIM>
FieldTree<DIM>::~FieldTree()
{
}
//explicitly instantiating
template class FieldTree<2>;
template class FieldTree<3>;
