//
//  Avion.h
//  Aviacion
//
//  Created by Daniel on 10/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Aviacion__Avion__
#define __Aviacion__Avion__

#include <iostream>
#include <math.h>
#include "Hora.h"

class Avion{
private:
    std::string origin, destination, airline;
    int serial_number;
public:
    Hora salida, vuelo;
    Avion();
    Avion(int _serial, std::string _origin, std::string _destination, std::string _airline, std::string _salida):serial_number(_serial), origin(_origin), destination(_destination), airline(_airline), salida(Hora(_salida)){};
    
    int getSerialNumber();
    std::string getOrigin();
    std::string getDestination();
    Hora getSalida();
    Hora getVuelo();
    void setVuelo(Hora h);
    
    Hora avanzar(int);
    
    void setVuelo(int x1, int y1, int x2, int y2);
    
    bool operator <( Avion & a);
    bool operator ==(const Avion & a);
    
    std::ostream & imprimirSalida(std::ostream & os);
    std::ostream & imprimirLlegada(std::ostream & os);
    void imprimirGrafo(std::ostream & os);
    friend std::ostream & operator <<(std::ostream & os, Avion & a);
};

#endif /* defined(__Aviacion__Avion__) */
