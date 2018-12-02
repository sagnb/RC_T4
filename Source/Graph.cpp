#include"../Include/Graph.hpp"

using namespace std;

Graph::Graph(){}

Graph::Graph(int numNodes){
	for(int i=0; i<numNodes; i++){
		this->nodes.push_back(new Node(i, 1));
	}
}

Graph::~Graph(){
	Node *aux;
	int size=this->nodes.size();
	for(int i=0; i<size; i++){
		aux=this->nodes[this->nodes.size()-1];
		this->nodes.pop_back();
		delete aux;
	}
}

void Graph::createAdj(int of, int at, int cap){
	this->nodes[of]->addAdj(at, cap);
}

void Graph::print(){
	printf("\n\n==GRAPH STRUCT==\n");
	for(int i=0; i<this->nodes.size(); i++){
		this->nodes.at(i)->print();
	}
	printf("==GRAPH STRUCT==\n\n");
}