#include "Fields.h"

AbstractField::AbstractField()
{
  LOG(INFO) << "init AbstractField";
}

AbstractVectorField::AbstractVectorField()
{
  LOG(INFO) << "init AbstractVectorField()";
}

AbstractScalarField::AbstractScalarField()
{
  LOG(INFO) << "init AbstractScalarField()";
}

VectorFieldNode::VectorFieldNode()
{
  LOG(INFO) << "init VectorFieldNode()";
}

ScalarFieldNode::ScalarFieldNode()
{
  LOG(INFO) << "init ScalarFieldNode()";
}

VectorField::VectorField()
{
  LOG(INFO) << "init vectorfield";
}

ScalarField::ScalarField()
{
  LOG(INFO) << "init scalarfield";
}
