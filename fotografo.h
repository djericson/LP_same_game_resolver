#ifndef FOTOGRAFO_H
#define FOTOGRAFO_H

#include <iostream>
#include <list>
#include "memento.h"

using namespace std;
class Memento;

class Fotografo
{
public:

	list<Memento*> fotos;
	//list<Memento*> fd;
    Fotografo();
	void tomarFoto(Memento* m);
	Memento* obtenerFoto();
	~Fotografo();


};

#endif
