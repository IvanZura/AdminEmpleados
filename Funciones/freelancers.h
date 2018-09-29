//#############################################################################
// ARCHIVO             : freelancers.h
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
#ifndef FREELANCERS_H_INCLUDED
#define FREELANCERS_H_INCLUDED

using namespace std;

struct tFreelancers {
    char DNI[9];
    char nombre[30];
    char apellido[30];
    int Horas;
    int idTipo;
    char tipo[30];
};

int totalFreelancers()
{
    tFreelancers freelancers;
    FILE *archivo;
    archivo = fopen(F_FREELANCERS, "rb+");
    if(archivo != NULL)
    {
        fseek(archivo, 0, SEEK_END);
        int val = ftell(archivo) / sizeof(tFreelancers);
        fclose(archivo);
        return val;
    }
}

void mostrarFreelancers(tFreelancers freelancers)
{
    cout << "############################################" << endl;
    cout << "# " << freelancers.nombre << " " << freelancers.apellido << endl;
    cout << "# DNI: " << freelancers.DNI << " - " << freelancers.tipo << " - " << freelancers.Horas << " Horas" << endl;
}

void leerFreelancers()
{
    tFreelancers freelancers;
    FILE *archivo;
    archivo = fopen(F_FREELANCERS,"rb");
    if(archivo!=NULL)
    {
        while(fread(&freelancers,sizeof(tFreelancers),1,archivo))
        {
            mostrarFreelancers(freelancers);
        }
        fclose(archivo);
    }
    else
    {
        fclose(archivo);

        sys::pause();
    }
}

bool validaDNI(char* DNI)
{
    tFreelancers freelancers;
    FILE *archivo;
    archivo = fopen(F_FREELANCERS, "rb");
    if(archivo != NULL)
    {
        while(fread(&freelancers, sizeof(tFreelancers), 1, archivo))
        {
            int DNIParam = strToInt(DNI);
            int DNIFile = strToInt(freelancers.DNI);
            if(DNIFile == DNIParam)
            {
                fclose(archivo);
                return true;
            }
        }
        return false;
    }
}

int posDNI(tFreelancers *freelancers, char DNI[30])
{
    FILE *archivo;
    archivo = fopen(F_FREELANCERS, "rb");
    if(archivo != NULL)
    {
        while(fread(freelancers, sizeof(tFreelancers), 1, archivo))
        {
            int DNIParam = strToInt(DNI);
            int DNIFile = strToInt(freelancers->DNI);
            if(DNIFile == DNIParam)
            {
                int pos = ftell(archivo) / sizeof(tFreelancers) - 1;
                fclose(archivo);
                return pos;
            }
        }
    }
}

int actualizaFreelancer(tFreelancers freelancers, int pos)
{
    FILE *archivo;
    archivo = fopen(F_FREELANCERS, "rb+");
    if(archivo != NULL)
    {
        fseek(archivo,sizeof(tFreelancers) * pos, SEEK_SET);
        int val = fwrite(&freelancers, sizeof(tFreelancers), 1, archivo);
        fclose(archivo);
        return val;
    }
}

void llenaFreelance(tFreelancers *freelancers, int pos)
{
    FILE *archivo;
    archivo = fopen(F_FREELANCERS, "rb+");
    if(archivo != NULL)
    {
        fseek(archivo, sizeof(tFreelancers) * pos, SEEK_SET);
        fread(freelancers, sizeof(tFreelancers), 1, archivo);
        fclose(archivo);
    }
}

