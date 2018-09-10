#ifndef FREELANCERS_H_INCLUDED
#define FREELANCERS_H_INCLUDED

using namespace std;

struct tFreelancers {
    int DNI;
    char nombre[30];
    char apellido[30];
    short int Horas;
    short int idTipo;
    char tipo[30];
};

void mostrarFreelancers(tFreelancers freelancers)
{
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "+ Nombre   : " << freelancers.nombre << endl;
    cout << "+ Apellido : " << freelancers.apellido << endl;
    cout << "+ DNI      : " << freelancers.DNI << endl;
    cout << "+ Tipo     : " << freelancers.tipo << endl;
    cout << "+ Horas    : " << freelancers.Horas << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
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

void AltaFreelancers()
{
    short int salir = 0;
    while(salir == 0)
    {
        char nombre[30];
        char apellido[30];
        short int idTipo;

        cout << "############   Agregando Freelancer    ############" << endl;

        cout << "Nombre: ";
        sys::getline(nombre, 30);
        if(strcmp(nombre, ""))
        {
            sys::cls();
            cout << "Nombre vacio, vuelva a cargar" << endl;
            sys::pause();
            continue;
        }
        cout << "Apellido: ";
        sys::getline(apellido, 30);
        if(strcmp(apellido, ""))
        {
            sys::cls();
            cout << "Apellido vacio, vuelva a cargar" << endl;
            sys::pause();
            continue;
        }
        cout << "Tipo de laburante: ";
        cin >> idTipo;
        cin.ignore();
        switch(idTipo)
        {
            case '1':
            {

            }break;
            case '2':
            {

            }break;
            case '3':
            {

            }break;
            default:
            {
                sys::cls();
                cout << "Opcion incorrecta, vuelva a cargar" << endl;
                sys::pause();
                continue;
            }break;
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
            freelancers.DNI = 36938292;
            freelancers.Horas = 35;
            freelancers.idTipo = 1;
            strcpy(freelancers.tipo, "Diseñador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Pablo");
            strcpy(freelancers.apellido, "Sardulex");
            freelancers.DNI = 32119232;
            freelancers.Horas = 28;
            freelancers.idTipo = 1;
            strcpy(freelancers.tipo, "Diseñador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Marta");
            strcpy(freelancers.apellido, "Martulo");
            freelancers.DNI = 33213333;
            freelancers.Horas = 100;
            freelancers.idTipo = 1;
            strcpy(freelancers.tipo, "Diseñador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Miguel");
            strcpy(freelancers.apellido, "Andaro");
            freelancers.DNI = 39222823;
            freelancers.Horas = 33;
            freelancers.idTipo = 1;
            strcpy(freelancers.tipo, "Diseñador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Jesus");
            strcpy(freelancers.apellido, "Aragon");
            freelancers.DNI = 34232999;
            freelancers.Horas = 130;
            freelancers.idTipo = 2;
            strcpy(freelancers.tipo, "Desarrollador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Natanel");
            strcpy(freelancers.apellido, "Semilla");
            freelancers.DNI = 35098098;
            freelancers.Horas = 22;
            freelancers.idTipo = 2;
            strcpy(freelancers.tipo, "Desarrollador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Orlando");
            strcpy(freelancers.apellido, "Satur");
            freelancers.DNI = 92003990;
            freelancers.Horas = 57;
            freelancers.idTipo = 2;
            strcpy(freelancers.tipo, "Desarrollador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Matias");
            strcpy(freelancers.apellido, "Latero");
            freelancers.DNI = 93003998;
            freelancers.Horas = 80;
            freelancers.idTipo = 2;
            strcpy(freelancers.tipo, "Desarrollador");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Ramiro");
            strcpy(freelancers.apellido, "Simero");
            freelancers.DNI = 27203199;
            freelancers.Horas = 33;
            freelancers.idTipo = 3;
            strcpy(freelancers.tipo, "Analista");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Santiago");
            strcpy(freelancers.apellido, "Sasa");
            freelancers.DNI = 28391955;
            freelancers.Horas = 39;
            freelancers.idTipo = 3;
            strcpy(freelancers.tipo, "Analista");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Gonzalo");
            strcpy(freelancers.apellido, "Reibon");
            freelancers.DNI = 33058999;
            freelancers.Horas = 28;
            freelancers.idTipo = 3;
            strcpy(freelancers.tipo, "Analista");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

            strcpy(freelancers.nombre, "Rodrigo");
            strcpy(freelancers.apellido, "Latete");
            freelancers.DNI = 32252495;
            freelancers.Horas = 10;
            freelancers.idTipo = 3;
            strcpy(freelancers.tipo, "Analista");
            fwrite(&freelancers,sizeof(tFreelancers),1,archivo);

        }
    }
    fclose(archivo);
}

#endif // FREELANCERS_H_INCLUDED
