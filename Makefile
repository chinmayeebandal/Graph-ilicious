CXX = g++
CXXFLAGS = -std=c++14 -O2 -Wall


unionfind: UnionFind.o 
	$(CXX) $(CXXFLAGS) UnionFind.o -o unionfind

UnionFind.o: UnionFind.cpp
	$(CXX) $(CXXFLAGS) -c UnionFind.cpp

all: unionfind

run: unionfind
	./unionfind

clean:
	rm -rf unionfind *.o
