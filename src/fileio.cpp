#include "fileio.h"
mad2* const read_double_h5_file_2d(string const filename,string const datasetname)
{
  const H5std_string FILE_NAME(filename);
  const H5std_string DATASET_NAME(datasetname);
  mad2* data;
  try{
    LOG(INFO) << "reading file: " << filename << endl;
    LOG(INFO) << "        dataset: /" << datasetname << endl;
    Exception::dontPrint();
    H5File file( FILE_NAME, H5F_ACC_RDONLY );
    DataSet dataset = file.openDataSet( DATASET_NAME );
    DataSpace filespace = dataset.getSpace();
    int rank = filespace.getSimpleExtentNdims();//number of dimension

    hsize_t dims[2];    // dataset dimensions
    rank = filespace.getSimpleExtentDims( dims );
    if (rank != 2)
      throw length_error("Incorrect dataset dimension!");
    DataSpace mspace1(rank, dims);
    double* const data_out = new double[dims[0]*dims[1]];
    dataset.read( data_out, PredType::NATIVE_DOUBLE, mspace1, filespace );
    data = new mad2(boost::extents[dims[0]][dims[1]]);
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
  catch (length_error error)
    {
      LOG(ERROR) << error.what();
      exit(EXIT_FAILURE);
    }
  return data;
}

mad3* const read_double_h5_file_3d(string const filename,string const datasetname)
{
  const H5std_string FILE_NAME(filename);
  const H5std_string DATASET_NAME(datasetname);
  mad3* data;
  try{
    LOG(INFO) << "reading file: " << filename << endl;
    LOG(INFO) << "        dataset: /" << datasetname << endl;
    Exception::dontPrint();
    H5File file( FILE_NAME, H5F_ACC_RDONLY );
    DataSet dataset = file.openDataSet( DATASET_NAME );
    DataSpace filespace = dataset.getSpace();
    int rank = filespace.getSimpleExtentNdims();//number of dimension

    hsize_t dims[3];    // dataset dimensions
    rank = filespace.getSimpleExtentDims( dims );
    if (rank != 3)
      throw length_error("Incorrect dataset dimension!");
    DataSpace mspace1(rank, dims);
    double* const data_out = new double[dims[0]*dims[1]*dims[2]];
    dataset.read( data_out, PredType::NATIVE_DOUBLE, mspace1, filespace );
    data = new mad3(boost::extents[dims[0]][dims[1]][dims[2]]);
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
  catch (length_error error)
    {
      LOG(ERROR) << error.what();
      exit(EXIT_FAILURE);
    }
  return data;
}

mad4* const read_double_h5_file_4d(string const filename,string const datasetname)
{
  const H5std_string FILE_NAME(filename);
  const H5std_string DATASET_NAME(datasetname);
  mad4* data;
  try{
    LOG(INFO) << "reading file: " << filename << endl;
    LOG(INFO) << "        dataset: /" << datasetname << endl;
    Exception::dontPrint();
    H5File file( FILE_NAME, H5F_ACC_RDONLY );
    DataSet dataset = file.openDataSet( DATASET_NAME );
    DataSpace filespace = dataset.getSpace();
    int rank = filespace.getSimpleExtentNdims();//number of dimension

    hsize_t dims[4];    // dataset dimensions
    rank = filespace.getSimpleExtentDims( dims );
    if (rank != 4)
      throw length_error("Incorrect dataset dimension!");
    DataSpace mspace1(rank, dims);
    double* const data_out = new double[dims[0]*dims[1]*dims[2]*dims[3]];
    dataset.read( data_out, PredType::NATIVE_DOUBLE, mspace1, filespace );
    data = new mad4(boost::extents[dims[0]][dims[1]][dims[2]][dims[3]]);
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
  catch (length_error error)
    {
      LOG(ERROR) << error.what();
      exit(EXIT_FAILURE);
    }
  return data;
}

mac2* const read_complex_h5_file_2d(string const filename,string const datasetname)
{
  mac2* data;
  const dcomplex ii(0.0,1.0);
  try{
    LOG(INFO) << "reading file: " << filename << endl;
    LOG(INFO) << "        group: /" << datasetname << endl;
    auto const* const real_data = read_double_h5_file_2d(filename,datasetname+"/real");
    auto const* const imag_data = read_double_h5_file_2d(filename,datasetname+"/imag");
    auto const* const real_shape = real_data->shape();
    auto const* const imag_shape = imag_data->shape();
    auto const* const shape = real_shape;
    //check shapes are the same
    for (int i = 0; i < 2; ++i)
      {
        if (real_shape[i] != imag_shape[i])
          throw length_error("Real and imag parts have different shapes!");
      }
    data = new mac2(boost::extents[shape[0]][shape[1]]);
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

mac3* const read_complex_h5_file_3d(string const filename,string const datasetname)
{
  mac3* data;
  const dcomplex ii(0.0,1.0);
  try{
    LOG(INFO) << "reading file: " << filename << endl;
    LOG(INFO) << "        group: /" << datasetname << endl;
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
    data = new mac3(boost::extents[shape[0]][shape[1]][shape[2]]);
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

mac4* const read_complex_h5_file_4d(string const filename,string const datasetname)
{
  mac4* data;
  const dcomplex ii(0.0,1.0);
  try{
    LOG(INFO) << "reading file: " << filename << endl;
    LOG(INFO) << "        group: /" << datasetname << endl;
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
    data = new mac4(boost::extents[shape[0]][shape[1]][shape[2]][shape[3]]);
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

template <unsigned long DIM>
void write_h5_file(boost::multi_array<double,DIM> const* const data, string const filename, string const datasetname)
{
  const H5std_string FILE_NAME(filename);
  const H5std_string DATASET_NAME(datasetname);
  try{
    LOG(INFO) << "writing file: " << filename << endl;
    LOG(INFO) << "        dataset: /" << datasetname << endl;
    Exception::dontPrint();
    int const rank = data->num_dimensions();
    auto const* const shape = data->shape();
    H5File* file = new H5File( FILE_NAME, H5F_ACC_TRUNC );
    /*
    * Create property list for a dataset and set up fill values.
    */
    double fillvalue = 0.0;   /* Fill value for the dataset */
    DSetCreatPropList plist;
    plist.setFillValue(PredType::NATIVE_DOUBLE, &fillvalue);
    /*
     * Create dataspace for the dataset in the file.
     */
    hsize_t* const fdim = new hsize_t[rank];
    for (int i = 0; i < rank; ++i)
      fdim[i] = (hsize_t) shape[i];
    DataSpace fspace( rank, fdim );
    /*
     * Create dataset and write it into the file.
     */
    DataSet* dataset = new DataSet(file->createDataSet(
        DATASET_NAME, PredType::NATIVE_DOUBLE, fspace, plist));

    /*
     * Create dataspace for the first dataset.
     */
    DataSpace mspace1( rank, fdim );
    dataset->write( data->data(), PredType::NATIVE_DOUBLE, mspace1, fspace );
    delete dataset;
    delete file;
  }
  catch( FileIException error )
    {
      LOG(ERROR) << "cant write file: "<< filename << ", with dataset: " << datasetname << endl;
      error.printError();
      exit(EXIT_FAILURE);
    }
  catch( DataSetIException error )
    {
      LOG(ERROR) << "cant write file: "<< filename << ", with dataset: " << datasetname << endl;
      error.printError();
      exit(EXIT_FAILURE);
    }
  catch( DataSpaceIException error )
    {
      LOG(ERROR) << "cant write file: "<< filename << ", with dataset: " << datasetname << endl;
      error.printError();
      exit(EXIT_FAILURE);
    }
}

template <unsigned long DIM>
double const* const real_parts(boost::multi_array<dcomplex,DIM> const* const data)
{
  auto const arr_size = data->num_elements();
  auto const* const data_ptr = data->data();
  double* const r_data = new double[arr_size];
  for (unsigned int i = 0; i < arr_size; ++i)
    {
      r_data[i] = real(data_ptr[i]);
    }
  return r_data;
}

template <unsigned long DIM>
double const* const imag_parts(boost::multi_array<dcomplex,DIM> const* const data)
{
  auto const arr_size = data->num_elements();
  auto const* const data_ptr = data->data();
  double* const i_data = new double[arr_size];
  for (unsigned int i = 0; i < arr_size; ++i)
    {
      i_data[i] = imag(data_ptr[i]);
    }
  return i_data;
}

template <unsigned long DIM>
void write_h5_file(boost::multi_array<dcomplex,DIM> const* const data, string const filename, string const datasetname)
{
  const H5std_string FILE_NAME(filename);
  const H5std_string DATASET_REAL("/"+datasetname+"/real");
  const H5std_string DATASET_IMAG("/"+datasetname+"/imag");
  try{
    LOG(INFO) << "writing file: " << filename << endl;
    LOG(INFO) << "        dataset: /" << datasetname+"/real" << endl;
    LOG(INFO) << "        dataset: /" << datasetname+"/imag" << endl;
    Exception::dontPrint();
    int const rank = data->num_dimensions();
    auto const* const shape = data->shape();
    H5File* file = new H5File( FILE_NAME, H5F_ACC_TRUNC );
    Group* group = new Group( file->createGroup( "/"+datasetname ));

    /*
    * Create property list for a dataset and set up fill values.
    */
    double fillvalue = 0.0;   /* Fill value for the dataset */
    DSetCreatPropList plist;
    plist.setFillValue(PredType::NATIVE_DOUBLE, &fillvalue);
    hsize_t* const fdim = new hsize_t[rank];
    for (int i = 0; i < rank; ++i)
      fdim[i] = (hsize_t) shape[i];
    /*
     *save the real part
     */
    DataSpace fspace_r( rank, fdim );
    DataSet* dataset_r = new DataSet(file->createDataSet(
        DATASET_REAL, PredType::NATIVE_DOUBLE, fspace_r, plist));
    DataSpace* mspace_r = new DataSpace( rank, fdim );
    double const* const r_data = real_parts(data);
    dataset_r->write( r_data, PredType::NATIVE_DOUBLE, *mspace_r, fspace_r );
    delete mspace_r;
    delete dataset_r;
    delete r_data;
    /*
     *save the imag part
     */
    DataSpace fspace_i( rank, fdim );
    DataSet* dataset_i = new DataSet(file->createDataSet(
        DATASET_IMAG, PredType::NATIVE_DOUBLE, fspace_i, plist));
    DataSpace* mspace_i = new DataSpace( rank, fdim );
    double const* const i_data = imag_parts(data);
    dataset_i->write( i_data, PredType::NATIVE_DOUBLE, *mspace_i, fspace_i );
    delete mspace_i;
    delete dataset_i;
    delete i_data;

    delete group;
    delete file;
  }
  catch( FileIException error )
    {
      LOG(ERROR) << "can't write file: "<< filename << ", with dataset: " << datasetname << endl;
      error.printError();
      exit(EXIT_FAILURE);
    }
  catch( DataSetIException error )
    {
      LOG(ERROR) << "can't write file: "<< filename << ", with dataset: " << datasetname << endl;
      error.printError();
      exit(EXIT_FAILURE);
    }
  catch( DataSpaceIException error )
    {
      LOG(ERROR) << "can't write file: "<< filename << ", with dataset: " << datasetname << endl;
      error.printError();
      exit(EXIT_FAILURE);
    }
}

template <typename T>
void print_multi_array(boost::multi_array<T,2> const* const data, bool const print_data)
{
  int const rank = data->num_dimensions();
  auto const* const shape = data->shape();
  LOG(INFO) << "========================"<< endl;
  LOG(INFO) << "rank: "<< rank << endl;
  LOG(INFO) << "dims: "<<shape[0] <<" x " << shape[1] << endl;
  if (print_data)
    {
      stringstream ss;
      LOG(INFO) << "data:" << endl;
      for (int i = 0;i<(int)shape[0];i++)
        {
          for (int j = 0; j < (int)shape[1]; ++j)
            ss << (*data)[i][j] <<" ";
          LOG(INFO) << ss.str() << endl;
          ss.str(string());
        }
    }
  LOG(INFO) << "========================"<< endl;
}

template <typename T>
void print_multi_array(boost::multi_array<T,3> const* const data, bool const print_data)
{
  int const rank = data->num_dimensions();
  auto const* const shape = data->shape();
  LOG(INFO) << "========================"<< endl;
  LOG(INFO) << "rank: "<< rank << endl;
  LOG(INFO) << "dims: "<<shape[0]<<" x "<< shape[1]<<" x "<<shape[2]<< endl;
  if (print_data)
    {
      stringstream ss;
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
  LOG(INFO) << "========================"<< endl;
}

template <typename T>
void print_multi_array(boost::multi_array<T,4> const* const data, bool const print_data)
{
  int const rank = data->num_dimensions();
  auto const* const shape = data->shape();
  LOG(INFO) << "========================"<< endl;
  LOG(INFO) << "rank: "<< rank << endl;
  LOG(INFO) << "dims: "<<shape[0]<<" x "<< shape[1]<<" x "<<shape[2]<<" x "<<shape[3]<< endl;
  if (print_data)
    {
      stringstream ss;
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
  LOG(INFO) << "========================"<< endl;
}
//explicitly instantiating
template double const* const real_parts(mac2 const* const data);
template double const* const real_parts(mac3 const* const data);
template double const* const real_parts(mac4 const* const data);
template double const* const imag_parts(mac2 const* const data);
template double const* const imag_parts(mac3 const* const data);
template double const* const imag_parts(mac4 const* const data);
template void write_h5_file(mad2 const* const data, string const filename, string const datasetname);
template void write_h5_file(mad3 const* const data, string const filename, string const datasetname);
template void write_h5_file(mad4 const* const data, string const filename, string const datasetname);
template void write_h5_file(mac2 const* const data, string const filename, string const datasetname);
template void write_h5_file(mac3 const* const data, string const filename, string const datasetname);
template void write_h5_file(mac4 const* const data, string const filename, string const datasetname);
template void print_multi_array(mad2 const* const data, bool const print_data);
template void print_multi_array(mad3 const* const data, bool const print_data);
template void print_multi_array(mad4 const* const data, bool const print_data);
template void print_multi_array(mac2 const* const data, bool const print_data);
template void print_multi_array(mac3 const* const data, bool const print_data);
template void print_multi_array(mac4 const* const data, bool const print_data);
