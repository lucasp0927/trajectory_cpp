#include "fileio.h"
using namespace fileio;
std::string const generate_tmp_filename(std::string const postfix = "")
{
  return  (boost::filesystem::temp_directory_path()).native() \
    +"/"+(boost::filesystem::unique_path()).native()+postfix;
}

TEST(ReadWriteTest, WriteReadRandDouble1D)
{
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = rand()%10000+1;
  LOG(INFO) << dim0 <<  std::endl;
  mad1 data(boost::extents[dim0]);
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  for (int i = 0; i < dim0; ++i)
    data[i] = (double) uni();
  write_h5_file(&data,tmp_filename,"test");
  auto const* const data_out = read_double_h5_file<1>(tmp_filename,"test");
  ASSERT_EQ(data,*data_out);
  delete data_out;
  boost::filesystem::remove(tmp_filename);
}

TEST(ReadWriteTest, WriteReadRandComplex1D)
{
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = rand()%10000+1;
  LOG(INFO) << dim0 << std::endl;
  mac1 data(boost::extents[dim0]);
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  for (int i = 0; i < dim0; ++i)
    data[i] = dcomplex((double)uni(),(double)uni());
  write_h5_file(&data,tmp_filename,"test");
  auto const* const data_out = read_complex_h5_file<1>(tmp_filename,"test");
  ASSERT_EQ(data,*data_out);
  delete data_out;
  boost::filesystem::remove(tmp_filename);
}

TEST(ReadWriteTest, WriteReadRandDouble2D)
{
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = rand()%1000+1;
  int dim1 = rand()%1000+1;
  LOG(INFO) << dim0 << " x " << dim1 << std::endl;
  mad2 data(boost::extents[dim0][dim1]);
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      data[i][j] = (double) uni();
  write_h5_file(&data,tmp_filename,"test");
  auto const* const data_out = read_double_h5_file<2>(tmp_filename,"test");
  ASSERT_EQ(data,*data_out);
  delete data_out;
  boost::filesystem::remove(tmp_filename);
}

TEST(ReadWriteTest, WriteReadRandComplex2D)
{
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = rand()%1000+1;
  int dim1 = rand()%1000+1;
  LOG(INFO) << dim0 << " x " << dim1 << std::endl;
  mac2 data(boost::extents[dim0][dim1]);
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      data[i][j] = dcomplex((double)uni(),(double)uni());
  write_h5_file(&data,tmp_filename,"test");
  auto const* const data_out = read_complex_h5_file<2>(tmp_filename,"test");
  ASSERT_EQ(data,*data_out);
  delete data_out;
  boost::filesystem::remove(tmp_filename);
}

TEST(ReadWriteTest, WriteReadRandDouble3D)
{
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = rand()%500+1;
  int dim1 = rand()%500+1;
  int dim2 = rand()%500+1;
  LOG(INFO) << dim0 << " x " << dim1 << " x " << dim2 <<std::endl;
  mad3 data(boost::extents[dim0][dim1][dim2]);
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      for (int k = 0; k < dim2; ++k)
        data[i][j][k] = (double) uni();
  write_h5_file(&data,tmp_filename,"test");
  auto const* const data_out = read_double_h5_file<3>(tmp_filename,"test");
  ASSERT_EQ(data,*data_out);
  delete data_out;
  boost::filesystem::remove(tmp_filename);
}

TEST(ReadWriteTest, WriteReadRandComplex3D)
{
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = rand()%500+1;
  int dim1 = rand()%500+1;
  int dim2 = rand()%500+1;
  LOG(INFO) << dim0 << " x " << dim1 << " x " << dim2 <<std::endl;
  mac3 data(boost::extents[dim0][dim1][dim2]);
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      for (int k = 0; k < dim2; ++k)
        data[i][j][k] = dcomplex((double)uni(),(double)uni());
  write_h5_file(&data,tmp_filename,"test");
  auto const* const data_out = read_complex_h5_file<3>(tmp_filename,"test");
  ASSERT_EQ(data,*data_out);
  delete data_out;
  boost::filesystem::remove(tmp_filename);
}

TEST(ReadWriteTest, WriteReadRandDouble4D)
{
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = rand()%100+1;
  int dim1 = rand()%100+1;
  int dim2 = rand()%100+1;
  int dim3 = rand()%100+1;
  LOG(INFO) << dim0 << " x " << dim1 << " x " << dim2 << " x " << dim3<<std::endl;
  mad4 data(boost::extents[dim0][dim1][dim2][dim3]);
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      for (int k = 0; k < dim2; ++k)
        for (int l = 0; l < dim3; ++l)
          data[i][j][k][l] = (double) uni();
  write_h5_file(&data,tmp_filename,"test");
  auto const* const data_out = read_double_h5_file<4>(tmp_filename,"test");
  ASSERT_EQ(data,*data_out);
  delete data_out;
  boost::filesystem::remove(tmp_filename);
}

TEST(ReadWriteTest, WriteReadRandComplex4D)
{
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = rand()%100+1;
  int dim1 = rand()%100+1;
  int dim2 = rand()%100+1;
  int dim3 = rand()%100+1;
  LOG(INFO) << dim0 << " x " << dim1 << " x " << dim2 << " x " << dim3<<std::endl;
  mac4 data(boost::extents[dim0][dim1][dim2][dim3]);
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      for (int k = 0; k < dim2; ++k)
        for (int l = 0; l < dim3; ++l)
          data[i][j][k][l] = dcomplex((double)uni(), (double)uni());
  write_h5_file(&data,tmp_filename,"test");
  auto const* const data_out = read_complex_h5_file<4>(tmp_filename,"test");
  ASSERT_EQ(data,*data_out);
  delete data_out;
  boost::filesystem::remove(tmp_filename);
}

