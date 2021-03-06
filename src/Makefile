IDIR =../include
#CFLAGS= -std=c++11 -O3 -DNDEBUG -I$(IDIR) -I/usr/include -Wall
ODIR=obj
LDIR =../lib
BDIR = ../build
GTEST_IDIR = /Users/lucaspeng/git_packages/googletest/googletest/include
GTEST_INSTALL = /Users/lucaspeng/git_packages/googletest/googletest/install

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    OS := $(shell lsb_release -si)
endif
ifeq ($(UNAME_S),Linux)
	CC=g++
	CXX=g++
	CFLAGS= -std=c++11 -O3 -I$(IDIR) -I/usr/include -I/usr/include/hdf5/serial -Wall
	LFLAGS= -L$(LDIR)
endif
ifeq ($(OS),Ubuntu)
	CC=g++
	CXX=h5c++
	CFLAGS= -std=c++11 -O3 -I$(IDIR) -I/usr/include -I/usr/include/hdf5/serial/ -Wall
	LFLAGS= -L$(LDIR)
endif
ifeq ($(UNAME_S),Darwin)
	CC=g++
	cXX=g++
	CFLAGS= -std=c++11 -O3 -I$(IDIR) -I/usr/include -I$(GTEST_IDIR)  -Wall
	LFLAGS= -L$(GTEST_INSTALL) -L$(LDIR)
endif


LIBS= -lyaml-cpp -lglog -lgtest -lboost_program_options -lboost_system -lboost_filesystem -lhdf5_cpp -lhdf5 -lpthread -lm

_DEPS = ConfigParser.h Fields.h fileio.h BasePhySystem.h Atoms.h Atom.h FieldTree.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o ConfigParser.o Fields.o fileio.o BasePhySystem.o Atoms.o Atom.o FieldTree.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ_test = main_test.o ConfigParser.o Fields.o fileio.o fileio_test.o ConfigParser_test.o BasePhySystem.o Atoms.o Atom.o FieldTree.o
OBJ_test = $(patsubst %,$(ODIR)/%,$(_OBJ_test))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CXX) -o $(BDIR)/$@ $^ $(CFLAGS) $(LFLAGS) $(LIBS)

main_test: $(OBJ_test)
	$(CXX) -o $(BDIR)/$@ $^ $(CFLAGS) $(LFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
