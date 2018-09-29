//#############################################################################
// ARCHIVO             : config.h
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
//              Funciones relacionadas al archivo de configuracion
//
////////////////////////////////////////////////////////////////////////////////
#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

using namespace std;

//---------------------------------------------------------------------------
// FUNCION   : int strLen (char*cad).
// ACCION    : Cuenta la cantidad de caracteres que tiene una cadena.
// PARAMETROS: cadena.
// DEVUELVE  : el número entero.
//---------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
// FUNCION   : void horasExistentes void horasExistentes(tConfig *config, int pos).
// ACCION    : Carga una estructura de config
// PARAMETROS: estructura, entero.
// DEVUELVE  : nada
//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
// FUNCION   : void mostrarHorasExistentes(tConfig config)
// ACCION    : Muestra una estructura
// PARAMETROS: estructura.
// DEVUELVE  : nada
//---------------------------------------------------------------------------
void mostrarHorasExistentes(tConfig config)
{
    cout << "Puesto: " << config.idPuesto << " - " << config.nombre << "    | Precio: " << config.valorHora << endl;
    cout << " " << endl;
}
//---------------------------------------------------------------------------
// FUNCION   : int totalConfig()
// ACCION    : Devuelve la cantidad de registros
// PARAMETROS: nada.
// DEVUELVE  : entero
//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
// FUNCION   : int aplicarPrecioHoras(tConfig config, int pos)
// ACCION    : Carga una estructura y devuelve la respuesta del fwrite
// PARAMETROS: estructura, entero.
// DEVUELVE  : entero
//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
// FUNCION   : int grabarPrecioHoras(int idPuesto, float valor)
// ACCION    : Modifica el valor de la hora del puesto que se le pase
// PARAMETROS: entero, flotante.
// DEVUELVE  : entero
//---------------------------------------------------------------------------
int grabarPrecioHoras(int idPuesto, float valor)
{
    tConfig config;
    horasExistentes(&config, idPuesto);
    config.valorHora = valor;
    return aplicarPrecioHoras(config, idPuesto);
}
//---------------------------------------------------------------------------
// FUNCION   : void configuracionHora()
// ACCION    : Modifica el valor de la hora de algun puesto
// PARAMETROS: nada
// DEVUELVE  : nada
//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
// FUNCION   : void InitDataConfig()
// ACCION    : Si no existe, inicializa el archivo de configuraciones
// PARAMETROS: nada
// DEVUELVE  : nada
//---------------------------------------------------------------------------
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
