int shortestDist();
void floydWarshall();
void breadthFirstSearch();
void depthFirstSearch();
void backTracking();
void kruskal();
void prim();

int main() {
	/*
						  Programación dinámica

	La programación dinámica se puede describir como una técnica de 
	optimización a la recursión. La idea de la programación dinámica 
	es conservar el resultado de sub-problemas anteriores  y de esta
	forma  no tener que volverlos a computar en posteriores llamadas
	recursivas. Esto sule reducir la complejidad exponencial de algu-
	nos algoritmos a una polinómica.

	En la programación dinámica se resuelven los problemas mediante
	una secuencia de decisiones, y solamente hasta el final se sabe
	cuál es la mejor de ellas.

	Ejemplo:
	En la implementación propuesta se uso para hallar la ruta mínima
	de un grafo dirigido ponderado.
	*/
	shortestDist();

	/*
						Algoritmo Floyd-Warshall
	
	El algoritmo de Floyd-Warshall es un algortimo de análisis sobre
	grafos para encontrar el camino más corto.

	El algoritmo funciona para grafos dirigidos y ponderados, y sigue
	un enfoque de programación dinámica,  ya que se basa en ir buscar
	la solución a través de vértices intermedios. 

	Los detalles se despliegan en la implementación.
	*/
	floydWarshall();

	/*
							Algoritmo BFS

	Algoritmo para el recorrido o búsqueda detro de un árbol o grafo
	
	En este caso la implementación se sirve de la representación del
	grafo como listas de adyacencia, y un arreglo de nodos visitados.
	
	El algoritmo comienza de un nodo arbitrario recorriendo los nodos
	vecinos a esté, si el nodo al que se llega no ha sido visitado se
	marca añadiendolo a una cola. Este recorrido se hace por cada uno
	de los vértices, al principio de cada iteración se extrae el nodo
	que se encuentre al frente de la cola.  Estas extracciones marcan
	el recorrido en anchura.
	*/
	breadthFirstSearch();

	/*
							Algoritmo DFS

	El algoritmo depth first search  o traversal ocupa una estrategía
	inversa al del algoritmo DFS, pues recorre primero en profundidad.

	De nuevo la implementación propuesta ocupa la representación del
	grafo como listas de adyacencia, se escoje un nodo raíz y se hace
	un recorrido por los nodos vecinos hasta la mayor profundidad de
	dicha rama antes de hacer backtracking. Para verificar cuando es
	momento de realizar el backtracking tambien hay que preservar un  
	arreglo de nodos visitados previamente. El backtracking se puede
	conseguir mediante una función recursiva.
	*/
	depthFirstSearch();

	/*
						     Backtracking
	
	Backtracking es una técnica de diseño de algoritmos, que busca de
	manera sistemática todas las soluciones a un problema.

	La estrategia del backtracking se basa en resolver problemas de ma-
	mera recursiva e ir construyendo incrementalmente una solución , a
	su vez se van descartando las soluciones que no satisfacen las res-
	tricciones del problema.

	Para ejemplificar un algoritmo que usa esta estrategia,  se propuso
	la siguiente implementación que resuelve un Sudoku.

	El backtracking se evidencia cuando se halla un digito que no lleva
	a la solución, por lo que se remueve y se intenta con el sig dígito
	*/
	backTracking();

	/*
						Algoritmo de Kruskal

	Algoritmo para calcular el árbol de expansión mínima de Kruskal

	Teniendo un grafo no dirigido, conexo y ponderado,   G = ( V, E)
	el algoritmo ejecuta los siguientes pasos sobre el grafo:

	1-Ordenar todas las aristas en un orden ascendente según su peso

	2-Tomar la arista más pequeña, revisar si forma un ciclo con el
	  árbol de expansión construido hasta ahora , si no se forma un
	  ciclo esta se incluira en el árbol.

	3-Repetir el paso anterior hasta tener V-1 aristas para el árbol
	  de expansión mínima

	La implementación propuesta ocupa un vector de aristas para pri-
	orizar las aristas de menor peso

	A su vez se ocupa el algoritmo de estructura unión-búsqueda para
	detectar un ciclo.

	El algoritmo de Kruskal es un algoritmo avaro ya que selecciona
	la arista de menor peso que no cause un ciclo en el árbol de re-
	corrido mínimo en construcción.

	La complejidad del algoritmo es O(E log E) o O(E log V), ya que
	el ordenamiento de las aristas toma un tiempo de O(E log E) , y
	el algoritmo para encontrar uniones toma un tiempo de O( log V),
	por lo tanto la complejidad total es O(E log E + E log V), y ya
	que el valor de E a lo sumo es V^2, se puede decir que O( log V)
	y O( log E ) son similares en cuanto a complejidad temporal.
	*/
	kruskal();


	/*
						Algoritmo de Prim

	Algoritmo para calcular el árbol de expansión mínima de Prim.

	Al igual que el algoritmo de Kruskal el algoritmo de Prim es un
	ejemplo de algoritmo avaro.

	El algoritmo de Prim sigue los siguientes pasos:

	Empezar con un árbol de expansión mínima vacio
	Tener dos conjuntos de vértices 
		El primero incluira los vértices ya incluidos en el árbol
		El segundo los que no se han añadido

	En cada paso se consideran aristas que unen ambos conjuntos, se
	priorizará la arista de menor peso, al realizar esto el vértice
	destino pasará a formar parte del árbol de expansión mínima. Se
	repite este paso hasta que todos los vértices formen se hallan
	clasificado.

	La implementación propuesta incluye una mejora sobre el algoritmo
	original ya que utiliza una cola de prioridad y la representación
	del grafo como listas de adyacencia. 

	Esto concluye en una complejidad de O( E log V)
	*/
	prim();

	return 0;
}



