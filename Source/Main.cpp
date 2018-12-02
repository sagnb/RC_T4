#include"../Include/Main.hpp"

using namespace std;

int main(int argc, char **argv){
	int tam;
	printf("tam of graph: ");
	scanf("%d", &tam);
	Graph *graph=new Graph(tam);
	graph->createAdj(0, 1, 0);
	graph->createAdj(0, 2, 0);
	graph->createAdj(1, 1, 0);
	graph->createAdj(2, 2, 0);
	graph->createAdj(3, 1, 0);
	graph->createAdj(4, 2, 0);
	graph->print();
	delete graph;
	return 0;
}