TEST(ReadWriteTest, WriteReadRandDouble5D)
{
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = rand()%30+1;
  int dim1 = rand()%30+1;
  int dim2 = rand()%30+1;
  int dim3 = rand()%30+1;
  int dim4 = rand()%30+1;
  LOG(INFO) << dim0 << " x " << dim1 << " x " << dim2 <<\
    " x " << dim3 << " x " << dim4 <<std::endl;
  mad5 data(boost::extents[dim0][dim1][dim2][dim3][dim4]);
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      for (int k = 0; k < dim2; ++k)
        for (int l = 0; l < dim3; ++l)
          for (int m = 0; m < dim4; ++m)
            data[i][j][k][l][m] = (double) uni();
  write_h5_file(&data,tmp_filename,"test");
  auto const* const data_out = read_double_h5_file<5>(tmp_filename,"test");
  ASSERT_EQ(data,*data_out);
  delete data_out;
  boost::filesystem::remove(tmp_filename);
}

TEST(ReadWriteTest, WriteReadRandComplex5D)
{
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = rand()%30+1;
  int dim1 = rand()%30+1;
  int dim2 = rand()%30+1;
  int dim3 = rand()%30+1;
  int dim4 = rand()%30+1;
  LOG(INFO) << dim0 << " x " << dim1 << " x " << dim2 <<\
    " x " << dim3 << " x " << dim4 <<std::endl;
  mac5 data(boost::extents[dim0][dim1][dim2][dim3][dim4]);
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      for (int k = 0; k < dim2; ++k)
        for (int l = 0; l < dim3; ++l)
          for (int m = 0; m < dim4; ++m)
            data[i][j][k][l][m] = dcomplex((double)uni(), (double)uni());
  write_h5_file(&data,tmp_filename,"test");
  auto const* const data_out = read_complex_h5_file<5>(tmp_filename,"test");
  ASSERT_EQ(data,*data_out);
  delete data_out;
  boost::filesystem::remove(tmp_filename);
}

TEST(ReadWriteTest, AppendToFile)
{
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  //write a complex 4d array
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = rand()%50+1;
  int dim1 = rand()%50+1;
  int dim2 = rand()%50+1;
  int dim3 = rand()%50+1;
  LOG(INFO) << dim0 << " x " << dim1 << " x " << dim2 << " x " << dim3<<std::endl;
  mac4 data1(boost::extents[dim0][dim1][dim2][dim3]);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      for (int k = 0; k < dim2; ++k)
        for (int l = 0; l < dim3; ++l)
          data1[i][j][k][l] = dcomplex((double)uni(), (double)uni());
  write_h5_file(&data1,tmp_filename,"test1");
  //write a double 3d array
  dim0 = rand()%500+1;
  dim1 = rand()%500+1;
  dim2 = rand()%500+1;
  LOG(INFO) << dim0 << " x " << dim1 << " x " << dim2 <<std::endl;
  mad3 data2(boost::extents[dim0][dim1][dim2]);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      for (int k = 0; k < dim2; ++k)
        data2[i][j][k] = (double) uni();
  write_h5_file(&data2,tmp_filename,"test2",true);
  //write a complex 2d array
  dim0 = rand()%1000+1;
  dim1 = rand()%1000+1;
  LOG(INFO) << dim0 << " x " << dim1 << std::endl;
  mac2 data3(boost::extents[dim0][dim1]);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      data3[i][j] = dcomplex((double)uni(),(double)uni());
  write_h5_file(&data3,tmp_filename,"test3",true);
  //read data
  auto const* const data_out1 = read_complex_h5_file<4>(tmp_filename,"test1");
  auto const* const data_out2 = read_double_h5_file<3>(tmp_filename,"test2");
  auto const* const data_out3 = read_complex_h5_file<2>(tmp_filename,"test3");
  ASSERT_EQ(data1,*data_out1);
  ASSERT_EQ(data2,*data_out2);
  ASSERT_EQ(data3,*data_out3);
  delete data_out1;
  delete data_out2;
  delete data_out3;
  boost::filesystem::remove(tmp_filename);
}

TEST(MemoryTest, WriteReadRandComplex3D)
{
  std::string const tmp_filename = generate_tmp_filename(".h5");
  int dim0 = 1000;
  int dim1 = 500;
  int dim2 = 500;
  LOG(INFO) << dim0 << " x " << dim1 << " x " << dim2 <<std::endl;
  mac3 data(boost::extents[dim0][dim1][dim2]);
  typedef boost::minstd_rand base_generator_type;
  base_generator_type generator(time(0));
  boost::uniform_real<> uni_dist(-DBL_MAX,DBL_MAX);
  boost::variate_generator<base_generator_type&, boost::uniform_real<> > uni(generator, uni_dist);
  for (int i = 0; i < dim0; ++i)
    for (int j = 0; j < dim1; ++j)
      for (int k = 0; k < dim2; ++k)
        data[i][j][k] = dcomplex((double)uni(),(double)uni());
  write_h5_file(&data,tmp_filename,"test");
  auto const* const data_out = read_complex_h5_file<3>(tmp_filename,"test");
  ASSERT_EQ(data,*data_out);
  delete data_out;
  boost::filesystem::remove(tmp_filename);
}
