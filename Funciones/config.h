#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

using namespace std;

struct tConfig{
    short int idPuesto;
    char nombre[30];
    float valorHora;
};

void InitDataConfig()
{
    tConfig config;
    FILE *archivo;
    archivo = fopen(F_CONFIG, "r");
    if(archivo == NULL)
    {
        fclose(archivo);
        archivo = fopen(F_CONFIG, "ab");
        if(archivo == NULL)
        {
            cout << "No se pudo crear el archivo" << endl;
        }
        else
        {
            config.idPuesto = 1;
            strcpy(config.nombre, "Diseñador");
            config.valorHora = 300;
            fwrite(&config,sizeof(tConfig),1,archivo);

            config.idPuesto = 2;
            strcpy(config.nombre, "Desarrollador");
            config.valorHora = 350;
            fwrite(&config,sizeof(tConfig),1,archivo);

            config.idPuesto = 3;
            strcpy(config.nombre, "Analista");
            config.valorHora = 400;
            fwrite(&config,sizeof(tConfig),1,archivo);
        }
    }


    fclose(archivo);

}

#endif // CONFIG_H_INCLUDED
