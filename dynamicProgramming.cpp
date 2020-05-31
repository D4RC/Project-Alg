/*
	Distancia más corta usando programación dinámica
*/
#include "matrix.h"
#define T 12

int shortestDist() {
	short** A = createMatrix<short>(T);
	initialize(A, T);
	loadExample1<short>(A);
	printMatrix(A, T);

	int distance[T];
	distance[T - 1] = 0;

	for (int i = T - 2; i >= 0; i--)
	{
		distance[i] = INF;

		for (int j = i; j < T; j++)
		{
			if (*(*(A + i) + j) == INF)
				continue;

			distance[i] = (distance[i] < *(*(A + i) + j) + distance[j]) ? distance[i] : *(*(A + i) + j) + distance[j];
		}
	}

	cout << endl << "La distancia minima es: " << distance[0] << endl;
	deleteMatrix(A, T);
	return distance[0];
}