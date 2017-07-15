#include "Fields.h"
namespace fields
{
  template <unsigned long DIM>
  AbstractField<DIM>::AbstractField()
  {
    if (DIM == 2)
      LOG(INFO) << "init 2D AbstractField";
    else if (DIM ==3)
      LOG(INFO) << "init 3D AbstractField";
  }

  template <unsigned long DIM>
  FieldNode<DIM>::FieldNode()
  {
    LOG(INFO) << "init FieldNode ";
  }

  template <unsigned long DIM>
  AbstractVectorField<DIM>::AbstractVectorField()
  {
    LOG(INFO) << "init AbstractVectorField";
  }

  template <unsigned long DIM>
  AbstractScalarField<DIM>::AbstractScalarField()
  {
    LOG(INFO) << "init AbstractScalarField";
  }

  template <unsigned long DIM>
  VectorFieldNode<DIM>::VectorFieldNode()
  {
    LOG(INFO) << "init VectorFieldNode";
  }

  template <unsigned long DIM>
  ScalarFieldNode<DIM>::ScalarFieldNode()
  {
    LOG(INFO) << "init ScalarFieldNode";
  }

  template <unsigned long DIM,typename T>
  ScalarField<DIM,T>::ScalarField()
  {
    if (DIM==2)
      LOG(INFO) << "init 2D Scalarfield";
    else if (DIM==3)
      LOG(INFO) << "init 3D Scalarfield";
    field = nullptr;
  }

  template <unsigned long DIM,typename T>
  VectorField<DIM,T>::VectorField()
  {
    if (DIM==2)
      LOG(INFO) << "init 2D Vectorfield";
    else if (DIM==3)
      LOG(INFO) << "init 3D Vectorfield";
    field = nullptr;
  }

  template <unsigned long DIM,typename T>
  void VectorField<DIM,T>::test() const
  {
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
