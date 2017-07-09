#include "Fields.h"
template <int DIM>
AbstractField<DIM>::AbstractField()
{
  if (DIM == 2)
    LOG(INFO) << "init 2D AbstractField";
  else if (DIM ==3)
    LOG(INFO) << "init 3D AbstractField";
}

template <int DIM>
FieldNode<DIM>::FieldNode()
{
  LOG(INFO) << "init FieldNode ";
}

template <int DIM>
AbstractVectorField<DIM>::AbstractVectorField()
{
  LOG(INFO) << "init AbstractVectorField";
}

template <int DIM>
AbstractScalarField<DIM>::AbstractScalarField()
{
  LOG(INFO) << "init AbstractScalarField";
}

template <int DIM>
VectorFieldNode<DIM>::VectorFieldNode()
{
  LOG(INFO) << "init VectorFieldNode";
}

template <int DIM>
ScalarFieldNode<DIM>::ScalarFieldNode()
{
  LOG(INFO) << "init ScalarFieldNode";
}

template <int DIM,typename T>
ScalarField<DIM,T>::ScalarField()
{
  if (DIM==2)
    LOG(INFO) << "init 2D Scalarfield";
  else if (DIM==3)
    LOG(INFO) << "init 3D Scalarfield";
  field = nullptr;
}

template <int DIM,typename T>
VectorField<DIM,T>::VectorField()
{
  if (DIM==2)
    LOG(INFO) << "init 2D Vectorfield";
  else if (DIM==3)
    LOG(INFO) << "init 3D Vectorfield";
  field = nullptr;
}

template <int DIM,typename T>
void VectorField<DIM,T>::test() const
{
}

//explicitly instantiating
template class AbstractField<2>;
template class AbstractField<3>;
template class FieldNode<2>;
template class FieldNode<3>;
template class AbstractScalarField<2>;
template class AbstractScalarField<3>;
template class AbstractVectorField<2>;
template class AbstractVectorField<3>;
template class ScalarFieldNode<2>;
template class ScalarFieldNode<3>;
template class VectorFieldNode<2>;
template class VectorFieldNode<3>;
template class ScalarField<2,double>;
template class ScalarField<3,double>;
template class ScalarField<2,dcomplex>;
template class ScalarField<3,dcomplex>;
template class VectorField<2,double>;
template class VectorField<3,double>;
template class VectorField<2,dcomplex>;
template class VectorField<3,dcomplex>;
