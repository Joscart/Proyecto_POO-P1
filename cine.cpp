#include "cine.h"

const string &Cine::getNombre() const
{
    return nombre;
}

void Cine::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

bool Cine::addBoletos(int peliculaID,int fila, int columna, int horario)
{
    if(peliculaID<=0||peliculaID>numPeliculas)
        return false;

    bool bandera;
    bandera = salas[cartelera[peliculaID-1]->getSalaId()-1]->asignarAsiento(fila,columna);

    if(!bandera)
        return false;

    boletos.push_back(new Boleto);
    boletos[numBoletos]->setBoleto(numBoletos+1, cartelera[peliculaID-1],salas[cartelera[peliculaID-1]->getSalaId()-1],fila,columna,horario);

    numBoletos = boletos.size();
    return true;

}

bool Cine::setPelicula(string titulo, int duracion, bool estreno, int hora, int minutos)
{
    if(hora>=24||minutos>=60)
        return false;
    if(numPeliculas>numSalas)
        return false;

    Tiempo tiempo,horario;
    horario.setTiempo(0,hora,minutos,0);
    tiempo.setTiempo(0,0,duracion,0);

    cartelera.push_back( new Pelicula );
    cartelera[numPeliculas]->setPelicula(numPeliculas+1,titulo,tiempo,estreno,horario);
    cartelera[numPeliculas]->setSalaId(numPeliculas+1);



    numPeliculas++;
    return true;
}

bool Cine::peliculaAddHorario(int id, int hora, int minutos)
{
    if(hora>=24||minutos>=60||id>numPeliculas||id<=0)
        return false;

    Tiempo horario;
    horario.setTiempo(0,hora,minutos,0);


    cartelera[id-1]->addHorario(horario);

    return true;
}

string Cine::getBoletoAsiento(int id)
{
    return boletos[id-1]->getAsiento();
}

string Cine::getBoletoSala(int id)
{
    return to_string(boletos[id-1]->getSala()->getId());
}

string Cine::getBoletoPelicula(int id)
{
    return boletos[id-1]->getPeli()->getTitulo() + " [" + boletos[id-1]->getHorario().printTiempo(2) + "]";
}

float Cine::getBoletoCosto()
{
    return boletos[0]->costoBoleto;
}

int Cine::getBoletoNumBoletos()
{
    return boletos.size();
}

void Cine::eliminarUltimoBoleto()
{
    boletos.pop_back();
}

string Cine::getPeliculaID(int id)
{
    return to_string(cartelera[id-1]->getId());
}

string Cine::getPeliculaNombre(int id)
{
    return cartelera[id-1]->getTitulo();
}

string Cine::getPeliculaEstreno(int id)
{
    return cartelera[id-1]->getEstreno()? "*Estreno*":"";
}

string Cine::getPeliculaHorarios(int id)
{
    string aux;
    vector<Tiempo> auxTiempo = cartelera[id-1]->getHorarios();
    for(int i=0;i<cartelera[id-1]->getNumHorarios();i++){
        aux  += "[" + auxTiempo[i].printTiempo(2) + "] ";
    }
    return aux;
}

string Cine::getPeliculaHorarios(int id, bool numerar)
{
    string aux;
    vector<Tiempo> auxTiempo = cartelera[id-1]->getHorarios();
    if(numerar){
        for(int i=0;i<cartelera[id-1]->getNumHorarios();i++){
            aux  += to_string(i+1) + ") [" + auxTiempo[i].printTiempo(2) + "] \n";
        }
    }else{
        for(int i=0;i<cartelera[id-1]->getNumHorarios();i++){
            aux  += "[" + auxTiempo[i].printTiempo(2) + "] ";
        }
    }
    return aux;
}

int Cine::getPeliculaNumHorarios(int id)
{
    return cartelera[id-1]->getNumHorarios();
}

int Cine::getPeliculaSalaID(int id)
{
    return cartelera[id-1]->getSalaId();
}

string Cine::getSalaID(int id)
{
    return to_string(salas.at(id-1)->getId());
}

//vector<vector<bool>> Cine::getAsientos(int salaID)
//{
//    if(salaID<=0||salaID>numSalas)
//        salaID=1;


//    return salas[salaID-1]->getArr();
//}

bool Cine::getSalaPosAsiento(int salaID, int fila, int columna)
{
    if(salaID<=0||salaID>numSalas)
        return false;
    //salas[cartelera[peliculaID-1]->getSalaId()]->asignarAsiento(fila,columna)

    return salas.at(salaID-1)->getAsiento(fila,columna);
}

int Cine::getSalaAsientoPosFila(int salaID, int fila, int columna)
{
    if(salaID<=0||salaID>numSalas)
        salaID=1;

    return salas.at(salaID-1)->getPosAsientoFila(fila,columna);
}

int Cine::getSalaAsientoPosColumna(int salaID, int fila, int columna)
{
    if(salaID<=0||salaID>numSalas)
        salaID=1;

    return salas.at(salaID-1)->getPosAsientoColumna(fila,columna);
}

int Cine::getAsientosDisponibles(int salaID)
{
    if(salaID<=0||salaID>numSalas)
        salaID=1;

    return salas.at(salaID-1)->getAsientosDisponibles();
}

int Cine::getSalaFilas()
{
    return salas[0]->getNumF();
}

int Cine::getSalaColumnas()
{
    return salas[0]->getNumC();
}

int Cine::getNumSalas() const
{
    return numSalas;
}

void Cine::setNumSalas(int newNumSalas)
{
    numSalas = newNumSalas;
}

int Cine::getNumBoletos() const
{
    return numBoletos;
}

void Cine::setNumBoletos(int newNumBoletos)
{
    numBoletos = newNumBoletos;
}

int Cine::getNumPeliculas() const
{
    return numPeliculas;
}

void Cine::setNumPeliculas(int newNumPeliculas)
{
    numPeliculas = newNumPeliculas;
}

void Cine::dataTest()
{
    setNombre("Cine Local");
    setPelicula("El Rey Leon 1, el despertar",180,false,16,30);
    setPelicula("El Rey Leon 2, un nuevo inicio",180,false,13,30);
    setPelicula("El Rey Leon 3, la caida",200,false,14,00);
    peliculaAddHorario(3,20,30);
    setPelicula("El Rey Leon 4, Renacer",120,true,19,45);
}

Cine::Cine()
{

    for(int i=0;i<numSalas;i++){
        salas.push_back(new Sala());
    }

    for(int i=0;i<numPeliculas;i++){
        cartelera.push_back( new Pelicula() );
    }
}
