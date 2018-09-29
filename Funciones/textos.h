//#############################################################################
// ARCHIVO             : textos.h
// AUTOR/ES            : Zura Iván Alejandro
// VERSION             : 1.00.
// FECHA DE CREACION   : 30/08/2018.
// ULTIMA ACTUALIZACION: 28/09/2018.
// LICENCIA            : GPL (General Public License) - Version 3.
//
//  **************************************************************************
//  * El software libre no es una cuestion economica sino una cuestion etica *
//  **************************************************************************
//
// Este programa es software libre;  puede redistribuirlo  o  modificarlo bajo
// los terminos de la Licencia Publica General de GNU  tal como se publica por
// la  Free Software Foundation;  ya sea la version 3 de la Licencia,  o (a su
// eleccion) cualquier version posterior.
//
// Este programa se distribuye con la esperanza  de que le sea util,  pero SIN
// NINGUNA  GARANTIA;  sin  incluso  la garantia implicita de MERCANTILIDAD  o
// IDONEIDAD PARA UN PROPOSITO PARTICULAR.
//
// Vea la Licencia Publica General GNU para mas detalles.
//
// Deberia haber recibido una copia de la Licencia Publica General de GNU junto
// con este proyecto, si no es asi, escriba a la Free Software Foundation, Inc,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, EE.UU.

//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7 / Windows 10
// IDE                 : Code::Blocks - 8.02 / 10.05 / 17.12
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//              Breve explicacion sobre el contenido del archivo.
//
////////////////////////////////////////////////////////////////////////////////
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
    cout << "#    3 - Busqueda por nombre o apellido                    #" <<endl;
    cout << "#    4 - Reportes                                          #" <<endl;
    cout << "#    5 - Configuracion precio de Horas / Listado           #" <<endl;
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

void menuReportes()
{
    cout << "############################################################" <<endl;
    cout << "#    1 - Horas totales por puesto                          #" <<endl;
    cout << "#    2 - Horas totales por freelancer por puesto           #" <<endl;
    cout << "#    3 - Volver                                            #" <<endl;
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
