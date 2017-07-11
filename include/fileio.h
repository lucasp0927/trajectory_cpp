#ifndef FILEIO_H
#define FILEIO_H
#include <glog/logging.h>
#include "boost/multi_array.hpp"
#include "boost/array.hpp"
#include <boost/filesystem.hpp> //for generating temp files
#include <complex>
#include <iostream>
#include <H5Cpp.h>
#include <stdexcept>
#include <sstream>

#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/generator_iterator.hpp>
#include "gtest/gtest.h"


using namespace std;
using namespace H5;
typedef complex<double> dcomplex;
typedef boost::multi_array<double,1> mad1;
typedef boost::multi_array<double,2> mad2;
typedef boost::multi_array<double,3> mad3;
typedef boost::multi_array<double,4> mad4;
typedef boost::multi_array<dcomplex,1> mac1;
typedef boost::multi_array<dcomplex,2> mac2;
typedef boost::multi_array<dcomplex,3> mac3;
typedef boost::multi_array<dcomplex,4> mac4;
//read
template <unsigned long DIM>
boost::multi_array<double,DIM>* const read_double_h5_file(string const filename,\
                                                          string const datasetname);
mac1* const read_complex_h5_file_1d(string const filename, string const datasetname);
mac2* const read_complex_h5_file_2d(string const filename, string const datasetname);
mac3* const read_complex_h5_file_3d(string const filename, string const datasetname);
mac4* const read_complex_h5_file_4d(string const filename, string const datasetname);

//write
template <unsigned long DIM>
void write_h5_file(boost::multi_array<double,DIM> const* const data, string const filename,\
                   string const datasetname, bool const append = false);

template <unsigned long DIM>
void write_h5_file(boost::multi_array<dcomplex,DIM> const* const data, string const filename,\
                   string const datasetname, bool const append = false);

//helping function
template <unsigned long DIM>
double const* const real_parts(boost::multi_array<dcomplex,DIM> const* const data);

template <unsigned long DIM>
double const* const imag_parts(boost::multi_array<dcomplex,DIM> const* const data);

//print
template <typename T>
void print_multi_array(boost::multi_array<T,2> const* const data, bool const print_data = false);

template <typename T>
void print_multi_array(boost::multi_array<T,3> const* const data, bool const print_data = false);

template <typename T>
void print_multi_array(boost::multi_array<T,4> const* const data, bool const print_data = false);

#endif
