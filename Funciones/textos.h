#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

using namespace std;

void presentacion()
{
    cout << "############################################################" <<endl;
    cout << "#                                                          #" <<endl;
    cout << "#                  Magic Software S.A                      #" <<endl;
    cout << "#                                                          #" <<endl;
    cout << "#         Empresa de tecnologias de la informacion         #" <<endl;
    cout << "#                                                          #" <<endl;
    cout << "#            No hackeamos Facebook ni Twitter              #" <<endl;
    cout << "#                                                          #" <<endl;
    cout << "############################################################" <<endl;
}

void menu()
{
    cout << "############################################################" <<endl;
    cout << "#    1 - Gestion de Freelancers                            #" <<endl;
    cout << "#    2 - Gestion de Horas                                  #" <<endl;
    cout << "#    3 - Busquedas                                         #" <<endl;
    cout << "#    4 - Reportes                                          #" <<endl;
    cout << "#    5 - Configuracion de Horas                            #" <<endl;
    cout << "#    6 - Salir                                             #" <<endl;
    cout << "############################################################" <<endl;
}

void salirMenu()
{
    cout << "############################################################" <<endl;
    cout << "#                                                          #" <<endl;
    cout << "#                      Desea salir ?                       #" <<endl;
    cout << "#                                                          #" <<endl;
    cout << "#         S - Salir                                        #" <<endl;
    cout << "#         N - Volver                                       #" <<endl;
    cout << "#                                                          #" <<endl;
    cout << "############################################################" <<endl;
}

#endif // MENUS_H_INCLUDED
