//
//  Aviacion
//
//  Created by Daniel on 10/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Aeropuerto.h"

Aeropuerto::Aeropuerto(){
    name = "Vaico";
    capacity = latY = latX = 0;
}

Aeropuerto::Aeropuerto(std::string _name, int _capacity, int _latX,int _latY){
    name = _name;
    capacity = _capacity;
    latX = _latX;
    latY = _latY;
}

int Aeropuerto::getCapacity(){
    return capacity;
}

int Aeropuerto::getLatX(){
    return latX;
}

int Aeropuerto::getLatY(){
    return latY;
}

std::string Aeropuerto::getName(){
    return name;
}

void Aeropuerto::crearDespegue(Avion & a){
    departures.push_back(a);
//    departures.sort();
}

void Aeropuerto::crearLleguada(Avion & a){
    arrivals.push_back(a);
//    arrivals.sort();
}

bool operator <(const Avion a, const Avion b){
    return a < b;
}

void Aeropuerto::imprimirGrafo(std::ostream &os){
    os << "------Aeropuero: " << name << "------"<<std::endl;
}

void Aeropuerto::imprimirGrafoD(std::ostream &os){
    os << "Aeropuero: " << name <<std::endl;
}

std::ostream & operator <<(std::ostream & os, Aeropuerto & a){
    os << "----------Aeropuerto: " << a.name<< "------------" <<std::endl;
    os << "Salidas: "<<std::endl;
    for (auto item:a.departures){
        item.imprimirSalida(os);
        os <<std::endl;
    }
    os << "Llegadas: ";
    for (auto i:a.arrivals){
        i.imprimirLlegada(os);
        os << std::endl;
    }
    return os;
}
