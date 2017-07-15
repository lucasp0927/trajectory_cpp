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
namespace fileio
{
  using namespace H5;
  typedef std::complex<double> dcomplex;
  template <unsigned long DIM>
    using mad = boost::multi_array<double,DIM>;
  template <unsigned long DIM>
    using mac = boost::multi_array<dcomplex,DIM>;

  //read
  template <unsigned long DIM>
    mad<DIM>* const read_double_h5_file(std::string const filename,\
                                        std::string const datasetname);

  template <unsigned long DIM>
    mac<DIM>* const read_complex_h5_file(std::string const filename,\
                                         std::string const datasetname);

  //write
  template <unsigned long DIM>
    void write_h5_file(mad<DIM> const* const data, std::string const filename,\
                       std::string const datasetname, bool const append = false);

  template <unsigned long DIM>
    void write_h5_file(mac<DIM> const* const data, std::string const filename,\
                       std::string const datasetname, bool const append = false);

  //helping function
  template <unsigned long DIM>
    double const* const real_parts(mac<DIM> const* const data);

  template <unsigned long DIM>
    double const* const imag_parts(mac<DIM> const* const data);

  //print
  template <typename T>
    void print_multi_array(boost::multi_array<T,2> const* const data, bool const print_data = false);

  template <typename T>
    void print_multi_array(boost::multi_array<T,3> const* const data, bool const print_data = false);

  template <typename T>
    void print_multi_array(boost::multi_array<T,4> const* const data, bool const print_data = false);
}
#endif
