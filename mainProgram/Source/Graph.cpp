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

void Graph::resetGraph(){
	for(int i=0; i<this->nodes.size(); i++){
		this->nodes[i]->reset();
	}
}

vector<int> Graph::smallerPath(int from, int to){
	vector<int> path;
	map<int, int> aux;
	queue<int> visit;
	visit.push(from);
	this->nodes[visit.front()]->setFlag(true);
	int now=visit.front();
	for(int i=0; i<this->nodes.size(); i++){
		aux[i]=-1;
	}
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
		if(now==-1){
			path.clear();
			return path;
		}
	}
	path.insert(path.begin(), now);
	for(int i=1; i<path.size(); i++){
		this->nodes[i-1]->update(1, i);
	}
	return path;
}

std::vector<int> Graph::bestWayCost(int from, int to){
	vector<int> path;
	map<int, int> label;
	map<int, int> aux;
	int winner;
	for(int i=0; i<this->nodes.size(); i++){
		label[i]=100000;
		aux[i]=-1;
	}
	label[from]=0;
	aux[from]=-1;
	while(!this->itsOver()){
		winner=this->theWinner(label);
		for(int i=0; i<this->nodes[winner]->getAdjs().size(); i++){
			if(label[this->nodes[winner]->getAdjs()[i]->getTo()]>label[winner]+this->nodes[winner]->getAdjs()[i]->getCost() && this->nodes[winner]->getAdjs()[i]->canUpdate(1)){
				label[this->nodes[winner]->getAdjs()[i]->getTo()]=label[winner]+this->nodes[winner]->getAdjs()[i]->getCost();
				aux[this->nodes[winner]->getAdjs()[i]->getTo()]=winner;
			}
		}
	}
	int now=to;
	while(now!=from){
		path.insert(path.begin(), now);
		now=aux[now];
		if(now==-1){
			path.clear();
			return path;
		}
	}
	path.insert(path.begin(), now);
	for(int i=1; i<path.size(); i++){
		this->nodes[i-1]->update(1, i);
	}
	return path;
}

std::vector<int> Graph::bestWayJumps(int from, int to){
	vector<int> path;
	map<int, int> label;
	map<int, int> aux;
	int winner;
	for(int i=0; i<this->nodes.size(); i++){
		label[i]=100000;
		aux[i]=-1;
	}
	label[from]=0;
	aux[from]=-1;
	while(!this->itsOver()){
		winner=this->theWinner(label);
		for(int i=0; i<this->nodes[winner]->getAdjs().size(); i++){
			if(label[this->nodes[winner]->getAdjs()[i]->getTo()]>label[winner]+this->nodes[this->nodes[winner]->getAdjs()[i]->getTo()]->getJumps() && this->nodes[winner]->getAdjs()[i]->canUpdate(1)){
				label[this->nodes[winner]->getAdjs()[i]->getTo()]=label[winner]+this->nodes[this->nodes[winner]->getAdjs()[i]->getTo()]->getJumps();
				aux[this->nodes[winner]->getAdjs()[i]->getTo()]=winner;
			}
		}
	}
	int now=to;
	while(now!=from){
		path.insert(path.begin(), now);
		now=aux[now];
		if(now==-1){
			path.clear();
			return path;
		}
	}
	path.insert(path.begin(), now);
	for(int i=1; i<path.size(); i++){
		this->nodes[i-1]->update(1, i);
	}
	return path;
}

bool Graph::itsOver(){
	for(int i=0; i<this->nodes.size(); i++){
		if(!this->nodes[i]->getFlag()){
			return false;
		}
	}
	return true;
}

int Graph::theWinner(map<int, int> label){
	int winner=0;
	vector<int> notVisited;
	for(int i=0; i<this->nodes.size(); i++){
		if(!this->nodes[i]->getFlag()){
			notVisited.push_back(i);
		}
	}
	for(int i=0; i<notVisited.size(); i++){
		if(label[notVisited[i]]<label[notVisited[winner]]){
			winner=i;
		}
	}
	this->nodes[notVisited[winner]]->setFlag(true);
	return notVisited[winner];
}