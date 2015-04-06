#include <iostream>
#include "matrix.h"

using namespace std;


int main()
{


    cout << "Hello world!" << endl;
    Matrix grid;
    grid.cargarM(3,4);
    grid.llenarMceros();

    int m3[3][4]= {{1, 1, 3, 1},
                   {1, 0, 2, 3},
                   {1, 3, 3, 1}};


    for(int i = 0; i < 3; i++){
        //m[i] = m3[i];
        for(int j = 0; j < 4; j++){
            grid.m[i][j] = m3[i][j];
        }
    }

    //grid.colors2Down();
    //grid.moverLados();
    grid.printM();
    grid.buscarGrupo(1,2);
    grid.printM();

    //grid.solver();
    //grid.printM();

    return 0;
}
