#include "weightedGraph.h"

void prim()
{
	//Cargar ejemplo de la clase
	WeightedGraph graph(9);
	graph.addEdge(0, 1, 6);
	graph.addEdge(0, 6, 8);
	graph.addEdge(0, 3, 10);
	graph.addEdge(1, 4, 15);
	graph.addEdge(1, 7, 13);
	graph.addEdge(1, 2, 11);
	graph.addEdge(2, 7, 4);
	graph.addEdge(3, 4, 6);
	graph.addEdge(4, 5, 2);
	graph.addEdge(5, 6, 4);
	graph.addEdge(5, 8, 6);
	graph.addEdge(6, 8, 5);
	graph.addEdge(6, 7, 5);
	graph.addEdge(7, 8, 7);

	//LLamada del algoritmo
	cout << "Ejecutando el algoritmo de Prim" << endl;
	cout << "Aristas del arbol de expansion minima del grafo:" << endl;
	int weight_MST = graph.kruskal_minimum_spanning_tree();

}