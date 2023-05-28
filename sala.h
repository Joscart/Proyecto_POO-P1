#ifndef SALA_H
#define SALA_H

#include <vector>
#include <string>
#include "tiempo.h"
#include "asiento.h"
using namespace std ;


class Sala
{
private:
    int id;
    static const int numF = 5;
    static const int numC = 5;
    vector<vector<Asiento>> asientos;
    int peliculaID;
    //Tiempo horario;
    int asientosDisponibles = numAsientos();

public:
    Sala();
    ~Sala();
    int numAsientos();
    //bool setHorario(int hora, int minutos);

    static int getNumF();
    static int getNumC();
    bool asignarAsiento(int fila, int columna);

    int getId() const;
    void setId(int newId);
    int getPeliculaID() const;
    void setPeliculaID(int newPeliculaID);
    //Tiempo getHorario() const;
    //void setHorario(const Tiempo &newHorario);
    int getAsientosDisponibles() const;
    bool getAsiento(int fila, int columna);

    //test
    int getPosAsientoFila(int fila, int columna);
    int getPosAsientoColumna(int fila, int columna);
    //vector<vector<bool> > getArr() const;
};

#endif // SALA_H