void buscaFreelancer()
{
    int cant = totalFreelancers();
    tFreelancers freelancers[cant];
    tFreelancers freelancePag[cant];
    int total = 0;

    char busqueda[30];
    int opSalir = 0;
    while(opSalir == 0)
    {
        sys::cls();
        cout << "# Busqueda de freelancer por nombre o apellido" << endl;
        cout << "# Ingrese 0 para salir " << endl;
        cout << "Ingrese su busqueda: " << endl;
        sys::getline(busqueda, 30);
        if(!strcmp(busqueda, ""))
        {
            cout << "Campos vacio - Presione ENTER" << endl;
            sys::pause();
            continue;
        }
        int n = strToInt(busqueda);
        if(n == 0)
        {
            cout << "Se cancela - Presione ENTER" << endl;
            sys::pause();
            opSalir = 1;
            continue;
        }
        strupr(busqueda);

        for(int i = 0; i < cant; i++)
        {
            llenaFreelance(&freelancers[i], i);
            strupr(freelancers[i].nombre);
            strupr(freelancers[i].apellido);
            char *subn= strstr(freelancers[i].nombre, busqueda);
            char *suba= strstr(freelancers[i].apellido, busqueda);
            if(subn != NULL || suba != NULL)
            {
                strcpy(freelancePag[total].nombre, freelancers[i].nombre);
                strcpy(freelancePag[total].apellido, freelancers[i].apellido);
                strcpy(freelancePag[total].DNI, freelancers[i].DNI);
                strcpy(freelancePag[total].tipo, freelancers[i].tipo);
                freelancePag[total].idTipo = freelancers[i].idTipo;
                freelancePag[total].Horas = freelancers[i].Horas;
                total++;
                continue;
            }
        }
        int opSalirPag = 0;
        int maximoPorPag = 5;
        if(total < 5)
        {
            maximoPorPag = total;
        }
        int pag = 0;
        while(opSalirPag == 0){
            //sys::cls();
            char opc[2];
            for(int y = pag; y < maximoPorPag; y++)
            {
                mostrarFreelancers(freelancePag[y]);
            }
            if(total == 0)
            {
                cout << "No se encontro lo que buscaba - Presione ENTER" << endl;
                sys::pause();
                opSalirPag = 1;
                opSalir = 1;
                continue;
            }

            cout << "1 - Anterior / 2 - Siguiente / 3 - Salir" << endl;
            sys::getline(opc, 2);
            int opcN = strToInt(opc);
            if(opcN == 1)
            {
                int res = total - maximoPorPag;
                if(opcN)
                {

                }
            }
            else if(opcN == 2)
            {
                int res = total - ((total - maximoPorPag) - 5);
                //          12       12   -     5         - 5
                if(res > 0)
                {
                    pag += 5;
                    maximoPorPag = res;
                    total = total - 5;
                    continue;
                }
                else
                {
                    cout << "No hay mas paginas - Presione ENTER" << endl;
                    sys::pause();
                    continue;
                }
            }
            else if(opcN == 3)
            {
                opSalirPag = 1;
                opSalir = 1;
                continue;
            }
            else
            {
                cout << "Opcion incorrecta - Presione ENTER" << endl;
                sys::pause();
                continue;
            }
            sys::pause();
        }
        continue;
    }

}

void cargarHorasUnFreelancer()
{
    tFreelancers freelancers;
    char horas[5];
    char DNI[9];
    int opSalir = 0;
    while(opSalir == 0)
    {
        sys::cls();
        cout << "# Carga de horas a un individuo" << endl;
        cout << "# Presione 0 para salir al menu" << endl;
        cout << "Ingrese DNI: ";
        sys::getline(DNI, 9);
        int dniN = strToInt(DNI);
        if(dniN < 0)
        {
            cout << "Numero de DNI invalido - Presione ENTER" << endl;
            sys::pause();
            continue;
        }
        if(dniN == 0)
        {
            cout << "Se cancela la carga - Presione ENTER" << endl;
            sys::pause();
            opSalir = 1;
            continue;
        }
        int val = validaDNI(DNI);
        if(!val)
        {
            cout << "No existe DNI - Presione ENTER" << endl;
            sys::pause();
            continue;
        }
        int pos = posDNI(&freelancers, DNI);
        sys::cls();
        mostrarFreelancers(freelancers);
        cout << "Ingrese horas a asginar a " << freelancers.nombre << ": " << endl;
        sys::getline(horas, 5);
        int horasN = strToInt(horas);
        if(horasN < 0)
        {
            cout << "Numero de horas invalidas - Presione ENTER" << endl;
            sys::pause();
            continue;
        }
        freelancers.Horas = horasN;
        int valCar = actualizaFreelancer(freelancers, pos);
        if(valCar)
        {
            cout << "Grabo correctamente - Presione ENTER" << endl;
            sys::pause();
            opSalir = 1;
            continue;
        }
        else
        {
            cout << "Ocurrio un error al grabar la informacion - Presione ENTER para volver al menu" <<  endl;
            sys::pause();
            opSalir = 1;
            continue;
        }
    }
}

