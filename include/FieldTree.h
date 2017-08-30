#ifndef FIELDTREE_H
#define FIELDTREE_H
#include "Fields.h"
#include <iostream>
#include <glog/logging.h>
namespace fieldtree
{
  using namespace fields;
  template <unsigned long DIM>
    class FieldTree
    {
    public:
      FieldTree();
      virtual ~FieldTree();
    protected:
      ScalarFieldNode<DIM>* root;
    private:
    };
}
#endif
