#include "graph.h"

void depthFirstSearch()
{
	//Cargar ejemplo visto en clase
	Graph G(11);

	int data[11][2] = { {6,7},{7,2},{2,9},{7,10},{10,1},{10,4},{6,8},{8,0},{8,3},{3,5} };
		for (auto& row : data)
			G.addEdge(row[0], row[1]);

	cout << "Ejecutando DFS:" << endl;
	G.depth_first_search(6);
	cout << endl << endl;
}