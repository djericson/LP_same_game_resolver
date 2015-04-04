#include "Matrix.h"

Matrix::Matrix(int fil, int col)
{
	f = fil;
	c = col;
	m = new int*[f];
	for(int i = 0; i < f; i++)
		m[i] = new int[c];
}

void Matrix::llenarMceros()
{
	for(int i = 0; i < f; i++){
		m[i][i] = 0;
	}
}

void Matrix::printM()
{
	for(int i = 0; i < f; i++)
	{
		cout<<endl;
		for(int j = 0;j < c; j++)
			cout<<m[i][j]<<'\t';
	}
	cout<<endl;
}

Matrix::~Matrix(){}
