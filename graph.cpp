#include "graph.h"
/*
	@brief	Función para agregar una arista del grafo
	@param a	nodo origen
	@param b	nodo destino
*/
void Graph::addEdge(int a, int b)
{
	adj[a].push_back(b);
}

/*
	@bief	Algortimo BFS
	@param s	nodo fuente
*/
void Graph::breadth_first_search(int s)
{
	unique_ptr<bool[]> visited(new bool[V]);

	for (int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue;
	
	//Marcar el nodo fuente como visitado
	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i;
	
	while (!queue.empty())
	{
		//Sacar un vertice de la fila
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		//Obtener rodos los vertices adyacentes de dicho vertice
		//Si un vertice adyacente no se ha visitado se marcara como visitado y se enfila

		for (i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

/*
	@bief	Algortimo DFS
	@param s	nodo fuente
*/
void Graph::depth_first_search(int s)
{
	unique_ptr<bool[]> visited(new bool[V]);
	for (int i = 0; i < V; i++)
		visited[i] = false;

	dfs_u(s, visited.get());
}

//Paso recursivo del DFS
void Graph::dfs_u(int v, bool* visited)
{
	//Marcar el nodo actual como visitado
	visited[v] = true;
	cout << v << " ";

	//Recursión para todos los vértices adyacentes al actual
	list<int>::iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); i++) {
		if (!visited[*i])
			dfs_u(*i, visited);
	}
}
