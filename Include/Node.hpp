#ifndef NODE_HPP
#define NODE_HPP

#include<cstdio>//C
#include<vector>//CPP
#include"Adj.hpp"//HPP

class Adj;

class Node{
private:
	int index;
	int jumps;
	std::vector<Adj*> adjs;
	bool visitFLag;
public:
	Node();
	Node(int index, int jumps);
	~Node();
	int getIndex();
	bool getFlag();
	int at(int adj);
	void addAdj(int at, int cap);
	void print();
};


#endif