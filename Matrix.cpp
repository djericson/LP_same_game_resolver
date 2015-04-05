#include "Matrix.h"

/*
Matrix::Matrix(int fil, int col)
{
	f = fil;
	c = col;
	m = new int*[f];
	for(int i = 0; i < f; i++)
		m[i] = new int[c];
}
*/

Matrix::Matrix(){
    f = 0;
    c = 0;
    m = new int*[1];
}

void Matrix::cargarM(int fil, int col){
    f = fil;
	c = col;
	m = new int*[f];
	for(int i = 0; i < f; i++)
		m[i] = new int[c];
}

void Matrix::llenarMceros()
{
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            m[i][j] = 0;
        }
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
