#include <stdlib.h>
#include <stdio.h>


int main()
{

    int *v;
    int tam=5, x;


    // preciso colocar o int* antes do malloc?
    v = (int*) malloc(tam * sizeof(int));

    for(int i=0 ; i<tam; i++)
    {
        printf("Insira o numero no vetor: ");
        scanf("%d",&x);
        v[i] = x;
    }

    printf("\n");

    for(int i=0 ; i<tam; i++)
    {
        printf("Numero [%d]: %d \n", i+1, v[i]);
    }

    free(v);
    return 0;
}



