CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: main

main: main.o Matrix.o
	$(CXX) $(CXXFLAGS) -o main main.o Matrix.o

main.o: main.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Matrix.o: Matrix.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix.cpp

clean:
	rm -f *.o main
