#include"../Include/Graph.hpp"//HPP

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

void Graph::createAdj(int from, int to, int cap, int cost){
	this->nodes[from]->addAdj(to, cap, cost);
}

void Graph::print(){
	printf("\n\n==GRAPH STRUCT==\n");
	for(int i=0; i<this->nodes.size(); i++){
		this->nodes.at(i)->print();
	}
	printf("==GRAPH STRUCT==\n\n");
}

vector<int> Graph::smallerPath(int from, int to){
	vector<int> path;
	map<int, int> aux;
	queue<int> visit;
	visit.push(from);
	this->nodes[visit.front()]->setFlag(true);
	int now=visit.front();
	while(visit.size()>0 && now!=to){
		now=visit.front();
		visit.pop();
		for(int i=0; i<this->nodes[now]->getAdjs().size(); i++){
			if(!this->nodes[this->nodes[now]->getAdjs()[i]->getTo()]->getFlag() && this->nodes[now]->getAdjs()[i]->canUpdate(1)){
				visit.push(this->nodes[now]->getAdjs()[i]->getTo());
				this->nodes[this->nodes[now]->getAdjs()[i]->getTo()]->setFlag(true);
				aux[this->nodes[now]->getAdjs()[i]->getTo()]=now;
			}
		}
	}
	while(now!=from){
		path.insert(path.begin(), now);
		now=aux[now];
	}
	path.insert(path.begin(), now);
	for(int i=1; i<path.size(); i++){
		this->nodes[i-1]->update(1, i);
	}
	return path;
}