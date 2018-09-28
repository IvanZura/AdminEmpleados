#ifndef FREELANCERS_H_INCLUDED
#define FREELANCERS_H_INCLUDED

using namespace std;

struct tFreelancers {
    char DNI[9];
    char nombre[30];
    char apellido[30];
    short int Horas;
    int idTipo;
    char tipo[30];
};

void mostrarFreelancers(tFreelancers freelancers)
{
    cout << "############################################" << endl;
    cout << "# Nombre   : " << freelancers.nombre << endl;
    cout << "# Apellido : " << freelancers.apellido << endl;
    cout << "# DNI      : " << freelancers.DNI << endl;
    cout << "# Tipo     : " << freelancers.tipo << endl;
    cout << "# Horas    : " << freelancers.Horas << endl;
    cout << "#" << endl;
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
