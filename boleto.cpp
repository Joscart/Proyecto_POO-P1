#include "boleto.h"

int Boleto::getFila() const
{
    return fila;
}

int Boleto::getColumna() const
{
    return columna;
}



Sala *Boleto::getSala() const
{
    return sala;
}

Pelicula *Boleto::getPeli() const
{
    return peli;
}

const string &Boleto::getAsiento() const
{
    return asiento;
}

int Boleto::getId() const
{
    return id;
}

void Boleto::setId(int newId)
{
    id = newId;
}

Tiempo Boleto::getHorario() const
{
    return horario;
}

Boleto::Boleto()
{
    sala = new Sala();
    peli = new Pelicula();
}

Boleto::~Boleto()
{

}

void Boleto::setBoleto(int id, Pelicula *peli, Sala *sala, int fila, int columna, int horario)
{
    this->id = id;
    this->peli = peli;
    this->sala = sala;
    this->columna = columna;
    this->fila = fila;

    this->horario = peli->getHorarios()[horario-1];

    sala->setId(peli->getSalaId());

    char aux;

    switch(fila){
    case 1: aux = 'A';break;
    case 2: aux = 'B';break;
    case 3: aux = 'C';break;
    case 4: aux = 'D';break;
    case 5: aux = 'E';break;
    default:aux = ' ';
    }
    asiento = aux+to_string(columna);
}
