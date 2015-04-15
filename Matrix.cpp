#include "matrix.h"

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
	curr_pos = new Posicion();
	fotografo = new Fotografo();
	non_block = true;
	cont_non_visited = f*c;
}

void Matrix::crearM(int fil, int col){
    f = fil;
	c = col;
	m = new int*[f];
	m_pos = new int*[f];
	for(int i = 0; i < f; i++){
        m[i] = new int[c];
        m_pos[i] = new int[c];
	}
	curr_pos = new Posicion();
}

void Matrix::cargarMfromFile()
{
	const int _f = 3, _c = 4;

	crearM(_f, _c);

	int m2[_f][_c] = {{1, 1, 3, 1},
                   {1, 0, 3, 3},
                   {1, 3, 3, 1}};

	/*
	int m2[_f][_c] = {{2, 1, 3, 1},
					{2, 2, 2, 3},
					{2, 3, 3, 1}};
	*/
    for(int i = 0; i < _f; i++){
        for(int j = 0; j < _c; j++){
            m[i][j] = m2[i][j];
            m_pos[i][j] = 0;
        }
    }
}

void Matrix::colors2Down(){

	for(int i = 0; i < f-1; i++){
        for(int j = 0; j < c; j++){
			if(m[i+1][j] == 0 && m[i+1][j] != m[i][j]){
				m[i+1][j] = m[i][j];
                m[i][j] = 0;
			}
        }
    }
}

void Matrix::cpy_m2m(int** m2)
{
	for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
			m[i][j] = m2[i][j];
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
        //m[i][pos] = -2; //esto se debe de cambiar al valor de 0
		m[i][pos] = 0;
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
        //m[i][0] = -2;
		m[i][0] = 0;

    }
    //printM();
}

void Matrix::moverLados(){

	/*
    int m3[3][4]= {{1, 1, 3, 1},
                   {1, 0, 0, 3},
                   {1, 3, 3, 1}};

    for(int i = 0; i < f; i++){
        //m[i] = m3[i];
        for(int j = 0; j < c; j++){
            m[i][j] = m3[i][j];
        }
    }
	*/

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
		cont_non_visited++;
        //if(m_pos[x][y] == 1)
        //    m[x][y] = 0;
        if((x + 1 < f) && (m[x + 1][y] == conte)){
            //m[x + 1][y] = 0;
			non_block = false;
            v_p.push_back(Posicion(x + 1, y) );
            pila_pos.push(Posicion(x + 1, y) );
            buscarGrupo(x + 1, y);
        }
        if((x - 1 >= 0) && (m[x - 1][y] == conte)){
            //m[x -1][y] = 0;
			non_block = false;
            v_p.push_back(Posicion(x - 1, y) );
            pila_pos.push(Posicion(x - 1, y) );
            buscarGrupo(x - 1, y);
        }
        if((y + 1 < c) && (m[x][y + 1] == conte)){
            //m[x][y + 1] = 0;
			non_block = false;
            v_p.push_back(Posicion(x, y + 1) );
            pila_pos.push(Posicion(x, y + 1) );

            buscarGrupo(x, y + 1);
        }
        if((y - 1 >= 0) && (m[x][y - 1] == conte)){
            //m[x][y - 1] = 0;
			non_block = false;
            v_p.push_back(Posicion(x, y - 1) );
            pila_pos.push(Posicion(x, y - 1) );
            buscarGrupo(x, y - 1);
        }
		if(non_block)
			m_pos[x][y] = 0;
			cont_non_visited--;
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
	int nro_despl = 0;
	int q; //para indicar en las etapas de la recursion si hay solucion o no, es decir, no puede avanzar mas la recursion
	cout<<"Matriz Inicial:\n";
	printM();
	fotografo->tomarFoto(guardar2Memento()); //toma foto de la matriz inicial
	backtrack(pos_x, pos_y, nro_despl, &q);
	//printM();
}

void Matrix::backtrack(int px, int py, int cont, int *q)
{
	//printM();
	int x = 0, y = 0;
	//hay_solucion = 0;
	*q = 0;

	do{
		/*
	    for(int i = 0; i < f; i++){
            for(int j = 0;j < c; j++){
                if(m_pos[i][j] == 0){
                    x = i;
                    y = j;
                    break;
                }
            }
			break;
        }
		*/
		do{
			x = rand()%f;
			y = rand()%c;
		}
		while(m_pos[x][y] != 0);

	    buscarGrupo(x, y);
		if(non_block == false){
			colors2Down();
			moverLados();
			fotografo->tomarFoto(guardar2Memento());
			printM();
		}

		//if(x >= 0 && x < f && y>= 0 &&  y < c ){
			if(m_pos[x][y] == 0){
				//m[x][y] = cont;
				if(cont < f*c || cont_non_visited >0){

					backtrack(x, y, cont+1, q);
					if (!*q/*hay_solucion==0*/){
						//restaurar al estado anterior:
						deshacerMemento(fotografo->obtenerFoto());

                    }
					else{
						cout<<"o.o"<<endl;
						return;
					}
				}
				else
					*q = 1;//hay_solucion = 1;
			}
		//}
	}
	while(/*hay_solucion==0*/ !*q);
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
	cout<<endl<<endl;
}

Memento* Matrix::guardar2Memento()
{						//(int** m1, int** mp_mem, int _f, int _c, Posicion* p);
	return new Memento(m, m_pos,cont_non_visited, f,c, new Posicion(curr_pos->x, curr_pos->y) );
}

void Matrix::deshacerMemento(Memento* mem)
{
	m = mem->get_mat();
	m_pos= mem->get_mpos();

	Posicion* tmp_obj_p = mem->get_posicion();
	curr_pos->x = tmp_obj_p->x;
	curr_pos->y = tmp_obj_p->y;
	cont_non_visited = mem->cont_no_visited;
}

Matrix::~Matrix(){}
