#include <iostream>
#include <pthread.h>
#include <iomanip>

using namespace std;

#define NUM_THREADS 2 // 2,4,8,16

struct entradas {
    double acum;
    unsigned int inicio;
    unsigned int fin;
};

void gregLeibParaleloAntoguo(double &acum, long inicio, long fin){  //OJO!!!!!, esto da pi/4
    double numerador,denominador,fraccion;
    int alternante = -1;
    for(long i = inicio; i < fin; i++)
    {
        alternante = -alternante;
        numerador = alternante;
        denominador = 2*i + 1;
        fraccion = numerador/denominador;
        acum = acum + fraccion;
    }
}

void* gregLeibParalelo(void* args){  //OJO!!!!!, esto da pi/4
    struct entradas *misEntradas;
    misEntradas = (struct entradas *) args;
    unsigned int inicio = misEntradas->inicio;
    cout << inicio << endl;
    unsigned int fin = misEntradas->fin;
    cout << inicio << endl;
    double acum = misEntradas->acum;
    double numerador,denominador,fraccion;
    int alternante = -1;
    
    for(unsigned int i = inicio; i < fin; i++)
    {
        alternante = -alternante;
        numerador = alternante;
        denominador = 2*i + 1;
        fraccion = numerador/denominador;
        acum = acum + fraccion;
    }
}
/*
int main (void) {
    pthread_t threads[NUM_THREADS];
    struct entradas td;
    unsigned int paso = 1000000000/NUM_THREADS;
    td.inicio = 0;
    td.fin = 1000000000/NUM_THREADS;
    double acumTotal = 0;
    td.acum = 0;

    for (unsigned int i = 0 ; i < NUM_THREADS ; ++i)
    {
        td.acum = 0;
        int t = pthread_create(&threads[i], NULL, gregLeibParalelo, (void *)&td);
 
        if (t != 0)
        {
            cout << "Error in thread creation: " << t << endl;
        }
        td.inicio = td.fin;
        td.fin = td.fin + paso;
        acumTotal += td.acum;
        printf("Acumulado: %f", acumTotal);
    }
    cout << std::setprecision(9) << 4*acumTotal << endl;
}
*/

int main (void) {
    struct entradas td;
    td.inicio = 0;
    td.fin = 10000;
    td.acum = 0;
    gregLeibParalelo((void *)&td);
    printf("Acumulado: %f \n", td.acum);
}