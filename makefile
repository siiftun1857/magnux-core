
CXX = g++
CFLAGS = -std=c++0x

SOURCES = MAGNUX_CORE.CPP MXNothing.cpp MXArray.cpp MXAlgorithm.cpp MAGNUX_LIBCRE.CPP
OBJS = $(SOURCES:.cpp=.o)
LIBa = MAGNUX_LIBCRE.a
LIBso = MAGNUX_LIBCRE.so


all : $(LIBa) $(LIBso) finished

finished : $(LIBa) $(LIBso)
	rm -f *.o

$(OBJS): $(@:.o=.cpp)
	$(CXX) $(CFLAGS) -c $(@:.o=.cpp) -o $@

$(LIBa) : $(OBJS)
	ar -r MAGNUX_LIBCRE.a $(OBJS)

$(LIBso) : $(OBJS)
	$(CXX) -shared $(OBJS) -o $(LIBso)

.PHONY : clean
clean:
	rm -f *.o *.a *.so
