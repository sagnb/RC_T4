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
	char* fileNameGraph=searchParameter((char*)"-g", argc, argv);
	char* fileNameHosts=searchParameter((char*)"-h", argc, argv);
	ifstream fileGraph(fileNameGraph);
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
	graph->print();
	vector<int> smaller=graph->smallerPath(80, 70);
	graph->resetGraph();
	vector<int> bestCost=graph->bestWayCost(80, 70);
	graph->resetGraph();
	vector<int> bestJumps=graph->bestWayJumps(80, 70);
	fileGraph.close();
	printf("\nsmaller ");
	for(int i=0; i<smaller.size(); i++){
		printf("ASs%d ", smaller[i]);
	}
	printf("\nbestJumps ");
	for(int i=0; i<bestJumps.size(); i++){
		printf("ASs%d ", bestJumps[i]);
	}
	printf("\nbestCost ");
	for(int i=0; i<bestCost.size(); i++){
		printf("ASs%d ", bestCost[i]);
	}
	printf("\n");
	delete graph;
	return 0;
}