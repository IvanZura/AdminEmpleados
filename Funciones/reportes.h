//#############################################################################
// ARCHIVO             : reportes.h
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
#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void horasPorPuesto()
{
    int totalF = totalFreelancers();
    tFreelancers freelancers[totalF];
    int totalC = totalConfig();
    tConfig config[totalC];
    int sumUno = 0;
    int sumDos = 0;
    int sumTres = 0;
    float valUno, valDos, valTres = 0;

    for(int i = 0; i < totalF; i++)
    {
        llenaFreelance(&freelancers[i], i);
        if(freelancers[i].idTipo == 1)
        {
            sumUno += freelancers[i].Horas;
        }
        else if(freelancers[i].idTipo == 2)
        {
            sumDos += freelancers[i].Horas;
        }
        else if(freelancers[i].idTipo == 3)
        {
            sumTres += freelancers[i].Horas;
        }
    }

    for(int i = 0; i < totalC; i++)
    {
        horasExistentes(&config[i], i);
        if(config[i].idPuesto == 1)
        {
            valUno = sumUno * config[i].valorHora;
        }
        else if(config[i].idPuesto == 2)
        {
            valDos = sumDos * config[i].valorHora;
        }
        else if(config[i].idPuesto == 3)
        {
            valTres = sumTres * config[i].valorHora;
        }
    }

    cout << "Diseñador      - Horas trabajadas: " << sumUno << "\t - A pagar: $" << valUno << endl;
    cout << "Desarrollador  - Horas trabajadas: " << sumDos << "\t - A pagar: $" << valDos << endl;
    cout << "Analista       - Horas trabajadas: " << sumTres << "\t - A pagar: $" << valTres << endl;
    sys::pause();
}

void horasPorPuestoPorFreelancer()
{
    int totalF = totalFreelancers();
    tFreelancers freelancers[totalF];
    tFreelancers freelancersUno[totalF];
    tFreelancers freelancersDos[totalF];
    tFreelancers freelancersTres[totalF];
    int contadorUno = 0;
    int contadorDos = 0;
    int contadorTres = 0;
    int totalC = totalConfig();
    tConfig config[totalC];
    int sumUno = 0;
    int sumDos = 0;
    int sumTres = 0;
    float valUno, valDos, valTres = 0;



    for(int i = 0; i < totalF; i++)
    {
        llenaFreelance(&freelancers[i], i);
        if(freelancers[i].idTipo == 1)
        {
            sumUno += freelancers[i].Horas;
            strcpy(freelancersUno[contadorUno].nombre, freelancers[i].nombre);
            strcpy(freelancersUno[contadorUno].apellido, freelancers[i].apellido);
            strcpy(freelancersUno[contadorUno].DNI, freelancers[i].DNI);
            strcpy(freelancersUno[contadorUno].tipo, freelancers[i].tipo);
            freelancersUno[contadorUno].idTipo = freelancers[i].idTipo;
            freelancersUno[contadorUno].Horas = freelancers[i].Horas;
            contadorUno++;
        }
        else if(freelancers[i].idTipo == 2)
        {
            sumDos += freelancers[i].Horas;
            strcpy(freelancersDos[contadorDos].nombre, freelancers[i].nombre);
            strcpy(freelancersDos[contadorDos].apellido, freelancers[i].apellido);
            strcpy(freelancersDos[contadorDos].DNI, freelancers[i].DNI);
            strcpy(freelancersDos[contadorDos].tipo, freelancers[i].tipo);
            freelancersDos[contadorDos].idTipo = freelancers[i].idTipo;
            freelancersDos[contadorDos].Horas = freelancers[i].Horas;
            contadorDos++;
        }
        else if(freelancers[i].idTipo == 3)
        {
            sumTres += freelancers[i].Horas;
            strcpy(freelancersTres[contadorTres].nombre, freelancers[i].nombre);
            strcpy(freelancersTres[contadorTres].apellido, freelancers[i].apellido);
            strcpy(freelancersTres[contadorTres].DNI, freelancers[i].DNI);
            strcpy(freelancersTres[contadorTres].tipo, freelancers[i].tipo);
            freelancersTres[contadorTres].idTipo = freelancers[i].idTipo;
            freelancersTres[contadorTres].Horas = freelancers[i].Horas;
            contadorTres++;
        }
    }

    for(int i = 0; i < totalC; i++)
    {
        horasExistentes(&config[i], i);
        if(config[i].idPuesto == 1)
        {
            valUno = sumUno * config[i].valorHora;
        }
        else if(config[i].idPuesto == 2)
        {
            valDos = sumDos * config[i].valorHora;
        }
        else if(config[i].idPuesto == 3)
        {
            valTres = sumTres * config[i].valorHora;
        }
    }

    for(int i = 0; i < totalC; i++)
    {
        if(i == 0)
        {
            cout << "#############################################" << endl;
            cout << "# Diseñador" << endl;
            cout << "---------------------------------------------" << endl;
            for(int y = 0; y < contadorUno; y++)
            {
                cout << "# " << freelancersUno[y].nombre << " " << freelancersUno[y].apellido << endl;
                cout << "# DNI: " << freelancersUno[y].DNI << " - " << freelancersUno[y].Horas << " Horas - " << "Sueldo: " << freelancersUno[y].Horas * config[i].valorHora << endl;
            }
            cout << "Horas trabajadas: " << sumUno << "\t - A pagar: $" << valUno << endl;
        }
        else if(i == 1)
        {
            cout << "#############################################" << endl;
            cout << "# Desarrollador" << endl;
            cout << "---------------------------------------------" << endl;
            for(int y = 0; y < contadorDos; y++)
            {
                cout << "# " << freelancersDos[y].nombre << " " << freelancersDos[y].apellido << endl;
                cout << "# DNI: " << freelancersDos[y].DNI << " - " << freelancersDos[y].Horas << " Horas - " << "Sueldo: " << freelancersDos[y].Horas * config[i].valorHora << endl;
            }
            cout << "Horas trabajadas: " << sumDos << "\t - A pagar: $" << valDos << endl;
        }
        else if(i == 2)
        {
            cout << "#############################################" << endl;
            cout << "# Analista" << endl;
            cout << "---------------------------------------------" << endl;
            for(int y = 0; y < contadorTres; y++)
            {
                cout << "# " << freelancersTres[y].nombre << " " << freelancersTres[y].apellido << endl;
                cout << "# DNI: " << freelancersTres[y].DNI << " - " << freelancersTres[y].Horas << " Horas - " << "Sueldo: " << freelancersTres[y].Horas * config[i].valorHora << endl;
            }
            cout << "Horas trabajadas: " << sumTres << "\t - A pagar: $" << valTres << endl;
        }
    }
    sys::pause();
}

#endif // REPORTES_H_INCLUDED
