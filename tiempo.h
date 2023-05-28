#ifndef TIEMPO_H
#define TIEMPO_H

#include <iostream>

using namespace std;

class Tiempo
{
private:
    unsigned int dia = 0;
    unsigned int hora = 0;
    unsigned int minuto = 0;
    unsigned int segundo = 0;
    char separador = ':';
    int max[4] = {60,60,24,7};
protected:
    char getSeparador() const;
    void setSeparador(char newSeparador);
public:
    Tiempo();
    ~Tiempo();
    void setTiempo(int dias,int horas,int minutos,int segundos,char delimitador);
    void setTiempo(int dias,int horas,int minutos,int segundos);
    string printTiempo();
    string printTiempo(int metodo);
    unsigned int getDia() const;
    void setDia(unsigned int newDia);
    unsigned int getHora() const;
    void setHora(unsigned int newHora);
    unsigned int getMinuto() const;
    void setMinuto(unsigned int newMinuto);
    unsigned int getSegundo() const;
    void setSegundo(unsigned int newSegundo);
};

#endif // TIEMPO_H
