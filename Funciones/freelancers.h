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

void initInfo()
{
    tFreelancers Freelancers;
    FILE *archivo;
    archivo = fopen(F_FREELANCERS,"ab");
    if(archivo==NULL)
    {

    }
}

#endif // FREELANCERS_H_INCLUDED
