int shortestDist();
void floydWarshall();
void breadthFirstSearch();
void depthFirstSearch();
void backTracking();
void kruskal();
void prim();

int main() {
	/*
						  Programaci�n din�mica

	La programaci�n din�mica se puede describir como una t�cnica de 
	optimizaci�n a la recursi�n. La idea de la programaci�n din�mica 
	es conservar el resultado de sub-problemas anteriores  y de esta
	forma  no tener que volverlos a computar en posteriores llamadas
	recursivas. Esto sule reducir la complejidad exponencial de algu-
	nos algoritmos a una polin�mica.

	En la programaci�n din�mica se resuelven los problemas mediante
	una secuencia de decisiones, y solamente hasta el final se sabe
	cu�l es la mejor de ellas.

	Ejemplo:
	En la implementaci�n propuesta se uso para hallar la ruta m�nima
	de un grafo dirigido ponderado.
	*/
	shortestDist();

	/*
						Algoritmo Floyd-Warshall
	
	El algoritmo de Floyd-Warshall es un algortimo de an�lisis sobre
	grafos para encontrar el camino m�s corto.

	El algoritmo funciona para grafos dirigidos y ponderados, y sigue
	un enfoque de programaci�n din�mica,  ya que se basa en ir buscar
	la soluci�n a trav�s de v�rtices intermedios. 

	Los detalles se despliegan en la implementaci�n.
	*/
	floydWarshall();

	/*
							Algoritmo BFS

	Algoritmo para el recorrido o b�squeda detro de un �rbol o grafo
	
	En este caso la implementaci�n se sirve de la representaci�n del
	grafo como listas de adyacencia, y un arreglo de nodos visitados.
	
	El algoritmo comienza de un nodo arbitrario recorriendo los nodos
	vecinos a est�, si el nodo al que se llega no ha sido visitado se
	marca a�adiendolo a una cola. Este recorrido se hace por cada uno
	de los v�rtices, al principio de cada iteraci�n se extrae el nodo
	que se encuentre al frente de la cola.  Estas extracciones marcan
	el recorrido en anchura.
	*/
	breadthFirstSearch();

	/*
							Algoritmo DFS

	El algoritmo depth first search  o traversal ocupa una estrateg�a
	inversa al del algoritmo DFS, pues recorre primero en profundidad.

	De nuevo la implementaci�n propuesta ocupa la representaci�n del
	grafo como listas de adyacencia, se escoje un nodo ra�z y se hace
	un recorrido por los nodos vecinos hasta la mayor profundidad de
	dicha rama antes de hacer backtracking. Para verificar cuando es
	momento de realizar el backtracking tambien hay que preservar un  
	arreglo de nodos visitados previamente. El backtracking se puede
	conseguir mediante una funci�n recursiva.
	*/
	depthFirstSearch();

	/*
						     Backtracking
	
	Backtracking es una t�cnica de dise�o de algoritmos, que busca de
	manera sistem�tica todas las soluciones a un problema.

	La estrategia del backtracking se basa en resolver problemas de ma-
	mera recursiva e ir construyendo incrementalmente una soluci�n , a
	su vez se van descartando las soluciones que no satisfacen las res-
	tricciones del problema.

	Para ejemplificar un algoritmo que usa esta estrategia,  se propuso
	la siguiente implementaci�n que resuelve un Sudoku.

	El backtracking se evidencia cuando se halla un digito que no lleva
	a la soluci�n, por lo que se remueve y se intenta con el sig d�gito
	*/
	backTracking();

	/*
						Algoritmo de Kruskal

	Algoritmo para calcular el �rbol de expansi�n m�nima de Kruskal

	Teniendo un grafo no dirigido, conexo y ponderado,   G = ( V, E)
	el algoritmo ejecuta los siguientes pasos sobre el grafo:

	1-Ordenar todas las aristas en un orden ascendente seg�n su peso

	2-Tomar la arista m�s peque�a, revisar si forma un ciclo con el
	  �rbol de expansi�n construido hasta ahora , si no se forma un
	  ciclo esta se incluira en el �rbol.

	3-Repetir el paso anterior hasta tener V-1 aristas para el �rbol
	  de expansi�n m�nima

	La implementaci�n propuesta ocupa un vector de aristas para pri-
	orizar las aristas de menor peso

	A su vez se ocupa el algoritmo de estructura uni�n-b�squeda para
	detectar un ciclo.

	El algoritmo de Kruskal es un algoritmo avaro ya que selecciona
	la arista de menor peso que no cause un ciclo en el �rbol de re-
	corrido m�nimo en construcci�n.

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

	Algoritmo para calcular el �rbol de expansi�n m�nima de Prim.

	Al igual que el algoritmo de Kruskal el algoritmo de Prim es un
	ejemplo de algoritmo avaro.

	El algoritmo de Prim sigue los siguientes pasos:

	Empezar con un �rbol de expansi�n m�nima vacio
	Tener dos conjuntos de v�rtices 
		El primero incluira los v�rtices ya incluidos en el �rbol
		El segundo los que no se han a�adido

	En cada paso se consideran aristas que unen ambos conjuntos, se
	priorizar� la arista de menor peso, al realizar esto el v�rtice
	destino pasar� a formar parte del �rbol de expansi�n m�nima. Se
	repite este paso hasta que todos los v�rtices formen se hallan
	clasificado.

	La implementaci�n propuesta incluye una mejora sobre el algoritmo
	original ya que utiliza una cola de prioridad y la representaci�n
	del grafo como listas de adyacencia. 

	Esto concluye en una complejidad de O( E log V)
	*/
	prim();

	return 0;
}



