#include "../Include/Adj.hpp"

Adj::Adj(){}

Adj::Adj(int at, int cap){
	this->at=at;
	this->cap=cap;
}

Adj::~Adj(){}

void Adj::setCap(int cap){
	this->cap=cap;
}

int Adj::getAt(){
	return this->at;
}

int Adj::getCap(){
	return this->cap;
}