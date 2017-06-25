#include "Fields.h"
template <typename T,int DIM>
AbstractField<T, DIM>::AbstractField()
{
  LOG(INFO) << "init AbstractField ";
}

template <typename T,int DIM>
FieldNode<T, DIM>::FieldNode()
{
  LOG(INFO) << "init FieldNode ";
}

template <typename T,int DIM>
AbstractVectorField<T, DIM>::AbstractVectorField()
{
  LOG(INFO) << "init AbstractVectorField";
}

template <typename T,int DIM>
AbstractScalarField<T, DIM>::AbstractScalarField()
{
  LOG(INFO) << "init AbstractScalarField";
}

template <typename T,int DIM>
VectorFieldNode<T, DIM>::VectorFieldNode()
{
  LOG(INFO) << "init VectorFieldNode";
}

template <typename T,int DIM>
ScalarFieldNode<T, DIM>::ScalarFieldNode()
{
  LOG(INFO) << "init ScalarFieldNode";
}

template <typename T,int DIM>
VectorField<T, DIM>::VectorField()
{
  LOG(INFO) << "init vectorfield";
}

template <typename T,int DIM>
ScalarField<T, DIM>::ScalarField()
{
  LOG(INFO) << "init scalarfield";
}

//explicitly instantiating
template class AbstractField<double,2>;
template class AbstractField<double,3>;
template class AbstractField<dcomplex,2>;
template class AbstractField<dcomplex,3>;
template class FieldNode<double,2>;
template class FieldNode<double,3>;
template class FieldNode<dcomplex,2>;
template class FieldNode<dcomplex,3>;
template class AbstractScalarField<double,2>;
template class AbstractScalarField<double,3>;
template class AbstractScalarField<dcomplex,2>;
template class AbstractScalarField<dcomplex,3>;
template class AbstractVectorField<double,2>;
template class AbstractVectorField<double,3>;
template class AbstractVectorField<dcomplex,2>;
template class AbstractVectorField<dcomplex,3>;
template class ScalarFieldNode<double,2>;
template class ScalarFieldNode<double,3>;
template class ScalarFieldNode<dcomplex,2>;
template class ScalarFieldNode<dcomplex,3>;
template class VectorFieldNode<double,2>;
template class VectorFieldNode<double,3>;
template class VectorFieldNode<dcomplex,2>;
template class VectorFieldNode<dcomplex,3>;
template class ScalarField<double,2>;
template class ScalarField<double,3>;
template class ScalarField<dcomplex,2>;
template class ScalarField<dcomplex,3>;
template class VectorField<double,2>;
template class VectorField<double,3>;
template class VectorField<dcomplex,2>;
template class VectorField<dcomplex,3>;
