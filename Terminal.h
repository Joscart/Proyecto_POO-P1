#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>

using namespace std;

//Clear screen and system pause for windows and linux
#ifdef _WIN32
#include<windows.h>
#endif

void limpiar_pantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Pausar()
{
#ifdef _WIN32
    system("pause");
#else
    cout<<"\n\n\nPresione enter para continuar ...";
    cin.ignore().get();
#endif
}

#endif // TERMINAL_H
