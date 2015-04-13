#include "Matrix.h"

/*
Matrix::Matrix(int fil, int col)
{
	f = fil;
	c = col;
	m = new int*[f];
	for(int i = 0; i < f; i++)
		m[i] = new int[c];
}
*/

Matrix::Matrix(){
    f = 0;
    c = 0;
    m = new int*[1];
    m_pos = new int*[1];
}

void Matrix::cargarM(int fil, int col){
    f = fil;
	c = col;
	m = new int*[f];
	m_pos = new int*[f];
	for(int i = 0; i < f; i++){
        m[i] = new int[c];
        m_pos[i] = new int[c];
	}

}

void Matrix::colors2Down(){
    int m3[3][4]= {{0, 1, 3, 1}, {0, 0, 0, 3}, {0, 3, 3, 1}};


    for(int i = 0; i < f; i++){
        //m[i] = m3[i];
        for(int j = 0; j < c; j++){
            m[i][j] = m3[i][j];
        }
    }



    int i = 0;
    for(int j = 0; j < c; j++){
        i = 0;
        if(m[i][j] != 0){
            while (i<f && m[i+1][j] == 0){
                m[i+1][j] = m[i][j];
                m[i][j] = 0;
                i++;
            }
        }
    }

}




void Matrix::llenarMceros()
{
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            m[i][j] = 0;
            m_pos[i][j] = 0;
        }
    }
}


int Matrix::buscarCceros(){
    for(int i = 0; i < c; i++){
        if(m[f-1][i] == 0){
                //cout<<f-1<<" ";
            return i;
        }
    }
    return -1;
}

void Matrix::moverDerecha(int pos){
    //cout<<"c-> "<<c<<" ";
    //cout<<"f-> "<<f<<" ";
    int tmp = pos;
    for(int i = 0; i < f; i++){
        for(; pos < c - 1; pos ++){
            m[i][pos] = m[i][pos + 1];
            //cout<<" "<<m[i][pos]<<" "<<"pos "<<pos;
        }
        //cout<<"posD "<<pos;
        m[i][pos] = -2; //esto se debe de cambiar al valor de 0
        pos = tmp;
        //cout<<endl<<"tmp "<<tmp;
        //cout<<endl;
        //printM();
        //cout<<endl;
    }

}

void Matrix::moverIzquierda(int pos){

    for(int i = 0; i < f; i++){
        for(int j = pos; j >0; j--){
            m[i][j]= m[i][j - 1];
        }
        //cout<< endl;
        m[i][0] = -2;

    }
    //printM();
}

void Matrix::moverLados(){


    int m3[3][4]= {{1, 1, 3, 1},
                   {1, 0, 0, 3},
                   {1, 3, 3, 1}};


    for(int i = 0; i < f; i++){
        //m[i] = m3[i];
        for(int j = 0; j < c; j++){
            m[i][j] = m3[i][j];
        }
    }


    int pos = 0;
    pos = buscarCceros();
    int med = f / 2;



    for(int i = 0; i < c; i++){
        pos=buscarCceros();
        if(pos == -1){
            break;
        }
        if(pos >= med){
            moverDerecha(pos);
        }
        else{
            moverIzquierda(pos);
        }
    }



}

void Matrix::buscarGrupo(int x, int y){

    if(((x >= 0) && (x < f)) && ((y >= 0) && (y < c))){
        if(m_pos[x][y] == 1) return;
        int conte = m[x][y];
        m_pos[x][y] = 1;
        //if(m_pos[x][y] == 1)
        //    m[x][y] = 0;
        if((x + 1 < f) && (m[x + 1][y] == conte)){
            //m[x + 1][y] = 0;
            v_p.push_back(Posicion(x + 1, y) );
            pila_pos.push(Posicion(x + 1, y) );
            buscarGrupo(x + 1, y);
        }
        if((x - 1 >= 0) && (m[x - 1][y] == conte)){
            //m[x -1][y] = 0;
            v_p.push_back(Posicion(x - 1, y) );
            pila_pos.push(Posicion(x - 1, y) );
            buscarGrupo(x - 1, y);
        }
        if((y + 1 < c) && (m[x][y + 1] == conte)){
            //m[x][y + 1] = 0;
            v_p.push_back(Posicion(x, y + 1) );
            pila_pos.push(Posicion(x, y + 1) );

            buscarGrupo(x, y + 1);
        }
        if((y - 1 >= 0) && (m[x][y - 1] == conte)){
            //m[x][y - 1] = 0;
            v_p.push_back(Posicion(x, y - 1) );
            pila_pos.push(Posicion(x, y - 1) );
            buscarGrupo(x, y - 1);
        }

    }

    while(pila_pos.empty() == 0){
        Posicion pos_tmp = pila_pos.top();
        m[pos_tmp.x][pos_tmp.y] = 0;
        pila_pos.pop();
    }

    return;
}

void Matrix::solver(){
	int posIni = 0;
	int pos_x = posIni;
	int pos_y = posIni;
	int nro_despl = 2;
	m_pos[posIni][posIni] = 1;
	int q;

	backtrack(pos_x, pos_y, nro_despl, &q);
	printM();

}

void Matrix::backtrack(int px, int py, int cont, int *q)
{
	printM();
	int x, y, e;
	//hay_solucion = 0;
	*q = 0;
	//e = 0;
	do{
	    int x, y;

	    for(int i = 0; i < f; i++){
            for(int j = 0;j < c; j++){
                if(m_pos[i][j] == 0){
                    x = i;
                    y = j;
                    break;
                }
            }
        }

	    buscarGrupo(x, y);
	    colors2Down();
	    moverLados();

		if(x >= 0 && x < f && y>= 0 &&  y < c ){
			if(m[x][y]==0){
				m[x][y] = cont;
				if(cont < f*c){

					backtrack(x, y, cont+1, q);
					if (!*q/*hay_solucion==0*/){

						//restaurar ultimo grupo de pos. cambiados en mpos a 0;
                    }
				}
				else
					*q = 1;//hay_solucion = 1;
			}
		}
		e++;
	}
	while(/*hay_solucion==0*/ !*q && e<f);
}

void Matrix::printM()
{
    cout<<"Matriz de Valores";

	for(int i = 0; i < f; i++)
	{
		cout<<endl;
		for(int j = 0;j < c; j++)
			cout<<m[i][j]<<'\t';
	}
	cout<<endl<<endl;

	cout<<"Matriz de Posiciones";

	for(int i = 0; i < f; i++)
	{
		cout<<endl;
		for(int j = 0;j < c; j++)
			cout<<m_pos[i][j]<<'\t';
	}
	cout<<endl;
}

Matrix::~Matrix(){}
