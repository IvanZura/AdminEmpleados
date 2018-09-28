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
    cout << "#    5 - Configuracion precio de Horas                     #" <<endl;
    cout << "#    6 - Salir                                             #" <<endl;
    cout << "############################################################" <<endl;
}

void menuGestionHoras()
{
    cout << "############################################################" <<endl;
    cout << "#    1 - Cargar horas todos los freelancers                #" <<endl;
    cout << "#    2 - Cargar horas a un freenlancer                     #" <<endl;
    cout << "#    3 - Volver                                            #" <<endl;
    cout << "############################################################" <<endl;
}

void menuFreelancers()
{
    cout << "############################################################" <<endl;
    cout << "#    1 - Alta freelancers                                  #" <<endl;
    cout << "#    2 - Modificacion de Freelancers                       #" <<endl;
    cout << "#    3 - Mostrar de Freelancers                            #" <<endl;
    cout << "#    4 - Volver                                            #" <<endl;
    cout << "############################################################" <<endl;
}

void menuModificaFreelancer()
{
    cout << "################### Elija que modificar ####################" <<endl;
    cout << "#    1 - Nombre                                            #" <<endl;
    cout << "#    2 - Apellido                                          #" <<endl;
    cout << "#    3 - Puesto                                            #" <<endl;
    cout << "#    4 - Volver                                            #" <<endl;
    cout << "############################################################" <<endl;
}

void salirMenu()
{
    cout << "############################################################" <<endl;
    cout << "#                                                          #" <<endl;
    cout << "#                      Desea salir ?                       #" <<endl;
    cout << "#                                                          #" <<endl;
    cout << "#         1 - Salir                                        #" <<endl;
    cout << "#         2 - Volver                                       #" <<endl;
    cout << "#                                                          #" <<endl;
    cout << "############################################################" <<endl;
}

#endif // MENUS_H_INCLUDED
