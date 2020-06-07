#include <iostream>
#include "matrix.h"
#define N 9
#define UNASSIGNED 0
using namespace std; 

/*
	Busca una posici�n donde no se haya asignado ya un n�mero en el Grid
	Row y Col conservan dicha posici�n
*/
bool findUnassignedLocation(int grid[][N], int &row, int &col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

//Busca si un n�mero ya ha sido usado previamente en la fila
bool usedInRow(int grid[][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

//Busca si un n�mero ya ha sido usado previamente en la columna
bool usedInCol(int grid[][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

//Busca si un n�mero ya ha sido usado previamente en la subcuadricula 3x3
bool usedInBox(int grid[][N], int startRow, int startCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + startRow][col + startCol] == num)
				return true;
	return false;
}

//Verifica si es valido insertar el n�mero en la celda cumpliendo las condiciones del Sudoku
bool isValid(int grid[][N], int row, int col, int num)
{
	return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) && !usedInBox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == UNASSIGNED;
}

bool solveSudoku(int grid[][N])
{
	int row, col;
	if (!findUnassignedLocation(grid, row, col))
		return true;
	
	for (int num = 1; num <= 9; num++)
	{
		if (isValid(grid, row, col, num))
		{
			//Probar con el n�mero
			grid[row][col] = num;

			//Paso recursivo
			if (solveSudoku(grid))
				return true;

			//Fallar y volver a intentar
			grid[row][col] = UNASSIGNED;
		}
	}

	//Preservar el backtracking
	return false;
}

void backTracking()
{
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					   { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					   { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					   { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					   { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					   { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					   { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					   { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					   { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

	char separator = 250;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{	
			if (grid[i][j]==0)
				cout << separator <<" ";
			else
				cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "Resolviendo el sudoku con un algoritmo de backtracking" << endl << endl;

	if (solveSudoku(grid))
	{
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
				cout<<grid[i][j]<<" ";
		cout<<endl;
		}
	}
	else
		cout << "No hay respuesta para el sudoku" << endl;
}