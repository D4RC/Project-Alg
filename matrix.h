#pragma once
#include <iostream>
using namespace std;

//Templates de utilidad para matrices
	//Número extremadamete alto - (Sin arista)
	#define INF 254

/*
Template:   crearMatriz
Retorna apuntador a matriz[n][n]
    @param n:   tamaño para crear matriz cuadrada
*/
template <class T>
T** createMatrix(size_t n) {
    T **mat = new T*[n];
    for(size_t i=0; i<n; i++) 
        *(mat+i) = new T[n];
    return mat;
}

/*
Template crearMatriz
Retorna apuntador a matriz[f][c]
    @param f  filas de la matriz
    @param c  columnas de la matriz
*/
template <class T>
T** createMatrix(size_t f, size_t c) {
    T **mat = new T*[f];
    for(size_t i=0; i<f; i++)
        *(mat+i) = new T[c];
    return mat;
}

/*
Template eliminarMatriz
Libera la memoria de la matrix
    @param mat: apuntador a la matriz
    @param n:   filas de la matriz
*/
template <class T>
void deleteMatrix(T **mat, size_t n) {
    for(size_t i=0; i<n; i++)
        delete[] *(mat + i);
    delete[] mat;
}

template <class T>
void printMatrix(T **mat, size_t n) {
	char separator = 250;
    for(size_t i=0; i<n; i++)
        cout<<"\t["<<i<<"]";
    cout<<endl;
    for(size_t i=0; i<n; i++) {
        cout<<"["<<i<<"]";
		for (size_t j = 0; j < n; j++)
		{
			if (mat[i][j] == INF)
				cout << "\t"<<separator;
			else
				cout << "\t" << mat[i][j];
		}
        cout<<endl;
    }
}

template <class T>
void initialize(T** mat, size_t n) {
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++)
			* (*(mat + i) + j) = INF;
}

template <class T>
void loadExample1(T **mat) {
	mat[0][1]=6;
	mat[0][2]=8;
	mat[0][3]=7;
	mat[1][4]=9;
	mat[1][5]=10;
	mat[2][4]=5;
	mat[2][5]=7;
	mat[2][6]=5;
	mat[2][7]=6;
	mat[3][6]=8;
	mat[3][7]=14;
	mat[4][8]=10;
	mat[4][9]=8;
	mat[5][8]=7;
	mat[5][9]=9;
	mat[6][8]=11;
	mat[6][9]=8;
	mat[6][10]=7;
	mat[7][9]=12;
	mat[7][10]=6;
	mat[8][11]=14;
	mat[9][11]=6;
	mat[10][11]=15;
}