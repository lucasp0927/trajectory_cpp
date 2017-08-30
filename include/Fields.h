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
      std::string const name;
      double const freq;
    public:
      AbstractField(std::string const _name, double const _freq);
      virtual ~AbstractField() = default;
      virtual std::string get_name() const {return name;};
      virtual double get_freq() const {return freq;};
    };

  template <unsigned long DIM>
    class FieldNode: virtual public AbstractField <DIM>
    {
    protected:
    public:
      FieldNode(std::string const _name, double const _freq);
      virtual ~FieldNode() = default;
    };

  template <unsigned long DIM>
    class AbstractScalarField: virtual public AbstractField <DIM>
    {
    protected:
    public:
      AbstractScalarField(std::string const _name, double const _freq);
      virtual ~AbstractScalarField() = default;
    };

  template <unsigned long DIM>
    class AbstractVectorField: virtual public AbstractField <DIM>
    {
    protected:
    public:
      AbstractVectorField(std::string const _name, double const _freq);
      virtual ~AbstractVectorField() = default;
    };

  template <unsigned long DIM>
    class ScalarFieldNode: public AbstractScalarField <DIM>, public FieldNode <DIM>
  {
  protected:
    AbstractField<DIM>** fields;
  public:
    ScalarFieldNode(std::string const _name, double const _freq);
    virtual ~ScalarFieldNode(){std::cout<<"SFN Destructor."<<std::endl;};
  };

  template <unsigned long DIM>
    class VectorFieldNode: public AbstractVectorField <DIM>, public FieldNode <DIM>
  {
  protected:
    AbstractVectorField<DIM>** fields;
  public:
    VectorFieldNode(std::string const _name, double const _freq);
    virtual ~VectorFieldNode() = default;
  };

  template <unsigned long DIM, typename T>
    class ScalarField: public AbstractScalarField <DIM>
  {
  private:
    boost::multi_array<T,DIM>* field;
  public:
    ScalarField(std::string const _name, double const _freq);
    virtual ~ScalarField() = default;
  };


  template <unsigned long DIM, typename T>
    class VectorField: public AbstractVectorField <DIM>
  {
  private:
    boost::multi_array<T,DIM+1>* field;
  public:
    VectorField(std::string const _name, double const _freq);
    virtual ~VectorField() = default;
  };
}
#endif
