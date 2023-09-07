#include <iostream>
#include <cmath>

#include "Ponto2D.hpp"

Ponto2D :: Ponto2D(double x, double y){
    _x = x;
    _y = y;
}

double Ponto2D :: calcular_distancia(Ponto2D * ponto){
    return sqrt(pow(ponto ->_x - _x, 2) + pow(ponto ->_y - _y, 2));
}