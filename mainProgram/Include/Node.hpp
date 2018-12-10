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
	int getJumps();
	void setFlag(bool status);
	std::vector<Adj*> getAdjs();
	void addAdj(int to, int cap, int cost);
	void print();
	void update(int charge, int to);
	void reset();
};


#endif