#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<queue>//CPP
#include<stack>//CPP
#include<map>//CPP
#include<algorithm>//CPP
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
	void resetGraph();
	std::vector<int> smallerPath(int from, int to);
	std::vector<int> bestWayCost(int from, int to);
	std::vector<int> bestWayJumps(int from, int to);
	bool itsOver();
	int theWinner(std::map<int, int> label);
};

#endif