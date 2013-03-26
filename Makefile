PROGRAMS=hw
BOOST_ROOT=$(HOME)/local/boost
CPPFLAGS=-Wall -I $(BOOST_ROOT) -g -O2 -save-temps
CPP=g++

.PHONY: all
all : $(PROGRAMS)

%.o : %.cc
	$(CPP) $(CPPFLAGS) -o $@ -c $<

hw : hw.o
	$(CPP) -o $@ $<

.PHONY: clean
clean:
	rm -f *.o *.ii *.s *~ $(PROGRAMS)

