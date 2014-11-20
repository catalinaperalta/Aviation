//
//  main.cpp
//  Aviacion
//
//  Created by Daniel on 10/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include <iostream>
#include <thread>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "Aeropuerto.h"
#include "Grafo.h"

Hora local("0000");
Hora max ("0200");

void refresh(std::map<int, Aeropuerto*> & m, Grafo<Aeropuerto*, Avion>* g, int tiem);

int main(int argc, const char * argv[])
{
    int opcion = 10;
    int menu = 0;
    bool salir = false, op = false;
    
    std::map<int, Aeropuerto*> aeropuertos;
    
    Aeropuerto* jfk = new Aeropuerto("JFK", 30, 20, 10);
    Aeropuerto* bj = new Aeropuerto("BJ", 20, 30, 5);
    Aeropuerto* tol = new Aeropuerto("Tol", 10, 25,40);
    
    aeropuertos[100] = jfk;
    aeropuertos[101] = bj;
    aeropuertos[102] = tol;
    
    Grafo<Aeropuerto*, Avion>* mundo = new Grafo<Aeropuerto*, Avion>;
    
    mundo->insertarVertice(jfk);
    mundo->insertarVertice(bj);
    mundo->insertarVertice(tol);
    
    Avion a(10, "JFK", "BJ", "Mexicana", "0010");
    Avion b(15, "BJ", "Tol", "AeroMex", "0015");
    Avion c(16, "Tol", "BJ", "Luftansa", "0016");
    Avion d(25, "JFK", "Tol", "Mexicana", "0025");
    Avion e(30, "BJ", "JFK", "AeroMexico", "0030");
    
    jfk->crearDespegue(a);
    jfk->crearDespegue(d);
    
    bj->crearDespegue(b);
    bj->crearDespegue(e);
    
    tol->crearDespegue(c);
    
    while (local < max)
    {
        
        int avance = 15;
        
        time_t startTime = time(0); //Start timer
        double secondsPassed;
        
        int aeropuerto;
        std::cout<< "Hora local: " <<local<<std::endl;
        
        std::cout<<"Bienvenido a la Torre de Control!\n";
        std::cout<<"Desea ingresar a:  1. Agregar vuelos. 2. Ver vuelos globales. 0. Salir\n";
        std::cin>>menu;
        
        switch (menu)
        {
            case 1:
            {
                int serial;
                std::string ser, origen, dest, airline, hour;
                std::cout<<"Numero serial>>";
                std::cin>>ser;
            
                for(int i = 0; i<ser.length(); i++)
                {
                    if(isdigit(ser[i]))
                    {
                        
                    }
                    else
                    {
                        std::cout<<"Numero serial invalido.\n";
                        break;
                    }
                }
                
                serial = atoi(ser.c_str());
                
                std::cout<<"Aeropuerto de origen(1. JFK 2. BJ 3. Tol)>>";
                std::cin>>origen;
                
                if(origen == "JFK" || origen == "BJ" || origen == "Tol")
                {
                }
                else
                {
                    std::cout<<"No es una opcion valida.\n";
                    break;
                }
                std::cout<<"Aeropuerto de destino(1. JFK 2. BJ 3. Tol)>>";
                std::cin>>dest;
                if(dest == "JFK" || dest == "BJ" || dest == "Tol")
                {
                }
                else
                {
                    std::cout<<"No es una opcion valida.\n";
                    break;
                }
                
                std::cout<<"Aerolinea>>";
                std::cin>>airline;
                std::cout<<"Hora de salida>>";
                std::cin>>hour;
                
                Avion a(serial, origen, dest, airline, hour);
                
                if(origen == "JFK")
                {
                    jfk->crearDespegue(a);
                }
                else if(origen == "BJ")
                {
                    bj->crearDespegue(a);
                }
                else if(origen == "Tol")
                {
                    tol->crearDespegue(a);
                }
            }
                break;
            case 2:
            {
                std::cout<<"Bienvenido a la Torre de Control del mundo!\n Puede realizar las siguientes acciones.\n 1. Visualizar los vuelos mundiales entre los aeropuertos.\n 2. Visualizar un aeropuerto.\n 3. Cerrar Aeropuerto.\n 0. Salir\n";
                
                std::cin>>opcion;
                
                switch (opcion)
                {
                    case 1:
                        std::cout<<*mundo;
                        break;
                    case 2:
                    {
                        std::cout<<"ID del aeropuerto que quisiera visualizar: \n";
                        std::cin>>aeropuerto;
                        
                        if(aeropuertos[aeropuerto])
                        {
                            std::cout<<*aeropuertos[aeropuerto];
                        }
                        else
                        {
                            std::cout<<"No existe un aeropuerto con ese ID.\n";
                        }
                    }
                        break;
                    case 3:
                    {
                        int aero;
                        Aeropuerto * cerrado = new Aeropuerto();
                        Aeropuerto * buscar = new Aeropuerto();
                        
                        std::cout<<" ID de aeropuerto a cerrar>>";
                        std::cin>>aero;
                        
                        //                        Aeropuerto * buscar = new Aeropuerto(aero, 0, 0, 0);
                        //                        NodoV<Aeropuerto*, Avion> * temp = mundo->buscarVertice(buscar);
                        //                        Aeropuerto * cerrado = temp->getInfo();
                        if(aeropuertos[aero])
                        {
                            cerrado = aeropuertos[aero];
                            
                        }
                        std::queue<Avion> espera;
                        
                        cerrado->departures.clear();
                        
                        for(auto i : cerrado->arrivals)
                        {
                            espera.push(i);
                        }
                        
                        //cerrado->Aeropuerto::arrivals.clear();
                        
                        std::cout<<"Aeropuerto al que serán redireccionados los vuelos>>";
                        std::cin>>aero;
                        
                        if(aeropuertos[aero])
                        {
                            buscar->arrivals = aeropuertos[aero]->arrivals;
                        }
                        else
                        {
                            std::cout<<"No se encontro el aeropuerto. No se logro el desvio.\n";
                            break;
                        }
                        
                        cerrado->arrivals.clear();
                        //cerrado = mundo->buscarVertice(buscar1)->getInfo();
                        
                        while(!espera.empty())
                        {
                            buscar->Aeropuerto::arrivals.push_back(espera.front());
                            espera.pop();
                        }
                        
                    }
                        break;
                    case 0:
                        break;
                        
                    default:
                        
                        break;
                }
                
            }
                
                break;
            case 0:
                salir = true;
                max = local;
                break;
            default:
                std::cout<<"No es una opcion valida.\n";
                break;
        }
        
        std::string p;
        std::cin>>p;
        
        time_t end = time(0);
        secondsPassed = difftime(end, startTime);
        avance = secondsPassed;
        local = local + avance;
        refresh(aeropuertos, mundo, secondsPassed);
        std::cout<<"\033[0J";
    }
    
    return 0;
}

