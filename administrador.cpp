#include "administrador.h"

Administrador::Administrador()
{
    cine = new Cine();
}

void Administrador::dataTest()
{
    cine->dataTest();
}

void Administrador::Instrucciones()
{
    cout << right << setw(40) << "*-*-*-Instrucciones-*-*-*\n\n\n";
    cout << "Este programa basado en terminal, esta pensado para otorgar\n"
            "la mayor rapidez al operador, por lo cual tenga en mente:\n\n"
            "1) No se debe usar ninguna combinacion de teclas especiales ejemplo: \"crtl+c\"\n"
            "2) Use principalmente el teclado numerico\n"
            "3) Si encuentra cualquier error o fallo no dude en contactarme\n\n"
            "info contacto:\n"
            "jguallasaminc@est.ups.edu.ec\n";
}

void Administrador::mostrarCartelera()
{
    cout << setw(1) << "<" << setw(78) << setfill('=') << "" << setw(1) << ">" << "\n" << setfill(' ');
    for(int i=1;i<=cine->getNumPeliculas();i++){
        cout << setw(1) << "|";

        cout << right << setw(4) << "> "+cine->getPeliculaID(i);
        cout << left << setw(cine->getPeliculaNombre(i).length()+1) << " "+cine->getPeliculaNombre(i);
        cout << left << setw(cine->getPeliculaHorarios(i).length()+1) << " "+cine->getPeliculaHorarios(i);
        cout << left << setw(cine->getPeliculaEstreno(i).length()+1) << " "+cine->getPeliculaEstreno(i);
        cout << right << setw(78-(cine->getPeliculaNombre(i).length()+cine->getPeliculaHorarios(i).length()+cine->getPeliculaEstreno(i).length()+7)) << setfill(' ') << "";

        cout << setw(1) << "|" << "\n";
    }
    cout << setw(1) << "<" << setw(78) << setfill('=') << "" << setw(1) << ">" << "\n\n" << setfill(' ');
}

void Administrador::venderBoleto()
{
    if(cine->getNumPeliculas()==1){
        cout << "Se necesita agregar una pelicula primero :D";
        return;
    }

    mostrarCartelera();

    string aux;
    int peliID=-1,horario=-1,numBoletos=-1,fila=-1,columna=-1;
    do{
        cout << "Ingrese el id de Pelicula[" + (cine->getNumPeliculas()==1? "1":"1-"+to_string(cine->getNumPeliculas())) + "]:";
        getline(cin>>ws,aux);

        if(!validarNumero(aux)){
            cout << "Id invalido" << endl;
        }else{
            peliID = stoi(aux);
            if(peliID<=0||peliID>cine->getNumPeliculas())
                cout << "Id invalido" << endl;
        }
    }while(peliID<=0||peliID>cine->getNumPeliculas());


    do{
        cout << "Elija el horario deseado \n";
        cout << cine->getPeliculaHorarios(peliID,true) << endl << "->";
        getline(cin>>ws,aux);

        if(!validarNumero(aux)){
            cout << "Horario invalido" << endl;
        }else{
            horario = stoi(aux);
            if(horario<=0||horario>cine->getPeliculaNumHorarios(peliID))
                cout << "Horario invalido" << endl;
        }
    }while(horario<=0||horario>cine->getPeliculaNumHorarios(peliID));


    do{
        cout << "Ingrese cantidad de boletos:";
        getline(cin>>ws,aux);

        if(!validarNumero(aux)){
            cout << "Asientos insuficientes" << endl;
        }else{
            numBoletos = stoi(aux);
            if(numBoletos<0||numBoletos>cine->getAsientosDisponibles(cine->getPeliculaSalaID(peliID)))
                cout << "Asientos insuficientes" << endl;
        }
    }while(numBoletos<0||numBoletos>cine->getAsientosDisponibles(cine->getPeliculaSalaID(peliID)));

    if(numBoletos==0){
        cout << "\nCompra cancelada\n";
        return;
    }


    mostrarAsientos(cine->getPeliculaSalaID(peliID));
    for(int i=0;i<numBoletos;i++){

        do{

            do{
                cout << "Ingrese Fila:";
                getline(cin>>ws,aux);

                if(!validarNumero(aux)){
                    aux[0] = toupper(aux[0]);

                    string filas_validas[cine->getSalaFilas()] = {"A","B","C","D","E"};
                    bool invalida = true;

                    for(int i=0;i<cine->getSalaFilas();i++){
                        if(aux==filas_validas[i]){
                            fila = i+1;
                            invalida = false;
                            break;
                        }
                    }

                    if(invalida)
                        cout << "Fila invalida" << endl;

                }else{
                    fila = stoi(aux);
                    if(fila<=0||fila>cine->getSalaFilas())
                        cout << "Fila invalida" << endl;
                }
            }while(fila<=0||fila>cine->getSalaFilas());

            do{
                cout << "Ingrese Columna:";
                getline(cin>>ws,aux);

                if(!validarNumero(aux)){
                    cout << "Columna invalida" << endl;
                }else{
                    columna = stoi(aux);
                    if(columna<=0||columna>cine->getSalaColumnas())
                        cout << "Columna invalida" << endl;
                }
            }while(columna<=0||columna>cine->getSalaColumnas());

            if(cine->addBoletos(peliID,fila,columna,horario)){
                cout << "\nBoleto comprado :D\n";
                cout << "Id asiento: " << cine->getBoletoAsiento(cine->getNumBoletos()) << endl;
                imprimirTicket(cine->getBoletoNumBoletos());
                mostrarAsientos(cine->getPeliculaSalaID(peliID));
                break;
            }else{
                cout << "\nEspacio ocupado :C\n";

            }
        }while(1);
        //mostrarAsientos(cine->getPeliculaSalaID(peliID));

        //cout << setw(1) << "<" << setw(78) << setfill('=') << "" << setw(1) << ">" << "\n" << setfill(' ') << endl;
    }
}

