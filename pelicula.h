#ifndef PELICULA_H
#define PELICULA_H

#include "tiempo.h"
#include <vector>

class Pelicula
{
private:
    int id;
    int salaId;
    string titulo;
    Tiempo duracion;
    bool estreno = false;
    vector<Tiempo> horarios;
    int numHorarios = 0;
public:
    Pelicula();
    ~Pelicula();
    void setPelicula(int id,string titulo, Tiempo duracion, bool estreno,Tiempo horario);
    void addHorario(Tiempo horario);
    int getNumHorarios() const;
    int getId() const;
    void setId(int newId);
    const string &getTitulo() const;
    void setTitulo(const string &newTitulo);
    const Tiempo &getDuracion() const;
    void setDuracion(const Tiempo &newDuracion);
    bool getEstreno() const;
    void setEstreno(bool newEstreno);
    const vector<Tiempo> &getHorarios() const;
    void setHorarios(const vector<Tiempo> &newHorarios);
    int getSalaId() const;
    void setSalaId(int newSalaId);
};

#endif // PELICULA_H