void cargarHorasAllFreelancers()
{
    char horas[5];
    int total = totalFreelancers();
    tFreelancers freelancers;
    for(int i = 0; i < total; i++)
    {
        sys::cls();
        llenaFreelance(&freelancers, i);
        mostrarFreelancers(freelancers);
        cout << "# Para salir ingrese un numero menor a 0" << endl; // Menor a 0 porque el tipo pudo haber trabajado 0 horas.
        cout << "Ingrese horas trabajadas por " << freelancers.nombre << ": " << endl;
        sys::getline(horas, 5);
        int horasN = strToInt(horas);
        if(horasN < 0)
        {
            cout << "Se cancela la carga del freelancer actual y vuelve al menu - Presione ENTER" << endl;
            sys::pause();
            break;
        }
        freelancers.Horas = horasN;
        int val = actualizaFreelancer(freelancers, i);
        if(val)
        {
            cout << "Grabo correctamente - Presione ENTER para continuar con otro freelance" << endl;
            sys::pause();
            continue;
        }
        else
        {
            cout << "Ocurrio un error al grabar la informacion - Presione ENTER para volver al menu" <<  endl;
            sys::pause();
            break;
        }
    }
    cout << "Toda la informacion fue procesada, se volvera al menu en 3 segundos" << endl;
    sys::msleep(3);
}

