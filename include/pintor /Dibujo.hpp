#pragma once
#include<string>
#include<list>
#include<Vector.hpp>
using namespace std;

class Dibujo{
    private:
        list<string> lineas;
    public:
            Dibujo () {}
            ~Dibujo() {}
            void AgregarLinea(string linea){
                this->lineas.push_back(linea);
            }
    list<string> ObtenerLineas(){
        return this->lineas;
    }
}