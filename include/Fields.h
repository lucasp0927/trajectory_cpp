#ifndef FIELDS_H
#define FIELDS_H
#include <iostream>
#include <glog/logging.h>
#include <complex>

using namespace std;
typedef complex<double> dcomplex;

template <typename T,int DIM>
  class AbstractField
{
 protected:
 public:
  AbstractField();
};

template <typename T, int DIM>
  class FieldNode: virtual public AbstractField <T, DIM>
{
 protected:
 public:
  FieldNode();
};

template <typename T,int DIM>
  class AbstractScalarField: virtual public AbstractField <T, DIM>
{
 protected:
 public:
  AbstractScalarField();
};

template <typename T,int DIM>
  class AbstractVectorField: virtual public AbstractField <T, DIM>
{
 protected:
 public:
  AbstractVectorField();
};

template <typename T,int DIM>
  class ScalarFieldNode: public AbstractScalarField <T, DIM>, public FieldNode <T, DIM>
{
 protected:
  AbstractField<T, DIM>** fields;
 public:
  ScalarFieldNode();
};


template <typename T,int DIM>
  class VectorFieldNode: public AbstractVectorField <T, DIM>, public FieldNode <T, DIM>
{
 protected:
  AbstractField<T, DIM>** fields;
 public:
  VectorFieldNode();
};

template <typename T,int DIM>
  class ScalarField: public AbstractScalarField <T, DIM>
{
 public:
  ScalarField();
};


template <typename T,int DIM>
  class VectorField: public AbstractVectorField <T, DIM>
{
 public:
  VectorField();
};
#endif
