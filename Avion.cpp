//
//  Avion.cpp
//  Aviacion
//
//  Created by Daniel on 10/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Avion.h"

Avion::Avion(){
//    std::cout<<"Número de serie: ";
//    std::cin>>serial_number;
//    std::cout<<"Aerolinea: ";
//    std::cin>>airline;
//    std::cout<<"Aeropuerto origen: ";
//    std::cin>>origin;
//    std::cout<<"Aeropuerto de destino: ";
//    std::cin>>destination;
//    std::cout<<"Hora de salida: ";
//    Hora s(1);
//    salida = s;
}

int Avion::getSerialNumber(){
    return serial_number;
}

std::string Avion::getOrigin(){
    return origin;
}

std::string Avion::getDestination(){
    return destination;
}

Hora Avion::getSalida(){
    return salida;
}

Hora Avion::getVuelo(){
    return vuelo;
}

void Avion::setVuelo(int x1, int y1, int x2, int y2){
    double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    int h = d/10;
    vuelo.hour = h;
    int m = d - (h*10);
    vuelo.minutes = m;
}

Hora Avion::avanzar(int t){
    return vuelo - t;
}

void Avion::setVuelo(Hora h){
    vuelo = h;
}

bool Avion::operator <( Avion & a){
    return this->vuelo < a.vuelo;
}

bool Avion::operator ==(const Avion & a){
    return this->serial_number == a.serial_number;
}

std::ostream & Avion::imprimirLlegada(std::ostream & os){
    os << "Avion numero: " << serial_number << std::endl;
    os << "Aerolinea: " << airline <<std::endl;
    os << "Origen: "<< origin <<" | ";
    if(vuelo <= 0){
        os << "Llego"<<std::endl;
    }
    else{
        os << "LLega en: " << vuelo;
    }
    return os;
}

std::ostream & Avion::imprimirSalida(std::ostream & os){
    os << "Avion numero: " << serial_number << std::endl;
    os << "Aerolinea: " << airline <<std::endl;
    os << "Destino: "<< destination << " | Salda: " << salida;
    return os;
}

void Avion::imprimirGrafo(std::ostream &os){
    os << vuelo;
}

std::ostream & operator <<(std::ostream & os, Avion & a){
    os << "Avion numero: " << a.serial_number << std::endl;
    os << "Aerolinea: " << a.airline <<std::endl;
    os << "Origen: "<< a.origin << "|  Destino: "<<a.destination<<std::endl;
    
    return os;
}
