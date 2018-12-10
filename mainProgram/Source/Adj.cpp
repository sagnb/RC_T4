#include "../Include/Adj.hpp"//HPP

Adj::Adj(){}

Adj::Adj(int to, int cap, int cost){
	this->to=to;
	this->cap=cap;
	this->cost=cost;
	this->charge=0;
}

Adj::~Adj(){}

int Adj::getTo(){
	return this->to;
}

int Adj::getCost(){
	return this->cost;
}

bool Adj::canUpdate(int charge){
	if(this->charge+charge<=this->cap){
		return true;
	}
	return false;
}

void Adj::update(int charge){
	if(this->charge+charge<=this->cap){
		this->charge+=charge;
	}
}

void Adj::reset(){
	this->charge=0;
}