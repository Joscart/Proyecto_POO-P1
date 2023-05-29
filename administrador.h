#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string.h>
#include "cine.h"

using namespace std;

class Administrador
{
private:
    Cine* cine;
public:
    Administrador();
    void dataTest();
    void Instrucciones();
    void mostrarCartelera();
    void venderBoleto();
    void factura();
    void imprimirTicket(int id);
    void mostrarAsientos(int salaId);
    bool validarNumero(const string &dato);
};

#endif // ADMINISTRADOR_H
