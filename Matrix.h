#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix
{
public:
	int f, c;
	int ** m;

	//Matrix(int fil, int col);
	Matrix();
	void cargarM(int fil, int col);
	void llenarMceros();

	void colors2Down();

	void printM();

	~Matrix();
};
#endif
