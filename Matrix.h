#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix
{
public:
	int f, c;
	int ** m;
	int ** m_pos;

	//Matrix(int fil, int col);
	Matrix();
	void cargarM(int fil, int col);
	void llenarMceros();

    int buscarCceros();
    void moverDerecha(int pos);
    void moverIzquierda(int pos);
    void moverLados();

    void buscarGrupo(int x, int y);

	void colors2Down();

	void printM();

	~Matrix();
};
#endif
