#include "fileio.h"
namespace fileio
{
  template<unsigned long DIM>
  mad<DIM>* const read_double_h5_file(std::string const filename,\
                                                            std::string const datasetname)
  {
    const H5std_string FILE_NAME(filename);
    const H5std_string DATASET_NAME(datasetname);
    mad<DIM>* data;
    try{
      LOG(INFO) << "reading file: " << filename << std::endl;
      LOG(INFO) << "        dataset: /" << datasetname << std::endl;
      Exception::dontPrint();
      H5File file( FILE_NAME, H5F_ACC_RDONLY );
      DataSet dataset = file.openDataSet( DATASET_NAME );
      DataSpace filespace = dataset.getSpace();
      int rank = filespace.getSimpleExtentNdims();//number of dimension

      hsize_t dims[DIM];    // dataset dimensions
      rank = filespace.getSimpleExtentDims( dims );
      if (rank != DIM)
        throw std::length_error("Incorrect dataset dimension!");

      hsize_t element_num = 1;
      for (hsize_t x: dims)
        element_num *= x;
      //read data from h5 file
      DataSpace mspace1(rank, dims);
      double* const data_out = new double[element_num];
      dataset.read( data_out, PredType::NATIVE_DOUBLE, mspace1, filespace );
      //construct multi_array and copy data.
      boost::array<hsize_t, DIM> shape;
      std::copy(std::begin(dims), std::end(dims), std::begin(shape));
      data = new mad<DIM>(shape);
      data->assign(data_out,data_out+element_num);
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
    catch (std::length_error error)
      {
        LOG(ERROR) << error.what();
        exit(EXIT_FAILURE);
      }
    return data;
  }

  template<unsigned long DIM>
  mac<DIM>* const read_complex_h5_file(std::string const filename,\
                                                               std::string const datasetname)
  {
    mac<DIM>* data;
    const dcomplex ii(0.0,1.0);
    try{
      LOG(INFO) << "reading file: " << filename << std::endl;
      LOG(INFO) << "        group: /" << datasetname << std::endl;
      auto const* const real_data = read_double_h5_file<DIM>(filename,datasetname+"/real");
      auto const* const imag_data = read_double_h5_file<DIM>(filename,datasetname+"/imag");
      auto const* const real_shape = real_data->shape();
      auto const* const imag_shape = imag_data->shape();
      //auto const* const shape = real_shape;
      //check shapes are the same
      boost::array<hsize_t, DIM> shape;
      for (unsigned int i = 0; i < DIM; ++i)
        {
          shape[i] = real_shape[i];
          if (real_shape[i] != imag_shape[i])
            throw std::length_error("Real and imag parts have different shapes!");
        }
      data = new mac<DIM>(shape);
      for (unsigned int i = 0; i < data->num_elements(); i++ )
        data->data()[i] = real_data->data()[i]+ii*imag_data->data()[i];
      delete real_data;
      delete imag_data;
    }
    catch (std::length_error error)
      {
        LOG(ERROR) << error.what();
        exit(EXIT_FAILURE);
      }
    return data;
  }

  template <unsigned long DIM>
  void write_h5_file(mad<DIM> const* const data, std::string const filename,\
                     std::string const datasetname, bool const append)
  {
    const H5std_string FILE_NAME(filename);
    const H5std_string DATASET_NAME(datasetname);
    try{
      LOG(INFO) << "writing file: " << filename << std::endl;
      LOG(INFO) << "        dataset: /" << datasetname << std::endl;
      Exception::dontPrint();
      int const rank = data->num_dimensions();
      auto const* const shape = data->shape();
      H5File* file = nullptr;
      if (append)
        file = new H5File( FILE_NAME, H5F_ACC_RDWR );
      else
        file = new H5File( FILE_NAME, H5F_ACC_TRUNC );
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
      DataSet* dataset = new DataSet(file->createDataSet(DATASET_NAME,\
                                                         PredType::NATIVE_DOUBLE, fspace, plist));

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
        LOG(ERROR) << "cant write file: "<< filename << ", with dataset: " << datasetname << std::endl;
        error.printError();
        exit(EXIT_FAILURE);
      }
    catch( DataSetIException error )
      {
        LOG(ERROR) << "cant write file: "<< filename << ", with dataset: " << datasetname << std::endl;
        error.printError();
        exit(EXIT_FAILURE);
      }
    catch( DataSpaceIException error )
      {
        LOG(ERROR) << "cant write file: "<< filename << ", with dataset: " << datasetname << std::endl;
        error.printError();
        exit(EXIT_FAILURE);
      }
  }

  template <unsigned long DIM>
  double const* const real_parts(mac<DIM> const* const data)
  {
    auto const arr_size = data->num_elements();
    auto const* const data_ptr = data->data();
    double* const r_data = new double[arr_size];
    for (unsigned int i = 0; i < arr_size; ++i)
      r_data[i] = std::real(data_ptr[i]);
    return r_data;
  }

  template <unsigned long DIM>
  double const* const imag_parts(mac<DIM> const* const data)
  {
    auto const arr_size = data->num_elements();
    auto const* const data_ptr = data->data();
    double* const i_data = new double[arr_size];
    for (unsigned int i = 0; i < arr_size; ++i)
      i_data[i] = std::imag(data_ptr[i]);
    return i_data;
  }

  template <unsigned long DIM>
  void write_h5_file(mac<DIM> const* const data, std::string const filename,\
                     std::string const datasetname, bool const append)
  {
    const H5std_string FILE_NAME(filename);
    const H5std_string DATASET_REAL("/"+datasetname+"/real");
    const H5std_string DATASET_IMAG("/"+datasetname+"/imag");
    try{
      LOG(INFO) << "writing file: " << filename << std::endl;
      LOG(INFO) << "        dataset: /" << datasetname+"/real" << std::endl;
      LOG(INFO) << "        dataset: /" << datasetname+"/imag" << std::endl;
      Exception::dontPrint();
      int const rank = data->num_dimensions();
      auto const* const shape = data->shape();
      H5File* file = nullptr;
      if (append)
        file = new H5File( FILE_NAME, H5F_ACC_RDWR );
      else
        file = new H5File( FILE_NAME, H5F_ACC_TRUNC );
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
        LOG(ERROR) << "can't write file: "<< filename << ", with dataset: " << datasetname << std::endl;
        error.printError();
        exit(EXIT_FAILURE);
      }
    catch( DataSetIException error )
      {
        LOG(ERROR) << "can't write file: "<< filename << ", with dataset: " << datasetname << std::endl;
        error.printError();
        exit(EXIT_FAILURE);
      }
    catch( DataSpaceIException error )
      {
        LOG(ERROR) << "can't write file: "<< filename << ", with dataset: " << datasetname << std::endl;
        error.printError();
        exit(EXIT_FAILURE);
      }
  }

  template <typename T>
  void print_multi_array(boost::multi_array<T,1> const* const data, bool const print_data)
  {
    int const rank = data->num_dimensions();
    auto const* const shape = data->shape();
    LOG(INFO) << "========================"<< std::endl;
    LOG(INFO) << "rank: "<< rank << std::endl;
    LOG(INFO) << "dims: "<<shape[0] << std::endl;
    if (print_data)
      {
        std::stringstream ss;
        LOG(INFO) << "data:" << std::endl;
        for (int i = 0;i<(int)shape[0];i++)
          ss << (*data)[i] <<" ";
        LOG(INFO) << ss.str() << std::endl;
      }
    LOG(INFO) << "========================"<< std::endl;
  }


  template <typename T>
  void print_multi_array(boost::multi_array<T,2> const* const data, bool const print_data)
  {
    int const rank = data->num_dimensions();
    auto const* const shape = data->shape();
    LOG(INFO) << "========================"<< std::endl;
    LOG(INFO) << "rank: "<< rank << std::endl;
    LOG(INFO) << "dims: "<<shape[0] <<" x " << shape[1] << std::endl;
    if (print_data)
      {
        std::stringstream ss;
        LOG(INFO) << "data:" << std::endl;
        for (int i = 0;i<(int)shape[0];i++)
          {
            for (int j = 0; j < (int)shape[1]; ++j)
              ss << (*data)[i][j] <<" ";
            LOG(INFO) << ss.str() << std::endl;
            ss.str(std::string());
          }
      }
    LOG(INFO) << "========================"<< std::endl;
  }

  template <typename T>
  void print_multi_array(boost::multi_array<T,3> const* const data, bool const print_data)
  {
    int const rank = data->num_dimensions();
    auto const* const shape = data->shape();
    LOG(INFO) << "========================"<< std::endl;
    LOG(INFO) << "rank: "<< rank << std::endl;
    LOG(INFO) << "dims: "<<shape[0]<<" x "<< shape[1]<<" x "<<shape[2]<< std::endl;
    if (print_data)
      {
        std::stringstream ss;
        LOG(INFO) << "data:" << std::endl;
        for (int i = 0;i<(int)shape[0];i++)
          {
            for (int j = 0; j < (int)shape[1]; ++j)
              {
                for (int k = 0; k < (int)shape[2]; ++k)
                  ss << (*data)[i][j][k] <<" ";
                LOG(INFO) << ss.str() << std::endl;
                ss.str(std::string());
              }
            LOG(INFO) << std::endl << std::endl;
          }
      }
    LOG(INFO) << "========================"<< std::endl;
  }

  template <typename T>
  void print_multi_array(boost::multi_array<T,4> const* const data, bool const print_data)
  {
    int const rank = data->num_dimensions();
    auto const* const shape = data->shape();
    LOG(INFO) << "========================"<< std::endl;
    LOG(INFO) << "rank: "<< rank << std::endl;
    LOG(INFO) << "dims: "<<shape[0]<<" x "<< shape[1]<<" x "<<shape[2]<<" x "<<shape[3]<< std::endl;
    if (print_data)
      {
        std::stringstream ss;
        LOG(INFO) << "data:" << std::endl;
        for (int i = 0;i<(int)shape[0];i++)
          {
            for (int j = 0; j < (int)shape[1]; ++j)
              {
                for (int k = 0; k < (int)shape[2]; ++k)
                  {
                    for (int l = 0; l < (int) shape[3]; ++l)
                      ss << (*data)[i][j][k][l] <<" ";
                    LOG(INFO)<< ss.str() << std::endl;
                    ss.str(std::string());
                  }
                LOG(INFO) << std::endl << std::endl;
              }
            LOG(INFO) << std::endl << std::endl <<std::endl;
          }
      }
    LOG(INFO) << "========================"<< std::endl;
  }
  //explicitly instantiating
  template mad<1>* const read_double_h5_file(std::string const filename, \
                                           std::string const datasetname);
  template mad<2>* const read_double_h5_file(std::string const filename, \
                                           std::string const datasetname);
  template mad<3>* const read_double_h5_file(std::string const filename, \
                                           std::string const datasetname);
  template mad<4>* const read_double_h5_file(std::string const filename, \
                                           std::string const datasetname);
  template mad<5>* const read_double_h5_file(std::string const filename, \
                                           std::string const datasetname);
  template mac<1>* const read_complex_h5_file(std::string const filename, \
                                            std::string const datasetname);
  template mac<2>* const read_complex_h5_file(std::string const filename, \
                                            std::string const datasetname);
  template mac<3>* const read_complex_h5_file(std::string const filename, \
                                            std::string const datasetname);
  template mac<4>* const read_complex_h5_file(std::string const filename, \
                                            std::string const datasetname);
  template mac<5>* const read_complex_h5_file(std::string const filename, \
                                            std::string const datasetname);

  template double const* const real_parts(mac<1> const* const data);
  template double const* const real_parts(mac<2> const* const data);
  template double const* const real_parts(mac<3> const* const data);
  template double const* const real_parts(mac<4> const* const data);
  template double const* const real_parts(mac<5> const* const data);
  template double const* const imag_parts(mac<1> const* const data);
  template double const* const imag_parts(mac<2> const* const data);
  template double const* const imag_parts(mac<3> const* const data);
  template double const* const imag_parts(mac<4> const* const data);
  template double const* const imag_parts(mac<5> const* const data);
  template void write_h5_file(mad<1> const* const data, std::string const filename, \
                              std::string const datasetname, bool const append);
  template void write_h5_file(mad<2> const* const data, std::string const filename, \
                              std::string const datasetname, bool const append);
  template void write_h5_file(mad<3> const* const data, std::string const filename, \
                              std::string const datasetname, bool const append);
  template void write_h5_file(mad<4> const* const data, std::string const filename, \
                              std::string const datasetname, bool const append);
  template void write_h5_file(mad<5> const* const data, std::string const filename, \
                              std::string const datasetname, bool const append);
  template void write_h5_file(mac<1> const* const data, std::string const filename, \
                              std::string const datasetname, bool const append);
  template void write_h5_file(mac<2> const* const data, std::string const filename, \
                              std::string const datasetname, bool const append);
  template void write_h5_file(mac<3> const* const data, std::string const filename, \
                              std::string const datasetname, bool const append);
  template void write_h5_file(mac<4> const* const data, std::string const filename, \
                              std::string const datasetname, bool const append);
  template void write_h5_file(mac<5> const* const data, std::string const filename, \
                              std::string const datasetname, bool const append);
  template void print_multi_array(mad<1> const* const data, bool const print_data);
  template void print_multi_array(mad<2> const* const data, bool const print_data);
  template void print_multi_array(mad<3> const* const data, bool const print_data);
  template void print_multi_array(mad<4> const* const data, bool const print_data);
  template void print_multi_array(mac<1> const* const data, bool const print_data);
  template void print_multi_array(mac<2> const* const data, bool const print_data);
  template void print_multi_array(mac<3> const* const data, bool const print_data);
  template void print_multi_array(mac<4> const* const data, bool const print_data);
}
