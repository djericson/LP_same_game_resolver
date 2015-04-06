#include <iostream>
#include "matrix.h"

using namespace std;

/* funcion para basarnos en el backtraking,hace exploracion por profuncidad
void Grafo<V,E>::visitar(T_iter vertice)
{
    if(vertice->first.esVisitado) return;
    cout<< (vertice->first).m_dato<<" "<<(vertice->first).m_x<<" "<<(vertice->first).m_y<<"-->";
    V* p = (V*)(&(vertice->first));
    p->esVisitado = true;
    T_iter_arista it = (vertice->second).begin();
    for(;it != (vertice->second).end(); ++ it)
    {
        T_iter destino = m_grafo.find(*((*it)->m_pVertex));
        visitar(destino);
        cout<<"-->"<<p->m_dato<<" "<<p->m_x<<" "<<p->m_y<<"-->";
    }
}
*/

int main()
{


    cout << "Hello world!" << endl;
    Matrix grid;
    grid.cargarM(3,4);
    grid.llenarMceros();

    int m3[3][4]= {{1, 1, 3, 1},
                   {1, 0, 3, 3},
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

    return 0;
}
