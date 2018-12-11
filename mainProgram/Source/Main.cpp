#include"../Include/Main.hpp"//HPP

using namespace std;

void help(char **argv){
	printf("%s -g <file_name_graph> -h <file_name_hosts>\n", argv[0]);
	exit(0);
}

char* searchParameter(char *command, int argc, char **argv){
	for(int i=0; i<argc; i+=1){
		if(!strcmp(argv[i], command)){
			if(1+i<argc){
				return argv[i+1];
			}
		}
	}
	help(argv);
	return command;
}

int main(int argc, char **argv){
	if(argc<5){
		help(argv);
	}
	vector<string> hosts;
	char* fileNameGraph=searchParameter((char*)"-g", argc, argv);
	char* fileNameHosts=searchParameter((char*)"-h", argc, argv);
	ifstream fileGraph(fileNameGraph);
	ifstream fileHosts(fileNameHosts);
	int tamGraph, numAdjs;
	fileGraph>>tamGraph;
	fileGraph>>numAdjs;
	Graph *graph=new Graph(tamGraph);
	for(int i=0; i<numAdjs; i++){
		int node1, node2, cap, cost;
		fileGraph>>node1;
		fileGraph>>node2;
		fileGraph>>cap;
		fileGraph>>cost;
		graph->createAdj(node1, node2, cap, cost);
		graph->createAdj(node2, node1, cap, cost);
	}
	string value;
	while(true){
		if(!(fileHosts>>value)){
			break;
		}
		hosts.push_back(value);
	}
	// graph->print();
	for(int k=0; k<hosts.size()-3; k+=4){
		string value, value2;
		for(int l=2; l<hosts[k+1].size(); l++){
			value+=hosts[k+1][l];
		}
		for(int l=2; l<hosts[k+3].size(); l++){
			value2+=hosts[k+3][l];
		}
		char *as1 = new char[value.length() + 1];
		char *as2 = new char[value2.length() + 1];
		strcpy(as1, value.c_str());
		strcpy(as2, value2.c_str());
		vector<int> smaller=graph->smallerPath(atoi((char *)as1), atoi((char *)as2));
		cout<<"\nsmaller host "<<hosts[k]<<" to host "<<hosts[k+2]<<" : ";
		for(int i=0; i<smaller.size(); i++){
			printf("As%d ", smaller[i]);
		}
	}
	graph->resetGraph();
	for(int k=0; k<hosts.size()-3; k+=4){
		string value, value2;
		for(int l=2; l<hosts[k+1].size(); l++){
			value+=hosts[k+1][l];
		}
		for(int l=2; l<hosts[k+3].size(); l++){
			value2+=hosts[k+3][l];
		}
		char *as1 = new char[value.length() + 1];
		char *as2 = new char[value2.length() + 1];
		strcpy(as1, value.c_str());
		strcpy(as2, value2.c_str());
		vector<int> bestCost=graph->bestWayCost(atoi((char *)as1), atoi((char *)as2));
		cout<<"\nbestCost host "<<hosts[k]<<" to host "<<hosts[k+2]<<" : ";
		for(int i=0; i<bestCost.size(); i++){
			printf("As%d ", bestCost[i]);
		}
	}
	graph->resetGraph();
	for(int k=0; k<hosts.size()-3; k+=4){
		string value, value2;
		for(int l=2; l<hosts[k+1].size(); l++){
			value+=hosts[k+1][l];
		}
		for(int l=2; l<hosts[k+3].size(); l++){
			value2+=hosts[k+3][l];
		}
		char *as1 = new char[value.length() + 1];
		char *as2 = new char[value2.length() + 1];
		strcpy(as1, value.c_str());
		strcpy(as2, value2.c_str());
		vector<int> bestJumps=graph->bestWayJumps(atoi((char *)as1), atoi((char *)as2));
		cout<<"\nbestJumps host "<<hosts[k]<<" to host "<<hosts[k+2]<<" : ";
		for(int i=0; i<bestJumps.size(); i++){
			printf("As%d ", bestJumps[i]);
		}
	}
	graph->resetGraph();
	fileGraph.close();
	fileHosts.close();
	printf("\n");
	delete graph;
	return 0;
}