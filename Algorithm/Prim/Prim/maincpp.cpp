#include "Graph.h"
int main() {
	Graph_List g;
	createGraph(g);
	print(g);
	Prim(g, 1);
	system("pause");
	return 0;
}