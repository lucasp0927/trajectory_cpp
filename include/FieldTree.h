#ifndef FIELDTREE_H
#define FIELDTREE_H
#include <iostream>
#include <glog/logging.h>
#include "Fields.h"
template <int DIM>
class FieldTree
{
 public:
  FieldNode<DIM>* root;
  FieldTree(FieldNode<DIM>*);
  ~FieldTree();
};
#endif
