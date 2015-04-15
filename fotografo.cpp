#include "fotografo.h"

Fotografo::Fotografo(){}

void Fotografo::tomarFoto(Memento* m)
{

	fotos.push_back(m);
}

Memento* Fotografo::obtenerFoto()
{
	fotos.pop_back(); //elimina el ultimo elemento de la lista
	Memento* re = fotos.back(); //obtiene el nuevo ultimo elemento de la lista, que antes era el penultimo
	return re;
}


Fotografo::~Fotografo(){}
