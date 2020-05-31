/*
	Distancia más corta usando programación dinámica
*/
#include "matrix.h"
#define T 12

void loadExample1(short**);

int shortestDist() {
	short** A = createMatrix<short>(T);
	initialize(A, T);
	loadExample1(A);
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

void loadExample1(short** mat) {
	mat[0][1] = 6;
	mat[0][2] = 8;
	mat[0][3] = 7;
	mat[1][4] = 9;
	mat[1][5] = 10;
	mat[2][4] = 5;
	mat[2][5] = 7;
	mat[2][6] = 5;
	mat[2][7] = 6;
	mat[3][6] = 8;
	mat[3][7] = 14;
	mat[4][8] = 10;
	mat[4][9] = 8;
	mat[5][8] = 7;
	mat[5][9] = 9;
	mat[6][8] = 11;
	mat[6][9] = 8;
	mat[6][10] = 7;
	mat[7][9] = 12;
	mat[7][10] = 6;
	mat[8][11] = 14;
	mat[9][11] = 6;
	mat[10][11] = 15;
}