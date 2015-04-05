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

void Matrix::colors2Down(){
    int m3[3][4];
    m3 = {{0, 1, 3, 1}, {0, 0, 0, 3}, {0, 3, 3, 1}};

    for(int i = 0; i < f; i++){
        //m[i] = m3[i];
        for(int j = 0; j < c; j++){
            m[i][j] = m3[i][j];
        }
    }



    int i = 0;
    for(int j = 0; j < c; j++){
        i = 0;
        if(m[i][j] != 0){
            while (i<f && m[i+1][j] == 0){
                m[i+1][j] = m[i][j];
                m[i][j] = 0;
                i++;
            }
        }
    }

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
