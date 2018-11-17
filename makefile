
CXX = g++
CFLAGS = -std=c++0x 

SOURCES = *.cpp
OBJS = $(SOURCES:.cpp=.o)
LIBa = MAGNUX_LIBCRE.a
LIBso = MAGNUX_LIBCRE.so


all : $(LIBa) $(LIBso)

%.o : %.cpp
    $(CXX) $(CFLAGS) -c $< -o $@ 

$(LIBa) : $(OBJS)
	ar -r MAGNUX_LIBCRE.a $(OBJS)
	
$(LIBso) : $(OBJS)
	$(CXX) -shared $(OBJS) -o $(LIBso)

.PHONY : clean
clean:
    rm -f $(OBJS) $(LIBso) $(LIBa)