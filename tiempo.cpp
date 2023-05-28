#include "tiempo.h"

Tiempo::Tiempo()
{

}

Tiempo::~Tiempo()
{

}

void Tiempo::setTiempo(int dias, int horas, int minutos, int segundos, char delimitador)
{
    if(dias<0||horas<0||minutos<0||segundos<0)
        return;
    int aux = 0;
    while(segundos>max[0]){
        segundos -= max[0];
        aux++;
    }
    minutos += aux;
    aux = 0;
    while(minutos>max[1]){
        minutos -= max[1];
        aux++;
    }
    horas += aux;
    aux = 0;
    while(horas>max[2]){
        horas -= max[2];
        aux++;
    }
    dias += aux;

    segundo = segundos;
    minuto = minutos;
    hora = horas;
    dia = dias;
    separador = delimitador;
}

void Tiempo::setTiempo(int dias, int horas, int minutos, int segundos)
{
    if(dias<0||horas<0||minutos<0||segundos<0)
        return;
    int aux = 0;
    while(segundos>=max[0]){
        segundos -= max[0];
        aux++;
    }
    minutos += aux;
    aux = 0;
    while(minutos>=max[1]){
        minutos -= max[1];
        aux++;
    }
    horas += aux;
    aux = 0;
    while(horas>=max[2]){
        horas -= max[2];
        aux++;
    }
    dias += aux;

    segundo = segundos;
    minuto = minutos;
    hora = horas;
    dia = dias;
}

string Tiempo::printTiempo()
{
    bool print = false;
    string aux = "";
    if(dia!=0)
        print = true;

    if(print)
        aux += to_string(dia)+separador;

    if(!print)
        if(hora!=0)
            print = true;

    if(print)
        aux += to_string(hora)+separador;

    if(!print)
        if(minuto!=0)
            print = true;

    if(print)
        aux += to_string(minuto)+separador;

    if(!print)
        if(segundo!=0)
            print = true;

    if(print)
        aux += to_string(segundo);

    return aux;
}

string Tiempo::printTiempo(int metodo)
{
    bool print = false;
    string aux = "";
    int num = 0;

    switch(metodo){
    case 1:
        //hh/mm/ss
        num=(dia*max[2])+hora;
        if(num!=0)
            print = true;

        if(print)
            aux += to_string(num)+separador;

        if(!print)
            if(minuto!=0)
                print = true;

        if(print)
            aux += to_string(minuto)+separador;

        if(!print)
            if(segundo!=0)
                print = true;

        if(print)
            aux += to_string(segundo);

        break;
    case 2:
        //hh/mm

        if(hora==0){
            aux += to_string(hora)+"0:";
        }else{
            aux += to_string(hora)+":";
        }
        if(minuto==0){
            aux += to_string(minuto) + "0";
        }else{
            aux += to_string(minuto);
        }

        break;
    case 3:
        //Dias, horas.
        print = true;

        if(print)
            aux += to_string(dia)+" Dias";

        if(hora!=0)
            aux += ", "+to_string(hora)+" Horas.";

        break;
    case 4:
        //mm/ss
        num=(dia*(max[2]*max[1]))+(hora*max[1])+minuto;
        if(num!=0)
            print = true;

        if(print)
            aux += to_string(num)+separador;

        if(!print)
            if(segundo!=0)
                print = true;

        if(print)
            aux += to_string(segundo);

        break;
    case 5:
        // Min.
        num=(dia*(max[2]*max[1]))+(hora*max[1])+minuto;
        if(num!=0)
            print = true;

        if(print)
            aux += to_string(num)+" Min";

        break;
    case 6:
        // Seg.
        num=(dia*(max[2]*max[1]*max[0]))+(hora*(max[1]*max[0]))+(minuto*max[0])+segundo;
        if(num!=0)
            print = true;

        if(print)
            aux += to_string(num)+" Seg";

        break;
    default:
        if(dia!=0)
            print = true;

        if(print)
            aux += to_string(dia)+separador;

        if(!print)
            if(hora!=0)
                print = true;

        if(print)
            aux += to_string(hora)+separador;

        if(!print)
            if(minuto!=0)
                print = true;

        if(print)
            aux += to_string(minuto)+separador;

        if(!print)
            if(segundo!=0)
                print = true;

        if(print)
            aux += to_string(segundo);
    }

    return aux;
}

unsigned int Tiempo::getDia() const
{
    return dia;
}

void Tiempo::setDia(unsigned int newDia)
{
    dia = newDia;
}

unsigned int Tiempo::getHora() const
{
    return hora;
}

void Tiempo::setHora(unsigned int newHora)
{
    hora = newHora;
}

unsigned int Tiempo::getMinuto() const
{
    return minuto;
}

void Tiempo::setMinuto(unsigned int newMinuto)
{
    minuto = newMinuto;
}

unsigned int Tiempo::getSegundo() const
{
    return segundo;
}

void Tiempo::setSegundo(unsigned int newSegundo)
{
    segundo = newSegundo;
}

char Tiempo::getSeparador() const
{
    return separador;
}

void Tiempo::setSeparador(char newSeparador)
{
    separador = newSeparador;
}
