//
//  Hora.h
//  TorreDeControl
//
//  Created by Catalina Peralta on 11/1/14.
//  Copyright (c) 2014 Catalina Peralta. All rights reserved.
//

#ifndef __TorreDeControl__Hora__
#define __TorreDeControl__Hora__

#include <iostream>


class Hora
{
public:
    int hour, minutes;
    Hora();
    Hora(std::string);
    Hora(int);
    bool operator<(Hora & h);
    bool operator<=(int i);
    
    Hora operator -(int s);
    Hora operator +(int s);
    friend std::ostream & operator <<(std::ostream & os, Hora & h);
};

#endif /* defined(__TorreDeControl__Hora__) */
