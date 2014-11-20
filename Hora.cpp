//
//  Hora.cpp
//  Aeropuerto
//
//  Created by Daniel on 01/11/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#include "Hora.h"

Hora::Hora(){
    hour =0;
    minutes = 0;
}

Hora::Hora(int ñ){
    std::string ho;
    std::string temp;
    std::cin>>ho;
    for(int i = 0;i < 2; i++){
        temp += ho[i];
    }
    hour = atoi(temp.c_str());
    temp = "";
    for (int j = 2; j< 4; j++) {
        temp += ho[j];
    }
    minutes = atoi(temp.c_str());
}

Hora::Hora(std::string ho){
    std::string temp;
    for(int i = 0;i < 2; i++){
        temp += ho[i];
    }
    hour = atoi(temp.c_str());
    
    temp = "";
    for (int j = 2; j< 4; j++) {
        temp += ho[j];
    }
    minutes = atoi(temp.c_str());
    if (minutes > 60){
        minutes = 60;
    }
    if(hour > 24){
        hour = 24;
    }
}

bool Hora::operator<(Hora & h){
    if (this->hour < h.hour) {
        return true;
    }
    else if((this->hour == h.hour) && (this->minutes < h.minutes)){
        return true;
    }
    return false;
}

bool Hora::operator<=(int i){
    if(hour < i){
        return true;
    }
    else if(hour == i){
        return minutes <= i;
    }
    return false;
}

Hora Hora::operator-(int s){
    int m = minutes - s;
    if(m < 0){
        hour--;
        minutes = 60 + m;
    }
    else{
        minutes = m;
    }
    
    return *this;
}

Hora Hora::operator+(int s){
    this->minutes += s;
    if(minutes > 60){
        hour += 1;
        minutes -= 60;
    }
    return *this;
}

std::ostream & operator <<(std::ostream & os, Hora & h){
    if(h.hour < 10){
        os << "0";
    }
    os << h.hour << ":";
    if (h.minutes < 10) {
        os << "0";
    }
    os << h.minutes;
    return os;
}
