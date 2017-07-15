#ifndef INTERP_H
#define INTERP_H
#include <glog/logging.h>
#include "boost/multi_array.hpp"
#include <complex>
#include <iostream>
#include <stdexcept>
#include "gtest/gtest.h"

namespace interp
{
  typedef std::complex<double> dcomplex;
  template <unsigned long DIM>
    using mad = boost::multi_array<double,DIM>;
  template <unsigned long DIM>
    using mac = boost::multi_array<dcomplex,DIM>;

  template<typename T,unsigned long DIM>
    class Interp
  {
  protected:
  public:
    Interp();
    ~Interp() = default;
    virtual T interp();
  };


}

#endif
