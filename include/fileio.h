#ifndef FILEIO_H
#define FILEIO_H
#include <glog/logging.h>
#include <iostream>
#include <H5Cpp.h>
using namespace std;
using namespace H5;

void read_h5_file(string filename,string datasetname);


#endif
