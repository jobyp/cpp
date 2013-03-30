PROGRAMS:=hw grade
BOOST_ROOT:=$(HOME)/local/boost
CPPFLAGS:=-Wall -I $(BOOST_ROOT) -g -O2 
CPP:=g++
LD:=g++
LDFLAGS:=-Wall

hw_OBJS:=hw.o
grade_OBJS:=grade.o median.o student_info.o

######################################################################

.PHONY: all
all : $(PROGRAMS)

PROGRAM_template=$(1) : $$($(1)_OBJS)
DEPENDENCY_template=$(shell $(CPP) -MM $(1))

# Cancel the implicit rule.
% : %.cc

%.o: %.cc
	$(CPP) $(CPPFLAGS) -o $@ -c $<


$(foreach prog,$(PROGRAMS),$(eval $(call PROGRAM_template,$(prog))))
$(foreach f,$(wildcard *.cc),$(eval $(call DEPENDENCY_template,$(f))))

$(PROGRAMS):
	$(LD) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f *.o *~ $(PROGRAMS)
