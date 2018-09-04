//#############################################################################
// ARCHIVO             : menuFunciones.cpp
// AUTOR/ES            : Zura Iv�n Alejandro
// VERSION             : 0.01 beta.
// FECHA DE CREACION   : 30/08/2018.
// ULTIMA ACTUALIZACION: 30/08/2018.
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

#ifndef MENUFUNCIONES_H_INCLUDED
#define MENUFUNCIONES_H_INCLUDED

using namespace std;

void leeropcion(char &op)
{
  op=cin.get();  // Leer la opcion
  cin.ignore();  // Limpiar el buffer del teclado.
}

void Menu()
{
    short int salir = 0;
    while(salir == 0)
    {
        char opMenu;
        sys::cls();
        menu();
        leeropcion(opMenu);
        switch(opMenu)
        {
            case '0':
            {
                cout << "Datos vacios" << endl;
                sys::pause();
                continue;
            }
            case '99':
            {
                cout << "Opcion 1" << endl;
                sys::pause();
                continue;
            }break;
            case '1':
            {
                cout << "Opcion 1" << endl;
                sys::pause();
                continue;
            }break;
            case '6':
            {
                char opSalir;
                sys::cls();
                salirMenu();
                cout << "opcion: ";
                leeropcion(opSalir);
                switch(opSalir)
                {
                    case 'S':
                    case 's':
                    {
                        salir = 1;
                        continue;
                    }break;
                    case 'N':
                    case 'n':
                    {
                        continue;
                    }break;
                    default:
                    {
                        cout << "Opcion incorrecta. Volviendo al menu";
                        sys::msleep(2);
                        continue;

                    }
                }
                continue;
            }break;
            default:
            {
                cout << "Opcion incorrecta" << endl;
                sys::pause();
                continue;
            }break;
        }
    }
}

#endif // MENUFUNCIONES_H_INCLUDED