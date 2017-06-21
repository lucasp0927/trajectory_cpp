#ifndef FIELDS_H
#define FIELDS_H
#include <iostream>
#include <glog/logging.h>
#include <complex>

using namespace std;

class AbstractField
{
 protected:
 public:
  int dim;
  AbstractField();
};

class AbstractScalarField: public AbstractField
{
 protected:
 public:
  AbstractScalarField();
};

class AbstractVectorField: public AbstractField
{
 protected:
 public:
  AbstractVectorField();
};

class ScalarFieldNode: public AbstractScalarField
{
 protected:
  AbstractField** fields;
 public:
  ScalarFieldNode();
};

class VectorFieldNode: public AbstractVectorField
{
 protected:
  AbstractField** fields;
 public:
  VectorFieldNode();
};

class ScalarField: public AbstractScalarField
{
 public:
  ScalarField();
};

class VectorField: public AbstractVectorField
{
 public:
  VectorField();
};
#endif
