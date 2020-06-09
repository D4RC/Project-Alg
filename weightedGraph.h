#pragma once
#include <iostream>
#include <list>
#include <queue>
using namespace std;

class WeightedGraph
{
	typedef pair<int, int> edge;

	//N�mero de v�rtices
	int V;

	//Representaci�n del grafo como un arreglo de listas de adyacencia
	//Puntero a un arreglo de listas de adyacencia
	//Estas listas de adyacencia contienen pares (vertice destino, peso)
	unique_ptr< list<pair<int, int>>[] > adj;

	//Otra representaci�n del grafo como un vector de aristas
	//{ peso, { arista origen, arista destino } }
	vector< pair<int, edge> > edges;

	//Representaci�n de conjuntos disjuntos
	struct DisjointSets
	{
		unique_ptr<int[]> parent;
		unique_ptr<int[]> rank;
		int n;

		explicit DisjointSets(int n) : n(n), parent{ make_unique<int[]>(n + 1) }, rank{ make_unique<int[]>(n + 1) } {
			//Incialmente todos los v�rtices estan en diferentes sets y tienen un rango de 0
			for (int i = 0; i < n; i++)
			{
				rank[i] = 0;
				parent[i] = i;
			}
		}
		
		//Encontrar el nodo base de u
		int find(int u)
		{
			if (u != parent[u])
				parent[u] = find(parent[u]);
			return parent[u];
		}

		//Uni�n por ranking
		void merge(int x, int y)
		{
			x = find(x);
			y = find(y);

			//Transformaci�n a sub-�rbol
			if (rank[x] > rank[y])
				parent[y] = x;
			else
				parent[x] = y;

			if (rank[x] == rank[y])
				rank[y]++;
		}
	};

public:
	explicit WeightedGraph(int V) : V(V), adj{ make_unique< list<pair<int,int>>[] >(V) } {}

	//Funci�n para agregar una arista
	void addEdge(int a, int b, int w);

	//Algoritmo de Prim para obtener el �rbol de expansi�n m�nima del grafo
	void prim_minimum_spanning_tree();

	//Algoritmo de Kruskal para obtener el �rbol de expansi�n m�nima del grafo
	int kruskal_minimum_spanning_tree();
};


