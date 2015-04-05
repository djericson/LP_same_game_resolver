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
    grid.colors2Down();
    grid.printM();

    return 0;
}
