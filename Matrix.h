#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "posicion.h"
#include "memento.h"
#include "fotografo.h"
using namespace std;

class Memento;

class Matrix
{
public:
	int f, c;
	int** m; //matriz principal..
	int** m_pos; //matriz de ceros y unos, inicialmente solo ceros
	Posicion* curr_pos; //coordenadas actuales en la matriz, sobre la que se intenta obtener un grupo a partir de el
	Fotografo* fotografo;
	vector<Posicion> v_p; //para almacenar una lista de coordenadas de un grupo en cierto momento
	stack<Posicion> pila_pos;
	//Matrix(int fil, int col);
	Matrix();
	void crearM(int fil, int col);
	void cargarMfromFile();
	void cpy_m2m(int** pm); //copia contenido
	bool non_block;
	int cont_non_visited;
    void solver();
    void backtrack(int p_x, int p_y, int cont, int* q);
    void colors2Down();
	int buscarCceros();
    void buscarGrupo(int x, int y);
	void moverDerecha(int pos);
    void moverIzquierda(int pos);
    void moverLados();

	void printM();

	Memento* guardar2Memento(); //devuelve un objeto memento que se tomara como paramatero para añadirlo a la lista de mementos, con la fn del fotografo
	void deshacerMemento(Memento* m); //obtiene el ultimo estdo anterior de memento y lo reasigna a los matributos de esta clase
	friend class Memento;
	~Matrix();
};
#endif
