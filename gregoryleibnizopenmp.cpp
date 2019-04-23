#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

struct entradas {
    double acum;
    long inicio;
    long fin;
};

void* gregLeibParalelo(void* args){  //OJO!!!!!, esto da pi/4
    struct entradas *misEntradas;
    misEntradas = (struct entradas *) args;
    long inicio = misEntradas->inicio;
    long fin = misEntradas->fin;
    double numerador,denominador,fraccion;
    int alternante = -1;
    
    for(long i = inicio; i < fin; i++)
    {
        alternante = -alternante;
        numerador = alternante;
        denominador = 2*i + 1;
        fraccion = numerador/denominador;
        misEntradas->acum = misEntradas->acum + fraccion;
    }
}

int main (void) {
    struct entradas td[4];
    double acumTotal = 0;
    long paso = 1000000000/4;

    clock_t t;
    t = clock();

    #pragma omp parallel for
    for (int i = 0; i < 4; ++i)
    {
        long imas1 = i+1;
        td[i].inicio = i*paso;
        td[i].fin = imas1*paso;
        gregLeibParalelo(&td[i]);
    }

    for(int i = 0; i < 4; ++i)
    {
        acumTotal = acumTotal + td[i].acum;
    }
    
    cout << std::setprecision(15) << 4*acumTotal << endl;
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",(int)t,((float)t)/CLOCKS_PER_SEC);
}