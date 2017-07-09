#include "fileio.h"

boost::multi_array<double,2>* const read_double_h5_file_2d(string const filename,string const datasetname)
{
  const H5std_string FILE_NAME(filename);
  const H5std_string DATASET_NAME(datasetname);
  boost::multi_array<double,2>* data;
  try{
    LOG(INFO) << filename;
    LOG(INFO) << datasetname;
    Exception::dontPrint();
    H5File file( FILE_NAME, H5F_ACC_RDONLY );
    DataSet dataset = file.openDataSet( DATASET_NAME );
    DataSpace filespace = dataset.getSpace();
    int rank = filespace.getSimpleExtentNdims();//number of dimension

    hsize_t dims[2];    // dataset dimensions
    rank = filespace.getSimpleExtentDims( dims );
    assert(rank == 2);
    LOG(INFO) << "dataset rank = " << rank << ", dimensions "
              << (unsigned long)(dims[0]) << " x "
              << (unsigned long)(dims[1]) << endl;
    DataSpace mspace1(rank, dims);
    double* const data_out = new double[dims[0]*dims[1]];
    dataset.read( data_out, PredType::NATIVE_DOUBLE, mspace1, filespace );
    data = new boost::multi_array<double,2>(boost::extents[dims[0]][dims[1]]);
    // for (int i = 0; i < (int)dims[0]; i++)
    //     for (int j = 0; j < (int)dims[1]; j++)
    //         (*data)[i][j] = data_out[i*dims[1]+j];
    data->assign(data_out,data_out+dims[0]*dims[1]);
    delete[] data_out;
  }// end of try block
  catch( FileIException error )
    {
      LOG(ERROR) << "Can't read file: " << filename <<", with dataset: " << datasetname;
      exit(EXIT_FAILURE);
    }
  // catch failure caused by the DataSet operations
  catch( DataSetIException error )
    {
      LOG(ERROR) << "Can't read file: " << filename <<", with dataset: " << datasetname;
      exit(EXIT_FAILURE);
    }
  // catch failure caused by the DataSpace operations
  catch( DataSpaceIException error )
    {
      error.printError();
      exit(EXIT_FAILURE);
    }
  return data;
}

boost::multi_array<double,3>* const read_double_h5_file_3d(string const filename,string const datasetname)
{
  const H5std_string FILE_NAME(filename);
  const H5std_string DATASET_NAME(datasetname);
  boost::multi_array<double,3>* data;
  try{
    LOG(INFO) << filename;
    LOG(INFO) << datasetname;
    Exception::dontPrint();
    H5File file( FILE_NAME, H5F_ACC_RDONLY );
    DataSet dataset = file.openDataSet( DATASET_NAME );
    DataSpace filespace = dataset.getSpace();
    int rank = filespace.getSimpleExtentNdims();//number of dimension

    hsize_t dims[3];    // dataset dimensions
    rank = filespace.getSimpleExtentDims( dims );
    assert(rank == 3);
    LOG(INFO) << "dataset rank = " << rank << ", dimensions "
              << (unsigned long)(dims[0]) << " x "
              << (unsigned long)(dims[1]) << " x "
              << (unsigned long)(dims[2]) << endl;
    DataSpace mspace1(rank, dims);
    double* const data_out = new double[dims[0]*dims[1]*dims[2]];
    dataset.read( data_out, PredType::NATIVE_DOUBLE, mspace1, filespace );
    data = new boost::multi_array<double,3>(boost::extents[dims[0]][dims[1]][dims[2]]);
    // for (int i = 0; i < (int)dims[0]; i++)
    //   for (int j = 0; j < (int)dims[1]; j++)
    //     for (int k = 0; k < (int)dims[2]; k++)
    //       (*data)[i][j][k] = data_out[i*dims[1]*dims[2]+j*dims[2]+k];
    data->assign(data_out,data_out+dims[0]*dims[1]*dims[2]);
    delete[] data_out;
  }// end of try block
  catch( FileIException error )
    {
      LOG(ERROR) << "Can't read file: " << filename <<", with dataset: " << datasetname;
      exit(EXIT_FAILURE);
    }
  // catch failure caused by the DataSet operations
  catch( DataSetIException error )
    {
      LOG(ERROR) << "Can't read file: " << filename <<", with dataset: " << datasetname;
      exit(EXIT_FAILURE);
    }
  // catch failure caused by the DataSpace operations
  catch( DataSpaceIException error )
    {
      error.printError();
      exit(EXIT_FAILURE);
    }
  return data;
}

