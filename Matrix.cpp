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


    int m3[3][4]= {{0, 1, 3, 1}, {0, 0, 0, 3}, {0, 3, 3, 1}};


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

void Matrix::printM()
{
	for(int i = 0; i < f; i++)
	{
		cout<<endl;
		for(int j = 0;j < c; j++)
			cout<<m[i][j]<<'\t';
	}
	cout<<endl;
}

Matrix::~Matrix(){}
