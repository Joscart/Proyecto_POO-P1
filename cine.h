#ifndef CINE_H
#define CINE_H

#include <vector>
#include "sala.h"
#include "pelicula.h"
#include "boleto.h"
#include "tiempo.h"


class Cine
{
private:
    string nombre = "Cine";
    int numPeliculas = 0;
    int numSalas = 5;
    int numBoletos = 0;

    vector<Pelicula*> cartelera;
    vector<Sala*> salas;
    vector<Boleto*> boletos;
public:
    Cine();
    const string &getNombre() const;
    void setNombre(const string &newNombre);
    bool addBoletos(int peliculaID, int fila, int columna, int horario);

    bool setPelicula(string titulo, int duracion, bool estreno, int hora, int minutos);
    bool peliculaAddHorario(int id, int hora, int minutos);



    /*Retorno de datos String(para imprimir)*///Definir strings******
    string getBoletoAsiento(int id);
    string getBoletoSala(int id);
    string getBoletoPelicula(int id);
    float getBoletoCosto();
    int getBoletoNumBoletos();
    void eliminarUltimoBoleto();

    string getPeliculaID(int id);
    string getPeliculaNombre(int id);
    string getPeliculaEstreno(int id);
    string getPeliculaHorarios(int id);
    string getPeliculaHorarios(int id,bool numerar);
    int getPeliculaNumHorarios(int id);
    int getPeliculaSalaID(int id);

    string getSalaID(int id);
    //vector<vector<bool> > getAsientos(int salaID);
    bool getSalaPosAsiento(int salaID, int fila, int columna);
    //test
    int getSalaAsientoPosFila(int salaID, int fila, int columna);
    int getSalaAsientoPosColumna(int salaID, int fila, int columna);
    int getAsientosDisponibles(int salaID);
    int getSalaFilas();
    int getSalaColumnas();



    int getNumSalas() const;
    void setNumSalas(int newNumSalas);
    int getNumBoletos() const;
    void setNumBoletos(int newNumBoletos);
    int getNumPeliculas() const;
    void setNumPeliculas(int newNumPeliculas);
    void dataTest();
};

#endif // CINE_H