boost::multi_array<double,4>* const read_double_h5_file_4d(string const filename,string const datasetname)
{
  const H5std_string FILE_NAME(filename);
  const H5std_string DATASET_NAME(datasetname);
  boost::multi_array<double,4>* data;
  try{
    LOG(INFO) << filename;
    LOG(INFO) << datasetname;
    Exception::dontPrint();
    H5File file( FILE_NAME, H5F_ACC_RDONLY );
    DataSet dataset = file.openDataSet( DATASET_NAME );
    DataSpace filespace = dataset.getSpace();
    int rank = filespace.getSimpleExtentNdims();//number of dimension

    hsize_t dims[4];    // dataset dimensions
    rank = filespace.getSimpleExtentDims( dims );
    assert(rank == 4);
    LOG(INFO) << "dataset rank = " << rank << ", dimensions "
              << (unsigned long)(dims[0]) << " x "
              << (unsigned long)(dims[1]) << " x "
              << (unsigned long)(dims[2]) << " x "
              << (unsigned long)(dims[3]) << endl;
    DataSpace mspace1(rank, dims);
    double* const data_out = new double[dims[0]*dims[1]*dims[2]*dims[3]];
    dataset.read( data_out, PredType::NATIVE_DOUBLE, mspace1, filespace );
    data = new boost::multi_array<double,4>(boost::extents[dims[0]][dims[1]][dims[2]][dims[3]]);
    // for (int i = 0; i < (int)dims[0]; i++)
    //   for (int j = 0; j < (int)dims[1]; j++)
    //     for (int k = 0; k < (int)dims[2]; k++)
    //       for (int l = 0; l < (int)dims[3]; l++)
    //         (*data)[i][j][k][l] = data_out[i*dims[1]*dims[2]*dims[3]+j*dims[2]*dims[3]+k*dims[3]+l];
    data->assign(data_out,data_out+dims[0]*dims[1]*dims[2]*dims[3]);
    delete[] data_out;
  }// end of try block
  catch( FileIException error )
    {
      LOG(ERROR) << "Can't read file: " << filename <<", with dataset: " << datasetname;
      exit(EXIT_FAILURE);
    }
  // catch failure caused by the DataSet operations
  catch( DataSetIException error )
    {
      LOG(ERROR) << "Can't read file: " << filename <<", with dataset: " << datasetname;
      exit(EXIT_FAILURE);
    }
  // catch failure caused by the DataSpace operations
  catch( DataSpaceIException error )
    {
      error.printError();
      exit(EXIT_FAILURE);
    }
  return data;
}

boost::multi_array<dcomplex,2>* const read_complex_h5_file_2d(string const filename,string const datasetname)
{
  boost::multi_array<dcomplex,2>* data;
  const dcomplex ii(0.0,1.0);
  try{
    auto const* const real_data = read_double_h5_file_2d(filename,datasetname+"/real");
    auto const* const imag_data = read_double_h5_file_2d(filename,datasetname+"/imag");
    auto const* const real_shape = real_data->shape();
    auto const* const imag_shape = imag_data->shape();
    auto const* const shape = real_shape;
    //check shapes are the same
    for (int i = 0; i < 2; ++i)
      {
        if (real_shape[i] != imag_shape[i])
            throw length_error("real and imag parts have different shapes!");
      }
    data = new boost::multi_array<dcomplex,2>(boost::extents[shape[0]][shape[1]]);
    for (int i = 0; i < (int)shape[0]; i++)
      for (int j = 0; j < (int)shape[1]; j++)
          (*data)[i][j] = (*real_data)[i][j] + ii*((*imag_data)[i][j]);
    delete real_data;
    delete imag_data;
  }
  catch (length_error error)
    {
      LOG(ERROR) << error.what();
      exit(EXIT_FAILURE);
    }
  return data;
}

boost::multi_array<dcomplex,3>* const read_complex_h5_file_3d(string const filename,string const datasetname)
{
  boost::multi_array<dcomplex,3>* data;
  const dcomplex ii(0.0,1.0);
  try{
    auto const* const real_data = read_double_h5_file_3d(filename,datasetname+"/real");
    auto const* const imag_data = read_double_h5_file_3d(filename,datasetname+"/imag");
    auto const* const real_shape = real_data->shape();
    auto const* const imag_shape = imag_data->shape();
    auto const* const shape = real_shape;
    //check shapes are the same
    for (int i = 0; i < 3; ++i)
      {
        if (real_shape[i] != imag_shape[i])
            throw length_error("real and imag parts have different shapes!");
      }
    data = new boost::multi_array<dcomplex,3>(boost::extents[shape[0]][shape[1]][shape[2]]);
    for (int i = 0; i < (int)shape[0]; i++)
      for (int j = 0; j < (int)shape[1]; j++)
        for (int k = 0; k < (int)shape[2]; k++)
          (*data)[i][j][k] = (*real_data)[i][j][k] + ii*((*imag_data)[i][j][k]);
    delete real_data;
    delete imag_data;
  }
  catch (length_error error)
    {
      LOG(ERROR) << error.what();
      exit(EXIT_FAILURE);
    }
  return data;
}

