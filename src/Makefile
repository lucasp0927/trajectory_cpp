IDIR =../include
CC=g++
CFLAGS= -std=c++11  -I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS= -lyaml-cpp -lglog -lboost_program_options

_DEPS = ConfigParser.h Fields.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o ConfigParser.o Fields.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o ../$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~