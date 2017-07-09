#ifndef FILEIO_H
#define FILEIO_H
#include <glog/logging.h>
#include "boost/multi_array.hpp"
#include <complex>
#include <iostream>
#include <H5Cpp.h>
#include <cassert>
#include <stdexcept>
#include <sstream>
using namespace std;
using namespace H5;
typedef complex<double> dcomplex;

boost::multi_array<double,2>* const read_double_h5_file_2d(string const filename,string const datasetname);
boost::multi_array<double,3>* const read_double_h5_file_3d(string const filename,string const datasetname);
boost::multi_array<double,4>* const read_double_h5_file_4d(string const filename,string const datasetname);

boost::multi_array<dcomplex,2>* const read_complex_h5_file_2d(string const filename,string const datasetname);
boost::multi_array<dcomplex,3>* const read_complex_h5_file_3d(string const filename,string const datasetname);
boost::multi_array<dcomplex,4>* const read_complex_h5_file_4d(string const filename,string const datasetname);

template <typename T>
void print_multi_array(boost::multi_array<T,2> const* const data);

template <typename T>
void print_multi_array(boost::multi_array<T,3> const* const data);

template <typename T>
void print_multi_array(boost::multi_array<T,4> const* const data);

#endif
