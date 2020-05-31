#include "matrix.h"

//Cargar grafo del ejemplo visto en clase
#define T 4
void loadExample2(short **);

//Algoritmo Floyd-Warshall para el camino más corto de un grafo dirigido ponderado
void floydWarshall() {

	//Matriz de adyacencia que representa al grafo a procesar
	short** A = createMatrix<short>(T);
	initialize(A, T);
	loadExample2(A);

	cout << endl << "Matriz de adyacencia que representa al grafo:" << endl;
	printMatrix(A, T);

	/*
		Matriz que contendra la disntacia mínima entre nodos
		de  todos los pares de vertices que tengan un camino
		entre sí.
	*/
	short** B = createMatrix<short>(T);

	for (size_t i = 0; i < T; i++)
		for (size_t j = 0; j < T; j++)
			B[i][j] = A[i][j];

	/*
		Iteración del algoritmo
		k será el vértice intermedio en el camino más corto entre origen y destino
	*/

	// k:Vértice intermedio
	for (int k = 0; k < T; k++)
	{
		// i:Origen
		for (int i = 0; i < T; i++)
		{
			// j:Destino
			for (int j = 0; j < T; j++)
			{
				// Si por el vértice k hay un camino más corto entre i y j que el ir
				// directo entonces se actualiza este valor en la matriz de resultado
				if (B[i][k] + B[k][j] < B[i][j])
					B[i][j] = B[i][k] + B[k][j];
			}
		}
	}

	cout << endl << "Matriz del peso del camino mas corto entre vertices:" << endl;
	printMatrix(B, T);

	deleteMatrix(A, T);
	deleteMatrix(B, T);
}

//Ejemplo visto en clase
void loadExample2(short** mat) {
	mat[0][0] = 0;
	mat[1][1] = 0;
	mat[2][2] = 0;
	mat[3][3] = 0;
	mat[1][0] = 2;
	mat[0][1] = 3;
	mat[2][1] = 1;
	mat[3][2] = 2;
	mat[0][3] = 5;
	mat[1][3] = 4;
}