boost::multi_array<dcomplex,4>* const read_complex_h5_file_4d(string const filename,string const datasetname)
{
  boost::multi_array<dcomplex,4>* data;
  const dcomplex ii(0.0,1.0);
  try{
    auto const* const real_data = read_double_h5_file_4d(filename,datasetname+"/real");
    auto const* const imag_data = read_double_h5_file_4d(filename,datasetname+"/imag");
    auto const* const real_shape = real_data->shape();
    auto const* const imag_shape = imag_data->shape();
    auto const* const shape = real_shape;
    //check shapes are the same
    for (int i = 0; i < 4; ++i)
      {
        if (real_shape[i] != imag_shape[i])
            throw length_error("real and imag parts have different shapes!");
      }
    data = new boost::multi_array<dcomplex,4>(boost::extents[shape[0]][shape[1]][shape[2]][shape[3]]);
    for (int i = 0; i < (int)shape[0]; i++)
      for (int j = 0; j < (int)shape[1]; j++)
        for (int k = 0; k < (int)shape[2]; k++)
          for (int l = 0; l < (int)shape[3]; l++)
            (*data)[i][j][k][l] = (*real_data)[i][j][k][l] + ii*((*imag_data)[i][j][k][l]);
    delete real_data;
    delete imag_data;
  }
  catch (length_error error)
    {
      LOG(ERROR) << error.what();
      exit(EXIT_FAILURE);
    }
  return data;
}

template <typename T>
void print_multi_array(boost::multi_array<T,2> const* const data)
{
  int const rank = data->num_dimensions();
  auto const* const shape = data->shape();
  stringstream ss;
  LOG(INFO) << "rank: "<< rank << endl;
  LOG(INFO) << "dims: "<<shape[0] <<"x" << shape[1] << endl;
  LOG(INFO) << "data:" << endl;
  for (int i = 0;i<(int)shape[0];i++)
    {
      for (int j = 0; j < (int)shape[1]; ++j)
        ss << (*data)[i][j] <<" ";
      LOG(INFO) << ss.str() << endl;
      ss.str(string());
    }
}

template <typename T>
void print_multi_array(boost::multi_array<T,3> const* const data)
{
  int const rank = data->num_dimensions();
  auto const* const shape = data->shape();
  stringstream ss;
  LOG(INFO) << "rank: "<< rank << endl;
  LOG(INFO) << "dims: "<<shape[0]<<"x"<< shape[1]<<"x"<<shape[2]<< endl;
  LOG(INFO) << "data:" << endl;
  for (int i = 0;i<(int)shape[0];i++)
    {
      for (int j = 0; j < (int)shape[1]; ++j)
        {
          for (int k = 0; k < (int)shape[2]; ++k)
            ss << (*data)[i][j][k] <<" ";
          LOG(INFO) << ss.str() << endl;
          ss.str(string());
        }
      LOG(INFO) << endl << endl;
    }
}

template <typename T>
void print_multi_array(boost::multi_array<T,4> const* const data)
{
  int const rank = data->num_dimensions();
  auto const* const shape = data->shape();
  stringstream ss;
  LOG(INFO) << "rank: "<< rank << endl;
  LOG(INFO) << "dims: "<<shape[0]<<"x"<< shape[1]<<"x"<<shape[2]<<"x"<<shape[3]<< endl;
  LOG(INFO) << "data:" << endl;
  for (int i = 0;i<(int)shape[0];i++)
    {
      for (int j = 0; j < (int)shape[1]; ++j)
        {
          for (int k = 0; k < (int)shape[2]; ++k)
            {
              for (int l = 0; l < (int) shape[3]; ++l)
                ss << (*data)[i][j][k][l] <<" ";
              LOG(INFO)<< ss.str() << endl;
              ss.str(string());
            }
          LOG(INFO) << endl << endl;
        }
      LOG(INFO) << endl << endl <<endl;
    }
}
//explicitly instantiating
template void print_multi_array(boost::multi_array<double,2> const* const data);
template void print_multi_array(boost::multi_array<double,3> const* const data);
template void print_multi_array(boost::multi_array<double,4> const* const data);
template void print_multi_array(boost::multi_array<dcomplex,2> const* const data);
template void print_multi_array(boost::multi_array<dcomplex,3> const* const data);
template void print_multi_array(boost::multi_array<dcomplex,4> const* const data);
