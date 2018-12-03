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
	return 0;
}