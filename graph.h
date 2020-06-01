#pragma once
#include <iostream>
#include <list>
using namespace std;

class Graph
{
	//Número de vértices
	int V;

	//Puntero a un arreglo de listas de adyacencia
	unique_ptr<list<int>[]> adj;

public:
	explicit Graph(int V) : V(V), adj{ make_unique < list<int>[] >(V) } {}


	//Función para agregar una arista
	void addEdge(int a, int b);

	//Algoritmo BFS
	void breadth_first_search(int s);

	//Algoritmo DFS
	void depth_first_search(int s);
	void dfs_u(int v, bool* visited);
};

