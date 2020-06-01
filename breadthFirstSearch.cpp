#include "graph.h"

void breadthFirstSearch() {
//Cargar ejemplo visto en clase
	Graph G(12);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(0, 3);
	G.addEdge(1, 4);
	G.addEdge(1, 5);
	G.addEdge(3, 6);
	G.addEdge(3, 7);
	G.addEdge(4, 8);
	G.addEdge(4, 9);
	G.addEdge(6, 10);
	G.addEdge(6, 11);

	cout << "Ejecutando BFS:" << endl;
	G.breadth_first_search(0);
	cout << endl << endl;
}