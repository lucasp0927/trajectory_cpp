#ifndef FIELDS_H
#define FIELDS_H
#include <iostream>
#include <glog/logging.h>
#include <boost/multi_array.hpp>
#include <complex>

using namespace std;
typedef complex<double> dcomplex;

template <int DIM>
  class AbstractField
{
 protected:
 public:
  AbstractField();
  ~AbstractField() = default;
};

template <int DIM>
  class FieldNode: virtual public AbstractField <DIM>
{
 protected:
 public:
  FieldNode();
  ~FieldNode() = default;
};

template <int DIM>
  class AbstractScalarField: virtual public AbstractField <DIM>
{
 protected:
 public:
  AbstractScalarField();
  ~AbstractScalarField() = default;
};

template <int DIM>
  class AbstractVectorField: virtual public AbstractField <DIM>
{
 protected:
 public:
  AbstractVectorField();
  ~AbstractVectorField() = default;
};

template <int DIM>
  class ScalarFieldNode: public AbstractScalarField <DIM>, public FieldNode <DIM>
{
 protected:
  AbstractField<DIM>** fields;
 public:
  ScalarFieldNode();
  ~ScalarFieldNode() = default;
};

template <int DIM>
  class VectorFieldNode: public AbstractVectorField <DIM>, public FieldNode <DIM>
{
 protected:
  AbstractVectorField<DIM>** fields;
 public:
  VectorFieldNode();
  ~VectorFieldNode() = default;
};

template <int DIM, typename T>
  class ScalarField: public AbstractScalarField <DIM>
{
 private:
  boost::multi_array<T,DIM>* field;
 public:
  ScalarField();
  ~ScalarField() = default;
};


template <int DIM, typename T>
  class VectorField: public AbstractVectorField <DIM>
{
 private:
  boost::multi_array<T,DIM+1>* field;
 public:
  VectorField();
};
#endif
