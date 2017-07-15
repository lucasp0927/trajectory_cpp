#ifndef FIELDS_H
#define FIELDS_H
#include <iostream>
#include <glog/logging.h>
#include <boost/multi_array.hpp>
#include <complex>

namespace fields
{
  typedef std::complex<double> dcomplex;

  template <unsigned long DIM>
    class AbstractField
    {
    protected:
    public:
      AbstractField();
      ~AbstractField() = default;
    };

  template <unsigned long DIM>
    class FieldNode: virtual public AbstractField <DIM>
    {
    protected:
    public:
      FieldNode();
      ~FieldNode() = default;
    };

  template <unsigned long DIM>
    class AbstractScalarField: virtual public AbstractField <DIM>
    {
    protected:
    public:
      AbstractScalarField();
      ~AbstractScalarField() = default;
    };

  template <unsigned long DIM>
    class AbstractVectorField: virtual public AbstractField <DIM>
    {
    protected:
    public:
      AbstractVectorField();
      ~AbstractVectorField() = default;
    };

  template <unsigned long DIM>
    class ScalarFieldNode: public AbstractScalarField <DIM>, public FieldNode <DIM>
  {
  protected:
    AbstractField<DIM>** fields;
  public:
    ScalarFieldNode();
    ~ScalarFieldNode() = default;
  };

  template <unsigned long DIM>
    class VectorFieldNode: public AbstractVectorField <DIM>, public FieldNode <DIM>
  {
  protected:
    AbstractVectorField<DIM>** fields;
  public:
    VectorFieldNode();
    ~VectorFieldNode() = default;
  };

  template <unsigned long DIM, typename T>
    class ScalarField: public AbstractScalarField <DIM>
  {
  private:
    boost::multi_array<T,DIM>* field;
  public:
    ScalarField();
    ~ScalarField() = default;
  };


  template <unsigned long DIM, typename T>
    class VectorField: public AbstractVectorField <DIM>
  {
  private:
    boost::multi_array<T,DIM+1>* field;
  public:
    void test() const;
    VectorField();
  };
}
#endif
