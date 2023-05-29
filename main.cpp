#include <iostream>
#include <iomanip>
#include "Terminal.h"
#include "administrador.h"

using namespace std;

int main()
{
    Administrador cine;

    cine.dataTest();

    string submenu;
    int menu = -1;
    do{
        cout<<"\nMenu de Opciones\n\n";
        cout<<"Elija su opcion: \n"
                "VenderBoleto[1] \n"
                "MostrarCartelera[2] \n"
                "Instruciones[3] \n"
                "Salir[4]\n";

        do{
            cout << "Ingrese su opcion: ";
            getline(cin>>ws,submenu);

            if(!cine.validarNumero(submenu)){
                cout << "Opcion invalida" << endl;
            }else{
                menu = stoi(submenu);
                if(menu<=0||menu>4)
                    cout << "Opcion invalida" << endl;
            }
        }while(menu<=0||menu>4);


        switch(menu){
        case 1:
            cine.venderBoleto();
            limpiar_pantalla();
            cine.factura();
            break;
        case 2:
            cine.mostrarCartelera();
            break;
        case 3:
            cine.Instrucciones();
            break;
        case 4:
            cout << "Gracias por usar mi programa" << endl;
        }

        Pausar();
        limpiar_pantalla();
    }while(menu!=4);

    return 0;
}
