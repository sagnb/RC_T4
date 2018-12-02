#include"../Include/Node.hpp"//HPP

using namespace std;

Node::Node(){}

Node::Node(int index, int jumps){
	this->index=index;
	this->visitFLag=false;
	this->jumps=jumps;
}

Node::~Node(){
	Adj *aux;
	int size=this->adjs.size();
	for(int i=0; i<size; i++){
		aux=this->adjs[this->adjs.size()-1];
		this->adjs.pop_back();
		delete aux;
	}
}

int Node::getIndex(){
	return this->index;
}

bool Node::getFlag(){
	return this->visitFLag;
}

int Node::at(int adj){
	return this->adjs.at(adj)->getAt();
}

void Node::addAdj(int at, int cap){
	for(int i=0;  i<this->adjs.size(); i++){
		if(at==this->adjs.at(i)->getAt()){
			return;
		}
	}
	this->adjs.push_back(new Adj(at, cap));
}

void Node::print(){
	printf("node: %d jumps: %d\n", this->index, this->jumps);
	for(int i=0; i<this->adjs.size(); i++){
		printf("\tadj %d: %d cap: %d\n", i, this->adjs.at(i)->getAt(), this->adjs.at(i)->getCap());
	}
}