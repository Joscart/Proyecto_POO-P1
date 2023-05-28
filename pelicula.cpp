#include "pelicula.h"

int Pelicula::getNumHorarios() const
{
    return numHorarios;
}

int Pelicula::getId() const
{
    return id;
}

void Pelicula::setId(int newId)
{
    id = newId;
}

const string &Pelicula::getTitulo() const
{
    return titulo;
}

void Pelicula::setTitulo(const string &newTitulo)
{
    titulo = newTitulo;
}

const Tiempo &Pelicula::getDuracion() const
{
    return duracion;
}

void Pelicula::setDuracion(const Tiempo &newDuracion)
{
    duracion = newDuracion;
}

bool Pelicula::getEstreno() const
{
    return estreno;
}

void Pelicula::setEstreno(bool newEstreno)
{
    estreno = newEstreno;
}

const vector<Tiempo> &Pelicula::getHorarios() const
{
    return horarios;
}

void Pelicula::setHorarios(const vector<Tiempo> &newHorarios)
{
    horarios = newHorarios;
}

int Pelicula::getSalaId() const
{
    return salaId;
}

void Pelicula::setSalaId(int newSalaId)
{
    salaId = newSalaId;
}

Pelicula::Pelicula()
{

}

Pelicula::~Pelicula()
{

}

void Pelicula::setPelicula(int id, string titulo, Tiempo duracion, bool estreno, Tiempo horario)
{
    this->id = id;
    this->titulo = titulo;
    this->duracion = duracion;
    this->estreno = estreno;
    this->horarios.push_back(horario);
    numHorarios = horarios.size();
}

void Pelicula::addHorario(Tiempo horario)
{
    this->horarios.push_back(horario);
    numHorarios = horarios.size();
}
