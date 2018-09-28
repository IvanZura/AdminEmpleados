#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

using namespace std;

int strLen (char *palabra)

{
    int i=0;
    while (palabra[i]!='\0')
    {
        i++;
    }
    return i;
}

//---------------------------------------------------------------------------
// FUNCION   : int strToInt (char*cad).
// ACCION    : convierte una cadena de caracteres a un número entero.
// PARAMETROS: cadena.
// DEVUELVE  : el número entero.
//---------------------------------------------------------------------------

int strToInt (char *cadena)
{

    int x=1;
    int resultado=0;
    int tam=strLen(cadena)-1;
    for (int c1=tam; c1>=0; c1--)
    {
        resultado+=((cadena[c1]-48)*x);
        x*=10 ;
    }
    return resultado;
}

struct tConfig{
    int idPuesto;
    char nombre[30];
    float valorHora;
};

void horasExistentes(tConfig *config, int pos)
{
    FILE *archivo;
    archivo = fopen(F_CONFIG, "rb+");
    if(archivo != NULL)
    {
        fseek(archivo, sizeof(tConfig) * pos, 0);
        fread(config, sizeof(tConfig), 1, archivo);
    }
    fclose(archivo);
}

void mostrarHorasExistentes(tConfig config)
{
    cout << "Puesto: " << config.idPuesto << " - " << config.nombre << "    | Precio: " << config.valorHora << endl;
    cout << " " << endl;
}

int totalConfig()
{
    tConfig config;
    FILE *archivo;
    archivo = fopen(F_CONFIG, "rb+");
    if(archivo != NULL)
    {
        fseek(archivo, 0, SEEK_END);
        int val = ftell(archivo) / sizeof(tConfig);
        fclose(archivo);
        return val;
    }
}

int aplicarPrecioHoras(tConfig config, int pos)
{
    FILE *archivo;
    archivo = fopen(F_CONFIG, "rb+");
    if(archivo != NULL)
    {
        fseek(archivo, sizeof(tConfig) * pos, SEEK_SET);
        int val = fwrite(&config, sizeof(tConfig), 1, archivo);
        fclose(archivo);
        return val;
    }
}

int grabarPrecioHoras(int idPuesto, float valor)
{
    tConfig config;
    horasExistentes(&config, idPuesto);
    config.valorHora = valor;
    return aplicarPrecioHoras(config, idPuesto);
}

void configuracionHora()
{
    char ho[2];
    char pho[20];
    short int salir = 0;
    int ca = totalConfig();
    tConfig config[ca];

    while(salir == 0)
    {
        sys::cls();
        cout << "################# Valores de puestos ################" << endl;
        cout << " " << endl;
        for(int i = 0; i < ca; i++)
        {
            horasExistentes(&config[i], i);
            mostrarHorasExistentes(config[i]);
        }
        cout << "Para salir presione el numero: " << ca + 1 << endl;
        cout << "Numero de puesto a cambiar precio de hora: ";
        sys::getline(ho, 2);
        if(!strcmp(ho, ""))
        {
            cout << "Campo vacio, vuelva a ingresar - Presione ENTER" << endl;
            sys::pause();
            continue;
        }
        int idp = strToInt(ho);
        if(idp > ca + 1 || idp < 1)
        {
            cout << "Puesto invalido - Presione ENTER" << endl;
            sys::pause();
            continue;
        }
        if(idp == ca + 1)
        {
            cout << "Se cancela la modificacion - Presione ENTER" << endl;
            salir = 1;
            continue;
        }
        cout << "Ingrese nuevo precio por Hora: ";
        sys::getline(pho, 20);
        float phoras = strtof(pho,0);
        if(phoras <= 0)
        {
            cout << "No es numero valido - Presione ENTER" << endl;
            sys::pause();
            continue;
        }
        cout << "Puesto: " << idp << " | Nuevo valor: " << phoras << endl;
        cout << "Confirma la modificacion? 1-Si / 2-NO" << endl;
        sys::getline(ho, 2);
        int ver = strToInt(ho);
        if(ver == 1)
        {
            int val = grabarPrecioHoras(idp - 1, phoras);
            if(val)
            {
                cout << "Cambio realizado con exito" << endl;
                salir = 1;
                continue;
            }
            else
            {
                cout << "ocurrio un error - Presione ENTER" << endl;
                sys::pause();
                continue;
            }
        }
        else if(ver == 2)
        {
            cout << "Se cancela la modificacion - Presione ENTER" << endl;
            sys::pause();
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

}

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
