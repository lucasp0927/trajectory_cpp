IDIR =../include
CC=g++
CFLAGS= -std=c++11 -O3 -DNDEBUG -I$(IDIR) -I/usr/include -Wall
#CFLAGS= -std=c++11 -O3 -I$(IDIR) -I/usr/include -Wall

ODIR=obj
LDIR =../lib

LIBS= -lyaml-cpp -lglog -lgtest -lboost_program_options -lboost_system -lboost_filesystem -lhdf5_cpp -lhdf5

_DEPS = ConfigParser.h Fields.h fileio.h BasePhySystem.h Atoms.h Atom.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o ConfigParser.o Fields.o fileio.o BasePhySystem.o Atoms.o Atom.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ_test = main_test.o ConfigParser.o Fields.o fileio.o fileio_test.o BasePhySystem.o Atoms.o Atom.o
OBJ_test = $(patsubst %,$(ODIR)/%,$(_OBJ_test))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o ../$@ $^ $(CFLAGS) $(LIBS)

main_test: $(OBJ_test)
	$(CC) -o ../$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
