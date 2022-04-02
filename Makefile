CXX = g++
CXXFLAGS = -std=c++14 -O2 -Wall


sparse: Sparse.o 
	$(CXX) $(CXXFLAGS) Sparse.o -o sparse

Sparse.o: Sparse.cpp
	$(CXX) $(CXXFLAGS) -c Sparse.cpp

all: sparse

run: sparse
	./sparse

clean:
	rm -rf sparse *.o
