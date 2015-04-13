#ifndef MATRIX_H
#define MATRIX_H
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

struct Posicion
{
    int x;
    int y;
    Posicion(){};
    Posicion(int _x, int _y){
        x = _x;
        y= _y;
    }

};

class Matrix
{
public:
	int f, c;
	int ** m;
	int ** m_pos;

	vector<Posicion> v_p;
	stack<Posicion> pila_pos;
	//Matrix(int fil, int col);
	Matrix();
	void cargarM(int fil, int col);
	void llenarMceros();

    void solver();
    void backtrack(int p_x, int p_y, int cont, int* q);
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
