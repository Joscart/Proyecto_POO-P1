#ifndef BOLETO_H
#define BOLETO_H

#include "pelicula.h"
#include "sala.h"
#include "tiempo.h"


class Boleto
{
private:
    int id;
    string asiento;
    Pelicula *peli;
    Sala *sala;
    Tiempo horario;
    int fila;
    int columna;
public:
    const float costoBoleto = 3.15;
    Boleto();
    ~Boleto();
    void setBoleto(int id, Pelicula *peli, Sala *sala, int fila, int columna, int horario);
    int getFila() const;
    int getColumna() const;


    Sala *getSala() const;
    Pelicula *getPeli() const;
    const string &getAsiento() const;
    int getId() const;
    void setId(int newId);
    Tiempo getHorario() const;
};

#endif // BOLETO_H
