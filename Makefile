CPPFLAGS = -std=c++11

a.out:	Cache/Main.o Cache/Graph.o Cache/Node.o Cache/Adj.o
	g++ Cache/Main.o Cache/Graph.o Cache/Node.o Cache/Adj.o $(CPPFLAGS)

Cache/Main.o:	Source/Main.cpp Include/Main.hpp
	g++ -c Source/Main.cpp -o Cache/Main.o

Cache/Graph.o:	Source/Graph.cpp Include/Graph.hpp
	g++ -c Source/Graph.cpp -o Cache/Graph.o

Cache/Node.o:	Source/Node.cpp Include/Node.hpp
	g++ -c Source/Node.cpp -o Cache/Node.o

Cache/Adj.o:	Source/Adj.cpp Include/Adj.hpp
	g++ -c Source/Adj.cpp -o Cache/Adj.o

clean:
	rm Cache/*.o
