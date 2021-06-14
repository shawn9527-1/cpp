
CXX=g++

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)

INCLUDE=-I ./

CFLAGS=-std=c++11

TARGET=demo.out

all:$(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

$(OBJS):%.o:%.cpp
	$(CXX) $< -c -o $@ $(INCLUDE) $(CFLAGS)

clean:
	rm $(OBJS) $(TARGET) -rf
