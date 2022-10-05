#include <iostream>
#include <fstream>
#include <cmath>

#include <sstream>
#include "funzioni.h"
using namespace std;


double *load(const string& filename, int& count){                    //metto dati in un array
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }

    count = 0;      // n. elementi nel file
    double temp = 0.;
    while ( !f.eof() ) {
        f >> temp;
        count++;
    }
    f.close();

    f.open(filename, ios::in);
    double *out = new double[count];
    for (int i = 0; i < count; i++){
        f >> out[i] ;
    }

    return out;
}

double media(double *m, int count){

    double sum = 0;
    for (int i = 0; i < count; i++){
        sum += m[i];
    }
    return sum/double (count);
}

double stdev(double *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i];
    }
    double media = sum/ntot;
    
    double scarti = 0;
    for(int i = 0; i < ntot; i++){
        scarti += pow((m[i] - media),2);
    }
    return sqrt(scarti/ntot);
}

double varianza(double *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i];
    }
    double media = sum/ntot;
    
    double scarti = 0;
    for(int i = 0; i < ntot; i++){
        scarti += pow((m[i] - media),2);
    }
    return (scarti/ntot);
}

void sort_by_value(double *m, int ntot){                        //metti in ordine crescente
    for (int i = 0; i < ntot - 1; i++){
        for (int j = i + 1; j < ntot; j++){
            if (m[i] > m[j]){
                double dep = m[i];
                m[i] = m[j];
                m[j] = dep;
            }
        }   
    }
}

double mediana (double *m, int ntot){
    double mediana;
    if(ntot%2 == 0){
        double pre = m[(ntot/2) -1];
        double post = m[(ntot/2)];
        mediana = (pre + post)/2;
    }else {
        mediana = m[(ntot+1)/2];
    }

    return mediana;
}

void savedata(double *m, int ntot){                          //salva dati ordinati in un file di uscita
    fstream outfile("datibelli.dat", ios::out);
    for( int i=0; i < ntot; i++){
        outfile << m[i] << endl;
    }
    outfile.close();
}
