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