void modificaFreelancer(int op)
{
    char titulo[30];
    char DNI[9];
    short int salir = 0;
    int DNIcero;
    bool vDNI;
    if(op == 1){ strcpy(titulo, "nombre"); }else if(op == 2){ strcpy(titulo, "apellido"); }else if(op == 3){ strcpy(titulo, "puesto"); }

    while(salir == 0)
    {
        sys::cls();
        cout << "######## Modificando " << titulo << " ##################" << endl;
        cout << "# " << endl;
        cout << "# Para volver al menu ingrese el numero 0" << endl;
        cout << " " << endl;
        cout << "Ingresa numero de DNI: ";
        sys::getline(DNI, 9);
        if(!strcmp(DNI, ""))
        {
            sys::cls();
            cout << "DNI vacio, vuelva a cargar - Presione ENTER" << endl;
            sys::pause();
            sys::cls();
            continue;
        }
        vDNI = validaDNI(DNI);
        DNIcero = strToInt(DNI);
        if(DNIcero == 0)
        {
            cout << "Se cancela la modificacion, volviendo al menu principal - Presione ENTER" << endl;
            salir = 1;
            continue;
        }
        if(!vDNI)
        {
            cout << "DNI No existente, consulte nuevamente." << endl;
            sys::pause();
            sys::cls();
            continue;
        }
        else
        {
            sys::cls();
            cout << "######## Modificando " << titulo << " ##################" << endl;
            cout << "# Ahora: " << endl;

            tFreelancers freelancers;
            int pos = posDNI(&freelancers, DNI);
            mostrarFreelancers(freelancers);

            switch(op)
            {
                case 1:
                {
                    char nombre[30];
                    char op2[2];
                    cout << "Nombre nuevo: ";
                    sys::getline(nombre, 30);
                    if(!strcmp(nombre, ""))
                    {
                        sys::cls();
                        cout << "Nombre vacio, vuelva a cargar" << endl;
                        sys::pause();
                        continue;
                    }
                    strcpy(freelancers.nombre, nombre);
                    cout << "# Modificacion: " << endl;
                    mostrarFreelancers(freelancers);
                    cout << "Esta seguro de modificar estos datos? 1-Si / 2-NO" << endl;
                    sys::getline(op2, 2);
                    int op2N = strToInt(op2);
                    if(op2N == 1)
                    {
                        int val = actualizaFreelancer(freelancers, pos);
                        if(val)
                        {
                            cout << "Se actualizo correctamente el " << titulo << " - Presione ENTER" << endl;
                            salir = 1;
                            continue;
                        }
                        else
                        {
                            cout << "Ocurrio un error al grabar la informacion - Presione ENTER" << endl;
                            sys::pause();
                            continue;
                        }
                    }
                    else if(op2N == 2)
                    {
                        cout << "Se cancelo la modificacion - Presione ENTER" << endl;
                        sys::pause();
                        continue;
                    }
                    else
                    {
                        cout << "Opcion incorrecta, se cancelara la modificacion - Presione ENTER" << endl;
                        sys::pause();
                        continue;
                    }

                }break;
                case 2:
                {
                    char apellido[30];
                    char op2[2];
                    cout << "Apellido nuevo: ";
                    sys::getline(apellido, 30);
                    if(!strcmp(apellido, ""))
                    {
                        sys::cls();
                        cout << "Apellido vacio, vuelva a cargar" << endl;
                        sys::pause();
                        continue;
                    }
                    strcpy(freelancers.apellido, apellido);
                    cout << "# Modificacion: " << endl;
                    mostrarFreelancers(freelancers);
                    cout << "Esta seguro de modificar estos datos? 1-Si / 2-NO" << endl;
                    sys::getline(op2, 2);
                    int op2N = strToInt(op2);
                    if(op2N == 1)
                    {
                        int val = actualizaFreelancer(freelancers, pos);
                        if(val)
                        {
                            cout << "Se actualizo correctamente el " << titulo << " - Presione ENTER" << endl;
                            salir = 1;
                            continue;
                        }
                        else
                        {
                            cout << "Ocurrio un error al grabar la informacion - Presione ENTER" << endl;
                            sys::pause();
                            continue;
                        }
                    }
                    else if(op2N == 2)
                    {
                        cout << "Se cancelo la modificacion - Presione ENTER" << endl;
                        sys::pause();
                        continue;
                    }
                    else
                    {
                        cout << "Opcion incorrecta, se cancelara la modificacion - Presione ENTER" << endl;
                        sys::pause();
                        continue;
                    }
                }break;
                case 3:
                {
                    char tipo[30];
                    int idTipo;
                    char id[2];
                    char op2[2];
                    cout << "# Puestos:" << endl;
                    cout << "# " << endl;
                    cout << "# 1 - Diseñador" << endl;
                    cout << "# 2 - Desarrollador" << endl;
                    cout << "# 3 - Analista" << endl;
                    cout << "# " << endl;
                    cout << "Numero de puesto nuevo: ";
                    sys::getline(id, 2);
                    if(!strcmp(id, ""))
                    {
                        sys::cls();
                        cout << "Puesto vacio, vuelva a cargar" << endl;
                        sys::pause();
                        continue;
                    }
                    idTipo = strToInt(id);
                    if(idTipo < 1 || idTipo > 3)
                    {
                       sys::cls();
                        cout << "Puesto invalido, vuelva a cargar" << endl;
                        sys::pause();
                        continue;
                    }
                    freelancers.idTipo = idTipo;
                    tConfig config;
                    FILE *archivo;
                    archivo = fopen(F_CONFIG, "rb");
                    if(archivo != NULL)
                    {
                        while(fread(&config, sizeof(tConfig), 1, archivo))
                        {
                            if(config.idPuesto == idTipo)
                            {
                                strcpy(freelancers.tipo, config.nombre);
                            }
                        }
                    }
                    fclose(archivo);
                    cout << "# Modificacion: " << endl;
                    mostrarFreelancers(freelancers);
                    cout << "Esta seguro de modificar estos datos? 1-Si / 2-NO" << endl;
                    sys::getline(op2, 2);
                    int op2N = strToInt(op2);
                    if(op2N == 1)
                    {
                        int val = actualizaFreelancer(freelancers, pos);
                        if(val)
                        {
                            cout << "Se actualizo correctamente el " << titulo << " - Presione ENTER" << endl;
                            salir = 1;
                            continue;
                        }
                        else
                        {
                            cout << "Ocurrio un error al grabar la informacion - Presione ENTER" << endl;
                            sys::pause();
                            continue;
                        }
                    }
                    else if(op2N == 2)
                    {
                        cout << "Se cancelo la modificacion - Presione ENTER" << endl;
                        sys::pause();
                        continue;
                    }
                    else
                    {
                        cout << "Opcion incorrecta, se cancelara la modificacion - Presione ENTER" << endl;
                        sys::pause();
                        continue;
                    }
                }break;
                default:
                {
                    cout << "Opcion incorrecta" << endl;
                    continue;
                }break;
            }
            sys::pause();
        }
    }


}

