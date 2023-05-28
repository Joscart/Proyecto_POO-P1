#include "sala.h"


int Sala::getNumF()
{
    return numF;
}

int Sala::getNumC()
{
    return numC;
}

bool Sala::asignarAsiento(int fila, int columna)
{
    if((fila<=0||columna<=0)||(fila>numF||columna>numC)){
        return false;
    }

    if(asientos.at(fila-1).at(columna-1).getOcupancia()){
        return false;
    }

    asientos.at(fila-1).at(columna-1).setOcupancia(true);
    return asientos.at(fila-1).at(columna-1).getOcupancia();
}

int Sala::getId() const
{
    return id;
}

void Sala::setId(int newId)
{
    id = newId;
}


int Sala::getPeliculaID() const
{
    return peliculaID;
}

void Sala::setPeliculaID(int newPeliculaID)
{
    peliculaID = newPeliculaID;
}




int Sala::getAsientosDisponibles() const
{
    return asientosDisponibles;
}

bool Sala::getAsiento(int fila, int columna)
{
    if((fila<=0||columna<=0)||(fila>numF||columna>numC)){
        return false;
    }

    return asientos.at(fila-1).at(columna-1).getOcupancia();
}

int Sala::getPosAsientoFila(int fila, int columna)
{
    if((fila<=0||columna<=0)||(fila>numF||columna>numC)){
        return 0;
    }

    return asientos.at(fila-1).at(columna-1).getPosFila();
}

int Sala::getPosAsientoColumna(int fila, int columna)
{
    if((fila<=0||columna<=0)||(fila>numF||columna>numC)){
        return 0;
    }

    return asientos.at(fila-1).at(columna-1).getPosColumna();
}

//vector<vector<bool>> Sala::getArr() const
//{
//    return arr;
//}

Sala::Sala()
{
    vector<Asiento> aux;
    for(int j=0;j<numC;j++){
        aux.push_back(Asiento());
        aux[j].setPosColumna(j+1);
    }
    for(int i=0;i<numF;i++){
        for(int j=0;j<numC;j++){
            aux[j].setPosFila(i+1);
        }
        asientos.push_back(aux);
    }
}

Sala::~Sala()
{

}

int Sala::numAsientos()
{
    return (numF*numC);
}
