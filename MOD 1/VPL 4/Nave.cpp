#include <iostream>
#include <cmath>
using namespace std;

#include "Nave.hpp"
#include "Ponto2D.hpp"

Nave :: Nave(Ponto2D posicao, double forca){
    _forca = 1;
   energia = 100;
    _posicao = posicao;
    if(forca > 0){
        _forca = forca;
    }
}

void Nave :: mover(double dx, double dy){
    _posicao._x += dx;
    _posicao._y += dy;
}

double Nave :: calcular_distancia(Nave* nave){
    double dx = nave -> _posicao._x - this -> _posicao._x;
    double dy = nave -> _posicao._y - this -> _posicao._y;
    return sqrt(dx*dx + dy*dy);
}

Nave* Nave :: determinar_nave_mais_proxima(Nave** naves, int n){
    int menorDistancia = -1;
    for(int i = 0; i < n; i++){
        if(this -> calcular_distancia(naves[menorDistancia]) > this -> calcular_distancia(naves[i]) && this -> calcular_distancia(naves[i]) != 0){
           menorDistancia = i;
        }
        else if(menorDistancia == -1 && this -> calcular_distancia(naves[i]) == 0){
            menorDistancia += 2;
        }
        
    }
    return naves[menorDistancia];
}

void Nave :: atacar(Nave** naves, int n){
   Nave* naveMaisProx = determinar_nave_mais_proxima(naves, n);
   double d = this -> calcular_distancia(naveMaisProx);
   double dano = (100/d) * _forca;
   if(dano > 30){
       dano = 30;
   }
   naveMaisProx -> energia -= dano;
   if(naveMaisProx -> energia <= 50){
       cout << "Energia baixa!" << endl;
   }
}

void Nave :: imprimir_status(){
    cout << _posicao._x << " " << _posicao._y << " " << energia << endl;
}