void Administrador::factura()
{
    cout << setw(1) << "<" << setw(78) << setfill('=') << "" << setw(1) << ">" << "\n" << setfill(' ');
    cout << setw(20) << "" << setw(60) << cine->getNombre() << endl;
    cout << setw(1) << "<" << setw(78) << setfill('=') << "" << setw(1) << ">" << "\n" << setfill(' ');
    int tickets = cine->getBoletoNumBoletos();
    for(int i=0;i<tickets;i++){
        imprimirTicket(cine->getBoletoNumBoletos());
        cine->eliminarUltimoBoleto();
    }
    cine->setNumBoletos(0);
    cout << setw(10) << right << "Total: " << setw(68) << setprecision(4) << cine->getBoletoCosto()*tickets << setw(2) << " $" << endl;
    cout << setw(1) << "<" << setw(78) << setfill('=') << "" << setw(1) << ">" << "\n" << setfill(' ');
}

void Administrador::imprimirTicket(int id)
{
    cout << setw(1) << "┌" << setw(78) << setfill('-') << "" << setw(1) << "┐" << "\n" << setfill(' ');
    for(int i=1;i<=9;i++){

        cout << setw(1) << "|";

        switch(i){
        case 1:cout << setw(19) << "" << setw(59) << cine->getNombre();break;
        case 2:cout << setw(29) << "" << setw(49) << "Boleto N# "+to_string(id);break;
        case 3:cout << setw(78) << "  " + cine->getBoletoPelicula(id);break;
        case 5:cout << setw(78) << "  Sala: " + cine->getBoletoSala(id);break;
        case 6:cout << setw(78) << "  Asiento: " + cine->getBoletoAsiento(id);break;
        case 8:cout << setw(10) << "  Precio: " << setw(68) << setprecision(4) << cine->getBoletoCosto();break;
        default:cout << setw(78) << "";
        }

        cout << setw(1) << "|" << "\n";

    }
    cout << setw(1) << "└" << setw(78) << setfill('-') << "" << setw(1) << "┘" << "\n" << setfill(' ') << endl;
}

void Administrador::mostrarAsientos(int salaId)
{
    char filas[cine->getSalaFilas()] = {'A','B','C','D','E'};
    //vector<vector<bool>> asientos = cine->getAsientos(salaId);

    cout << setfill(' ') << setw(5) << "";
    for(int i=1;i<=cine->getSalaColumnas();i++){
        cout << right << setw(3) << i << setw(2) << "";
    }
    cout<<endl;

    for(int i=0;i<cine->getSalaFilas();i++){

        cout << left << setw(2) << to_string(i+1)+")" << right << setw(2) << filas[i] << setw(1) << "";
        for(int j=0;j<cine->getSalaColumnas();j++){

            cout << right << setw(2) << "[";

            if(cine->getSalaPosAsiento(salaId,i+1,j+1)){
                cout << setw(1) << "X";
            }else{
                cout << setw(1) << "";
            }

            cout << left << setw(2) << "]";

        }
        cout << endl;
    }
    cout << endl << endl;
}

bool Administrador::validarNumero(const string &dato)
{
    for (char const &c : dato) {
        if (isdigit(c) == 0)
            return false;
    }

    return true;
}
