#include"../Include/Main.hpp"//HPP

using namespace std;

void help(void){
	printf("./a.out -t <tam of graph>\n");
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
	help();
}

int main(int argc, char **argv){
	if(argc<3){
		help();
	}
	int tam=atoi(searchParameter("-t", argc, argv));
	if(tam<1){
		exit(0);
	}
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