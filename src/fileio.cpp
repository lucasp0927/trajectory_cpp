#include "fileio.h"
void read_h5_file(string filename,string datasetname)
{
  const H5std_string FILE_NAME(filename);
  const H5std_string DATASET_NAME(datasetname);
  try{
    LOG(INFO) << filename;
    LOG(INFO) << datasetname;
    /*
     * Turn off the auto-printing when failure occurs so that we can
     * handle the errors appropriately
     */
    Exception::dontPrint();
    /*
     * Open the file and the dataset.
     */
    H5File file( FILE_NAME, H5F_ACC_RDONLY );
    DataSet dataset = file.openDataSet( DATASET_NAME );
    /*
     * Get filespace for rank and dimension
     */
    DataSpace filespace = dataset.getSpace();
    /*
     * Get number of dimensions in the file dataspace
     */
    int rank = filespace.getSimpleExtentNdims();
    /*
     * Get and print the dimension sizes of the file dataspace
     */
    if (rank == 2)
      {
        hsize_t dims[2];    // dataset dimensions
        rank = filespace.getSimpleExtentDims( dims );
        LOG(INFO) << "dataset rank = " << rank << ", dimensions "
             << (unsigned long)(dims[0]) << " x "
             << (unsigned long)(dims[1]) << endl;
        /*
         * Define the memory space to read dataset.
         */
        DataSpace mspace1(rank, dims);
        /*
         * Read dataset back and display.
         */
        double* data_out = new double[dims[0]*dims[1]];
        // double** data_out = new double*[dims[0]];
        // for(int i = 0; i < (int)dims[0]; ++i)
        //   data_out[i] = new double[dims[1]];

        // for (int j = 0; j < (int)dims[0]; j++)
        //   {
        //     for (int i = 0; i < (int)dims[1]; i++)
        //       data_out[j][i] = i;
        //   }
        dataset.read( data_out, PredType::NATIVE_DOUBLE, mspace1, filespace );
        for (int j = 0; j < (int)dims[0]; j++)
          {
            for (int i = 0; i < (int)dims[1]; i++)
              cout << data_out[j*dims[1]+i] << " ";
            cout << endl;
          }
      }
  }// end of try block
  catch( FileIException error )
    {
      LOG(ERROR) << "Can't read file: " << filename;
      //error.printError();
      return;
    }
  // catch failure caused by the DataSet operations
  catch( DataSetIException error )
    {
      LOG(ERROR) << "Can't read dataset: "<< datasetname;
      //error.printError();
      return;
    }
  // catch failure caused by the DataSpace operations
  catch( DataSpaceIException error )
    {
      error.printError();
      return;
    }
}
