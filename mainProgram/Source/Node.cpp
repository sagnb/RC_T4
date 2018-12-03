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

int Node::getJumps(){
	return this->jumps;
}

void Node::setFlag(bool status){
	this->visitFLag=status;
}

vector<Adj*> Node::getAdjs(){
	return this->adjs;
}

void Node::addAdj(int at, int cap, int cost){
	for(int i=0;  i<this->adjs.size(); i++){
		if(at==this->adjs.at(i)->getAt()){
			return;
		}
	}
	this->adjs.push_back(new Adj(at, cap, cost));
}

void Node::print(){
	printf("node: %d jumps: %d\n", this->index, this->jumps);
	for(int i=0; i<this->adjs.size(); i++){
		printf("\tadj %d: %d cost: %d\n", i, this->adjs.at(i)->getAt(), this->adjs.at(i)->getCost());
	}
}