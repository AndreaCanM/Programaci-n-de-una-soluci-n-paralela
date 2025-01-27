/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 10
#define mostrar 10

void imprimeArreglo(float *d);

int main()
{
    std:: cout <<"Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int i;
    for (i=0; i<N;i++)
    {
        //Caso 1
        //a[i]=i*10;
        //b[i]=(i+3)*3.7;
        
        //Caso 2
        //a[i]=i*15;
        //b[i]=(i+3)*4;
        
        //Caso 3
        a[i]=i*4;
        b[i]=(i+5)*2;
    }
    int pedazos=chunk;
    
    #pragma omp parallel for \
    shared(a,b,c,pedazos) private (i)\
    shedule(static,pedazos)
    
    for(i=0;i<N;i++)
    c[i]=a[i]+b[i];
    
    std::cout<<"Imprimiendo los Primeros" << mostrar << "valores del arreglo a " <<std::endl;
    imprimeArreglo(a);
    std::cout<<"Imprimiendo los Primeros" << mostrar << "valores del arreglo b " <<std::endl;
    imprimeArreglo(b);
    std::cout<<"Imprimiendo los Primeros" << mostrar << "valores del arreglo c " <<std::endl;
    imprimeArreglo(c);
}


    void imprimeArreglo(float *d)
    {
        for(int x=0;x<mostrar;x++)
            std::cout<<d[x]<<" - ";
        std::cout<<std::endl;
            
    }
