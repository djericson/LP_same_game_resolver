#include "memento.h"

Memento::Memento(int** m1, int** mp_mem, int cont_non_visited, int _f, int _c, Posicion* _p)
{
	//asigna memoria..
	m_mem = new int*[_f];
	mpos_mem = new int*[_f];
	for(int i = 0; i < _f; i++){
        m_mem[i] = new int[_c];
        mpos_mem[i] = new int[_c];
	}

	//copia contenido para m_mem y mpos_mem...
	for(int i = 0; i < _f; i++){
        for(int j = 0; j < _c; j++){
			m_mem[i][j] = m1[i][j];
			mpos_mem[i][j] = mp_mem[i][j];
        }
    }

	p = new Posicion(_p->x, _p->y); //crea su espacio y con contenido, para guardar la posicion en la ke esta
	cont_no_visited = cont_non_visited;
}

int** Memento::get_mat()
{
	return m_mem;
}

int** Memento::get_mpos()
{
	return mpos_mem;
}

Posicion* Memento::get_posicion()
{
	return p;
}


Memento::~Memento(){}
