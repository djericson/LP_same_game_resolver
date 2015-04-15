#ifndef POSICION_H
#define POSICION_H

class Posicion
{
public:
    int x;
    int y;
    Posicion(){
		x = y = 0;
	}
    Posicion(int _x, int _y){
        x = _x;
        y= _y;
    }

};

#endif
