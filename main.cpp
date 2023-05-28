#include <iostream>
#include <iomanip>
#include "Terminal.h"
#include "administrador.h"

using namespace std;

int main()
{

    cout << "hola mundo" << endl;

    Administrador cine;

    cine.dataTest();

    cine.Instrucciones();

    Pausar();
    limpiar_pantalla();

    cine.mostrarCartelera();

    Pausar();
    limpiar_pantalla();

    cine.venderBoleto();

    Pausar();
    limpiar_pantalla();

    cine.venderBoleto();

    Pausar();
    limpiar_pantalla();

    cine.venderBoleto();

    Pausar();
    limpiar_pantalla();

    cout << "hola mundo" << endl;

    return 0;
}
