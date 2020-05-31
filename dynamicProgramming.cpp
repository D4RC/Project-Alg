/*
	Distancia más corta usando programación dinámica
*/
#include "matrix.h"
#define T 12

int shortestDist() {
	short** A = createMatrix<short>(T);
	initialize(A, T);
	cargarEjemplo<short>(A);
	printMatrix(A, T);

	int distancia[T];
	distancia[T - 1] = 0;

	for (int i = T - 2; i >= 0; i--)
	{
		distancia[i] = INF;

		for (int j = i; j < T; j++)
		{
			if (*(*(A + i) + j) == INF)
				continue;

			distancia[i] = (distancia[i] < *(*(A + i) + j) + distancia[j]) ? distancia[i] : *(*(A + i) + j) + distancia[j];
		}
	}

	cout << endl << "La distancia minima es: " << distancia[0] << endl;
	deleteMatrix(A, T);
	return distancia[0];
}