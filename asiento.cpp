#include "asiento.h"

int Asiento::getPosFila() const
{
    return posFila;
}

void Asiento::setPosFila(int newPosFila)
{
    posFila = newPosFila;
}

int Asiento::getPosColumna() const
{
    return posColumna;
}

void Asiento::setPosColumna(int newPosColumna)
{
    posColumna = newPosColumna;
}

bool Asiento::getOcupancia() const
{
    return ocupancia;
}

void Asiento::setOcupancia(bool newOcupancia)
{
    ocupancia = newOcupancia;
}

Asiento::Asiento()
{

}

Asiento::~Asiento()
{

}