void refresh(std::map<int, Aeropuerto*> & m, Grafo<Aeropuerto*, Avion>* g, int tiem)
{
    
    NodoV<Aeropuerto*, Avion>* temp;
    temp = g->getVertices();
    while(temp){
        NodoA<Avion, Aeropuerto*>* _arista;
        _arista = temp->getAristas();
        while(_arista){
            _arista->getInfo().setVuelo(_arista->getInfo().getVuelo() - tiem);
            if(_arista->getInfo().getVuelo() <= 0){
                _arista = temp->changeArista(_arista);
            }
            else{
                _arista = _arista->getNext();
            }
        }
        temp = temp->getNext();
    }
    
    for (auto i:m){
        for(auto j:i.second->departures){
            if(j.salida < local){
                Aeropuerto * destino = nullptr;
                for (auto q:m){
                    //                    std::cout<<"entro"<<std::endl;
                    if(q.second->getName() == j.getDestination()){
                        destino = q.second;
                    }
                }
                if (destino != nullptr){
                    //                    std::cout<<"se inserta un avion en el grafo: "<< j<<std::endl;
                    j.setVuelo(i.second->getLatX(), i.second->getLatY(), destino->getLatX() ,destino->getLatY());
                    g->insertarArista(j, i.second, destino);
                    
                }
                i.second->departures.remove(j);
            }
        }
    }
}
