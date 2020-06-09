#include "weightedGraph.h"
#define INF 999

/*
	@brief		Función para agregar una arista entre dos vértices
	@param a	vértice
	@param b	vértice 
	@param w	peso de la arista
*/
void WeightedGraph::addEdge(int a, int b, int w)
{
	//Representación 1	Listas de adyacencia
	adj[a].push_back(make_pair(b, w));
	adj[b].push_back(make_pair(a, w));

	//Representación 2	Vector de aristas
	edges.push_back({ w, {a,b} });
}


/*
	@brief	Algoritmo de Prim para obtener el árbol de expansión mínima del grafo
			Retorna el peso del árbol de expansión mínima
*/
void WeightedGraph::prim_minimum_spanning_tree()
{
	/*
	Las colas de prioridad son contenedores adaptados, especialmente diseñados para que
	el primer elemento de la cola sea el mayor, esto facilita una busqueda en un tiempo
	constante, al costo de una inserción y extracción logaritmica
	*/
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;


	//Vértice origen para iniciar el algoritmo
	int src = 0;

	//Almacenamiento de las claves de los vértices, inicializando todos sus elementos con INF
	vector<int> key(V, INF);

	//Vector para almacenar las claves de nodos base del árbol de expansión mínima
	vector<int> parent(V, -1);

	//Para identificar los vértices que forman parte del árbol de expansión mínima
	vector<bool> inMST(V, false);

	//Insertar el origen en la cola de prioridad
	//Marcar su clave como 0
	pq.push(make_pair(0, src));
	key[src] = 0;

	//Iterar hasta que la cola de prioridad quede vacia
	while (!pq.empty())
	{
		//El primer vertice en la cola es el de la llave mínima
		int u = pq.top().second;
		pq.pop();

		//Incluir vértice en el árbol
		inMST[u] = true;

		for (auto& i : adj[u])
		{
			//Etiqueta del vertice y peso del vértice asyacente al actual
			int v = i.first;
			int weight = i.second;

			//Si el vértice no esta en el árbol, y el peso de la arista es menor
			if (!inMST[v] && key[v] > weight)
			{
				//Actualización de la clave
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}
	}

	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << endl;
}


/*
	@brief	Algoritmo de Kruskal para obtener el árbol de expansión mínima del grafo
			Retorna el peso del árbol de expansión mínima
*/
int WeightedGraph::kruskal_minimum_spanning_tree()
{
	int weightMST = 0;

	//Ordenar las aristas ascendentemente en base al peso
	sort(edges.begin(), edges.end());

	//Estructura para crear conjuntos y aplicar el algoritmo de búsqueda - unión
	DisjointSets ds(V);

	for (auto& edge : edges)
	{
		int u = edge.second.first;
		int v = edge.second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		//Checar si la arista seleccionada esta creando un ciclo o no
		//Un ciclo se forma si u y v pertenecen al mismo conjunto
		if (set_u != set_v)
		{
			//Si no se forma un ciclo dicha arista pasa a formar parte del árbol de expansión mínima
			cout << "\t" << u << " - " << v << endl;
		}

		weightMST += edge.first;
		ds.merge(set_u, set_v);
	}

	return weightMST;
}







