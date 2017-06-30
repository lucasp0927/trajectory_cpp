IDIR =../include
CC=g++
CFLAGS= -std=c++11 -O3 -DNDEBUG -I$(IDIR) -I/usr/include -Wall

ODIR=obj
LDIR =../lib

LIBS= -lyaml-cpp -lglog -lboost_program_options -lhdf5_cpp -lhdf5

_DEPS = ConfigParser.h Fields.h FieldTree.h fileio.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o ConfigParser.o Fields.o FieldTree.o fileio.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o ../$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
