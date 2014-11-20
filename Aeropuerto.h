//
//  Aeropuerto.h
//  Aviacion
//
//  Created by Daniel on 10/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Aviacion__Aeropuerto__
#define __Aviacion__Aeropuerto__

#include <iostream>
#include <list>
#include <map>
#include "Grafo.h"
#include "Avion.h"
#include "Hora.h"

class Aeropuerto{
private:
    int capacity, latX, latY;
    std::string name;
    
public:
    std::list<Avion> departures;
    std::list<Avion> arrivals;
    
    Aeropuerto();
    Aeropuerto(std::string, int, int, int);
    
    int getCapacity();
    int getLatX();
    int getLatY();
    std::string getName();
    
    void crearDespegue(Avion & a);
    void crearLleguada(Avion & a);
    
    void refresh(Hora h, Grafo<Aeropuerto, Avion>*);
    
    friend bool operator <(const Avion a, const Avion b);
    
    void imprimirGrafo(std::ostream & os);
    void imprimirGrafoD(std::ostream & os);
    friend std::ostream & operator <<(std::ostream & os, Aeropuerto & a);
};

#endif /* defined(__Aviacion__Aeropuerto__) */
