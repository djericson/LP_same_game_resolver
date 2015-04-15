#ifndef MEMENTO_H
#define MEMENTO_H
#include "posicion.h"

class Memento
{
public:
	int** m_mem; //la matriz principal
	int** mpos_mem; //la matriz de posiciones
	Posicion* p;
	int cont_no_visited;
	Memento(int** m1, int** mp_mem, int cont_non_visited, int _f, int _c, Posicion* p);
	int** get_mat();
	int** get_mpos();
	Posicion* get_posicion();

	~Memento();
};

#endif
