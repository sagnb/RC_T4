#include "../Include/Adj.hpp"//HPP

Adj::Adj(){}

Adj::Adj(int at, int cap, int cost){
	this->at=at;
	this->cap=cap;
	this->cost=cost;
	this->charge=0;
}

Adj::~Adj(){}

int Adj::getAt(){
	return this->at;
}

int Adj::getCost(){
	return this->cost;
}

bool Adj::updateCharge(int charge){
	if(this->charge+charge<=this->cap){
		this->charge+=charge;
		return true;
	}
	return false;
}