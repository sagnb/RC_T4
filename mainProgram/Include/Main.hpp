#ifndef MAIN_HPP
#define MAIN_HPP

#include<cstdio>//C
#include<cstdlib>//C
#include<cstring>//C
#include<iostream>//CPP
#include<fstream>//CPP
#include"Graph.hpp"//HPP

class Adj;
class Node;
class Graph;

void help(char **argv);
char* searchParameter(char *command, int argc, char **argv);
int main(int argc, char **argv);

#endif