void AltaFreelancers()
{
    short int salir = 0;
    while(salir == 0)
    {
        tFreelancers freelancers;
        char nombre[30];
        char apellido[30];
        char DNI[9];
        int idTipo;
        bool vDNI;

        sys::cls();
        cout << "############   Agregando Freelancer    ############" << endl;
        cout << "# Puestos:" << endl;
        cout << "# " << endl;
        cout << "# 1 - Diseñador" << endl;
        cout << "# 2 - Desarrollador" << endl;
        cout << "# 3 - Analista" << endl;
        cout << "# " << endl;
        cout << "# Presiona 4 para volver" << endl;
        cout << "# " << endl;
        cout << "###################################################" << endl;

        cout << "Puesto: ";
        char o[2];
        sys::getline(o, 2);
        idTipo = strToInt(o);

        switch(idTipo)
        {
            case 1:
            {
                tConfig config;
                FILE *archivo;
                archivo = fopen(F_CONFIG, "rb");
                if(archivo != NULL)
                {
                    while(fread(&config, sizeof(tConfig), 1, archivo))
                    {
                        if(config.idPuesto == idTipo)
                        {
                            strcpy(freelancers.tipo, config.nombre);
                        }
                    }
                }
                fclose(archivo);
            }break;
            case 2:
            {
                tConfig config;
                FILE *archivo;
                archivo = fopen(F_CONFIG, "rb");
                if(archivo != NULL)
                {
                    while(fread(&config, sizeof(tConfig), 1, archivo))
                    {
                        if(config.idPuesto == idTipo)
                        {
                            strcpy(freelancers.tipo, config.nombre);
                        }
                    }
                }
                fclose(archivo);
            }break;
            case 3:
            {
                tConfig config;
                FILE *archivo;
                archivo = fopen(F_CONFIG, "rb");
                if(archivo != NULL)
                {
                    while(fread(&config, sizeof(tConfig), 1, archivo))
                    {
                        if(config.idPuesto == idTipo)
                        {
                            strcpy(freelancers.tipo, config.nombre);
                        }
                    }
                }
                fclose(archivo);
            }break;
            case 4:
            {
                cout << "Salida sin carga" << endl;
                salir = 1;
                continue;
            }break;
            default:
            {
                sys::cls();
                cout << "Opcion incorrecta, vuelva a cargar" << endl;
                sys::pause();
                continue;
            }break;
        }
        cout << "Nombre: ";
        sys::getline(nombre, 30);
        if(!strcmp(nombre, ""))
        {
            sys::cls();
            cout << "Nombre vacio, vuelva a cargar" << endl;
            sys::pause();
            continue;
        }
        cout << "Apellido: ";
        sys::getline(apellido, 30);
        if(!strcmp(apellido, ""))
        {
            sys::cls();
            cout << "Apellido vacio, vuelva a cargar" << endl;
            sys::pause();
            continue;
        }
        cout << "DNI: ";
        sys::getline(DNI, 9);
        if(!strcmp(DNI, ""))
        {
            sys::cls();
            cout << "DNI vacio, vuelva a cargar" << endl;
            sys::pause();
            continue;
        }
        vDNI = validaDNI(DNI);
        if(vDNI)
        {
            cout << "Esta persona ya fue ingresada al sistema, favor de corroborar" << endl;
            sys::pause();
            continue;
        }

        strcpy(freelancers.nombre, nombre);
        strcpy(freelancers.apellido, apellido);
        strcpy(freelancers.DNI, DNI);
        freelancers.Horas = 0;
        freelancers.idTipo = idTipo;

        sys::cls();
        cout << "############   Agregando Freelancer    ############" << endl;
        cout << "#" << endl;
        cout << "# Desea confirmar el alta de estos datos? 1-SI / 2-NO" << endl;
        cout << "#" << endl;
        mostrarFreelancers(freelancers);
        cout << "opcion: ";
        char o3[2];
        sys::getline(o3, 2);
        int sel = strToInt(o3);
        if(sel == 1)
        {
            FILE *archivo;
            archivo = fopen(F_FREELANCERS,"r");
            if(archivo != NULL)
            {
                fclose(archivo);
                archivo = fopen(F_FREELANCERS,"ab");
                if(archivo==NULL)
                {
                    cout << "No se pudo crear el archivo de FREELANCERS" <<endl;
                }
                else
                {
                    if(fwrite(&freelancers,sizeof(tFreelancers),1,archivo))
                    {
                        cout << "Se agrego correctamente" << endl;
                        salir = 1;
                    }
                    else
                    {
                        cout << "Ocurrio un error, no se guardara los datos." << endl;
                        sys::pause();
                        continue;
                    }
                }
                fclose(archivo);
            }
            else
            {
                cout << "No existe archivo" << endl;
                sys::pause();
            }
        }
        else if(sel == 2)
        {
            cout << "No se guardara ningun cambio" <<endl;
            sys::pause();
            continue;
        }else
        {
            cout << "Opcion incorrecta" << endl;
            sys::pause();
            continue;
        }

    }
}

