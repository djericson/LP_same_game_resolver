#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
    Matrix grid;
    grid.cargarMfromFile();
	cout<<"Matriz Inicial"<<endl;
	grid.printM();
	grid.solver();

	/*
	cout<<"busca grupo en 0, 0"<<endl;
	grid.buscarGrupo(0, 0);


	if(grid.non_block == false){
		grid.printM();
		cout<<"cae de arriba hacia abajo"<<endl;
		grid.colors2Down();
		grid.printM();
		cout<<"mueve hacia lados"<<endl;
		grid.moverLados();
		grid.printM();

	}

	cout<<"busca grupo en 1, 2"<<endl;
	grid.buscarGrupo(1, 2);
    grid.printM();
	cout<<"cae de arriba hacia abajo"<<endl;
	grid.colors2Down();
	grid.printM();
	cout<<"mueve hacia lados"<<endl;
	grid.moverLados();
	grid.printM();
	*/

    //grid.printM();

    return 0;
}
