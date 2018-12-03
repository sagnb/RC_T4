#ifndef GRAPH_HPP
#define GRAPH_HPP

#include"Node.hpp"//HPP

class Adj;
class Node;

class Graph{
private:
	std::vector<Node*> nodes;
public:
	Graph();
	Graph(int numNodes);
	~Graph();
	void createAdj(int of, int at, int cap, int cost);
	void print();
};

#endif