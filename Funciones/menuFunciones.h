//#############################################################################
// ARCHIVO             : menuFunciones.h
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

#ifndef MENUFUNCIONES_H_INCLUDED
#define MENUFUNCIONES_H_INCLUDED

using namespace std;
//---------------------------------------------------------------------------
// FUNCION   : void Menu()
// ACCION    : Menu de varios niveles que interactua con las funciones y el usuario
// PARAMETROS: nada
// DEVUELVE  : nada
//---------------------------------------------------------------------------
void Menu()
{
    short int salir = 0;
    while(salir == 0)
    {
        char o[2];
        sys::cls();
        menu();
        sys::getline(o, 2);
        int opMenu = strToInt(o);
        switch(opMenu)
        {
            case 0:
            {
                cout << "Datos vacios" << endl;
                sys::pause();
                continue;
            }
            case 1:
            {
                char o2[2];
                sys::cls();
                menuFreelancers();
                cout << "opcion: ";
                sys::getline(o2, 2);
                int opSalir = strToInt(o2);
                switch(opSalir)
                {
                    case 1:
                    {
                        sys::cls();
                        AltaFreelancers();
                        sys::pause();
                        continue;
                    }break;
                    case 2:
                    {
                        sys::cls();
                        char o3[2];
                        int opModifica;
                        menuModificaFreelancer();
                        cout << "opcion: ";
                        sys::getline(o3, 2);
                        opModifica = strToInt(o3);
                        switch(opModifica)
                        {
                            case 1:
                            {
                                sys::cls();
                                modificaFreelancer(opModifica);
                            }break;
                            case 2:
                            {
                                sys::cls();
                                modificaFreelancer(opModifica);
                            }break;
                            case 3:
                            {
                                sys::cls();
                                modificaFreelancer(opModifica);
                            }break;
                            case 4:
                            {
                                continue;
                            }break;
                            default:
                            {
                                cout << "Opcion incorrecta - Presione ENTER" << endl;
                                sys::pause();
                                continue;
                            }break;
                        }
                        sys::pause();
                        continue;
                    }break;
                    case 3:
                    {
                        sys::cls();
                        leerFreelancers();
                        sys::pause();
                        continue;
                    }break;
                    case 4:
                    {
                        continue;
                    }break;
                    default:
                    {
                        cout << "Opcion incorrecta" <<endl;
                        sys::pause();
                        continue;
                    }
                }

                continue;
            }break;
            case 2:
            {
                char o2[2];
                sys::cls();
                menuGestionHoras();
                cout << "opcion: " << endl;
                sys::getline(o2, 2);
                int opSalir = strToInt(o2);
                switch(opSalir)
                {
                    case 1:
                    {
                        sys::cls();
                        cargarHorasAllFreelancers();
                        continue;
                    }break;
                    case 2:
                    {
                        sys::cls();
                        cargarHorasUnFreelancer();
                        continue;
                    }break;
                    case 3:
                    {
                        continue;
                    }break;
                    default:
                    {
                        cout << "Opcion incorrecta - Presione ENTER" << endl;
                        sys::pause();
                        continue;
                    }break;
                }

            }break;
            case 3:
            {
                sys::cls();
                buscaFreelancer();
                continue;
            }break;
            case 4:
            {
                sys::cls();
                char op2[2];
                int opSalir ;
                menuReportes();
                sys::getline(op2, 2);
                opSalir = strToInt(op2);
                switch(opSalir)
                {
                    case 1:
                    {
                        sys::cls();
                        horasPorPuesto();
                        continue;
                    }break;
                    case 2:
                    {
                        sys::cls();
                        horasPorPuestoPorFreelancer();
                        continue;
                    }break;
                    case 3:
                    {
                        continue;
                    }break;
                    default:
                    {
                        cout << "Opcion incorrecta - Presione ENTER" << endl;
                        sys::pause();
                        continue;
                    }
                }

                continue;
            }break;
            case 5:
            {
                sys::cls();
                configuracionHora();
                sys::pause();
                continue;
            }
            case 6:
            {
                char o[2];
                sys::cls();
                salirMenu();
                cout << "opcion: ";
                sys::getline(o, 2);
                int opSalir = strToInt(o);
                switch(opSalir)
                {
                    case 1:
                    {
                        salir = 1;
                        continue;
                    }break;
                    case 2:
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
            case 11:
            {
                cout << strToInt("A") << endl;
                sys::pause();
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