void InitDataFreelancers()
{
    tFreelancers freelancers;
    FILE *archivo;
    archivo = fopen(F_FREELANCERS,"r");
    if(archivo == NULL)
    {
        fclose(archivo);
        archivo = fopen(F_FREELANCERS,"ab");
        if(archivo==NULL)
        {
            cout << "No se pudo crear el archivo de FREELANCERS" <<endl;
        }
        else
        {
            strcpy(freelancers.nombre, "Pedro");
            strcpy(freelancers.apellido, "Vega");
            strcpy(freelancers.DNI, "36938292");
            strcpy(freelancers.DNI, "36938292");
            freelancers.Horas = 35;
            freelancers.idTipo = 1;
            strcpy(freelancers.tipo, "Diseñador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Pablo");
            strcpy(freelancers.apellido, "Sardulex");
            strcpy(freelancers.DNI, "32119232");
            freelancers.Horas = 28;
            freelancers.idTipo = 1;
            strcpy(freelancers.tipo, "Diseñador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Marta");
            strcpy(freelancers.apellido, "Martulo");
            strcpy(freelancers.DNI, "33213333");
            freelancers.Horas = 100;
            freelancers.idTipo = 1;
            strcpy(freelancers.tipo, "Diseñador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Miguel");
            strcpy(freelancers.apellido, "Andaro");
            strcpy(freelancers.DNI, "39222823");
            freelancers.Horas = 33;
            freelancers.idTipo = 1;
            strcpy(freelancers.tipo, "Diseñador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Jesus");
            strcpy(freelancers.apellido, "Aragon");
            strcpy(freelancers.DNI, "34232999");
            freelancers.Horas = 130;
            freelancers.idTipo = 2;
            strcpy(freelancers.tipo, "Desarrollador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Natanel");
            strcpy(freelancers.apellido, "Semilla");
            strcpy(freelancers.DNI, "35098098");
            freelancers.Horas = 22;
            freelancers.idTipo = 2;
            strcpy(freelancers.tipo, "Desarrollador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Orlando");
            strcpy(freelancers.apellido, "Satur");
            strcpy(freelancers.DNI, "92003990");
            freelancers.Horas = 57;
            freelancers.idTipo = 2;
            strcpy(freelancers.tipo, "Desarrollador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Matias");
            strcpy(freelancers.apellido, "Latero");
            strcpy(freelancers.DNI, "93003998");
            freelancers.Horas = 80;
            freelancers.idTipo = 2;
            strcpy(freelancers.tipo, "Desarrollador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Ramiro");
            strcpy(freelancers.apellido, "Simero");
            strcpy(freelancers.DNI, "27203199");
            freelancers.Horas = 33;
            freelancers.idTipo = 3;
            strcpy(freelancers.tipo, "Analista");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Santiago");
            strcpy(freelancers.apellido, "Sasa");
            strcpy(freelancers.DNI, "28391955");
            freelancers.Horas = 39;
            freelancers.idTipo = 3;
            strcpy(freelancers.tipo, "Analista");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Gonzalo");
            strcpy(freelancers.apellido, "Reibon");
            strcpy(freelancers.DNI, "33058999");
            freelancers.Horas = 28;
            freelancers.idTipo = 3;
            strcpy(freelancers.tipo, "Analista");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Rodrigo");
            strcpy(freelancers.apellido, "Latete");
            strcpy(freelancers.DNI, "32252495");
            freelancers.Horas = 10;
            freelancers.idTipo = 3;
            strcpy(freelancers.tipo, "Analista");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

        }
    }
    fclose(archivo);
}

#endif // FREELANCERS_H_INCLUDED
