#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

double gregLeib(long i){
    double numerador,denominador,fraccion;
    int alternante = (i % 2 == 0)? 1 : -1 ;
    double acum = 0;
    
    numerador = alternante;
    denominador = 2*i + 1;
    fraccion = numerador/denominador;
    return fraccion;
}

int main (void) {
    double acumTotal = 0;

    clock_t t;
    t = clock();

    #pragma omp parallel for reduction(+:acumTotal)
    for (long i = 0; i < 1000000000; ++i)
    {
	double acum = gregLeib(i);
	acumTotal = acumTotal + acum;
    }


    cout << std::setprecision(15) << 4*acumTotal << endl;
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",(int)t,((float)t)/CLOCKS_PER_SEC);
}
    
    cout << std::setprecision(15) << 4*acumTotal << endl;
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",(int)t,((float)t)/CLOCKS_PER_SEC);
}
