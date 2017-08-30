#include "Fields.h"
namespace fields
{
  template <unsigned long DIM>
  AbstractField<DIM>::AbstractField(std::string const _name, double const _freq): name(_name), freq(_freq)
  {
    if (DIM == 2)
      LOG(INFO) << "init 2D AbstractField";
    else if (DIM ==3)
      LOG(INFO) << "init 3D AbstractField";
  }

  template <unsigned long DIM>
  FieldNode<DIM>::FieldNode(std::string const _name, double const _freq): AbstractField<DIM>(_name, _freq)
  {
    LOG(INFO) << "init FieldNode ";
  }

  template <unsigned long DIM>
  AbstractVectorField<DIM>::AbstractVectorField(std::string const _name, double const _freq): AbstractField<DIM>(_name, _freq)
  {
    LOG(INFO) << "init AbstractVectorField";
  }

  template <unsigned long DIM>
  AbstractScalarField<DIM>::AbstractScalarField(std::string const _name, double const _freq): AbstractField<DIM>(_name, _freq)
  {
    LOG(INFO) << "init AbstractScalarField";
  }

  template <unsigned long DIM>
  VectorFieldNode<DIM>::VectorFieldNode(std::string const _name, double const _freq):\
    AbstractField<DIM>(_name, _freq),AbstractVectorField<DIM>(_name, _freq), FieldNode<DIM>(_name, _freq)
  {
    LOG(INFO) << "init VectorFieldNode";
  }

  template <unsigned long DIM>
  ScalarFieldNode<DIM>::ScalarFieldNode(std::string const _name, double const _freq):\
    AbstractField<DIM>(_name, _freq),AbstractScalarField<DIM>(_name, _freq), FieldNode<DIM>(_name, _freq)
  {
    LOG(INFO) << "init ScalarFieldNode";
  }

  template <unsigned long DIM,typename T>
  ScalarField<DIM,T>::ScalarField(std::string const _name, double const _freq): AbstractField<DIM>(_name, _freq), AbstractScalarField<DIM>(_name, _freq)
  {
    if (DIM==2)
      LOG(INFO) << "init 2D Scalarfield";
    else if (DIM==3)
      LOG(INFO) << "init 3D Scalarfield";
    field = nullptr;
  }

  template <unsigned long DIM,typename T>
  VectorField<DIM,T>::VectorField(std::string const _name, double const _freq): AbstractField<DIM>(_name, _freq), AbstractVectorField<DIM>(_name, _freq)
  {
    if (DIM==2)
      LOG(INFO) << "init 2D Vectorfield";
    else if (DIM==3)
      LOG(INFO) << "init 3D Vectorfield";
    field = nullptr;
  }

  //explicitly instantiating
  template class AbstractField<1>;
  template class AbstractField<2>;
  template class AbstractField<3>;
  template class FieldNode<1>;
  template class FieldNode<2>;
  template class FieldNode<3>;
  template class AbstractScalarField<1>;
  template class AbstractScalarField<2>;
  template class AbstractScalarField<3>;
  template class AbstractVectorField<1>;
  template class AbstractVectorField<2>;
  template class AbstractVectorField<3>;
  template class ScalarFieldNode<1>;
  template class ScalarFieldNode<2>;
  template class ScalarFieldNode<3>;
  template class VectorFieldNode<1>;
  template class VectorFieldNode<2>;
  template class VectorFieldNode<3>;
  template class ScalarField<1,double>;
  template class ScalarField<2,double>;
  template class ScalarField<3,double>;
  template class ScalarField<1,dcomplex>;
  template class ScalarField<2,dcomplex>;
  template class ScalarField<3,dcomplex>;
  template class VectorField<1,double>;
  template class VectorField<2,double>;
  template class VectorField<3,double>;
  template class VectorField<1,dcomplex>;
  template class VectorField<2,dcomplex>;
  template class VectorField<3,dcomplex>;
}
