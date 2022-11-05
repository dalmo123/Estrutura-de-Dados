#include <stdlib.h>
#include <stdio.h>

void preencher(int *v, int tam)
{

    int x;

    for(int i=0; i<tam ; i++)
    {
        printf("Preencha o vetor: ");
        scanf("%d", &x);
        v[i] = x;
    }

}


int verificaPar(int *v, int tam)
{

    int cont=0;
    for(int i=0; i<tam ; i++)
    {
        if(v[i] % 2 == 0)
        {
            cont++;
        }
    }

    return cont;
}

void mostrar (int *v, int tam, int par, int impar)
{

    printf("Sao pares: %d dos %d inteiros lidos\n", par, tam);
    printf("Sao impares: %d dos %d inteiros lidos\n", impar, tam);
}



int main()
{

    int *v;
    int tam, x, par, impar;

    printf("Insira o tam do vetor: ");
    scanf("%d", &tam);

    v = (int *) malloc(tam * sizeof(int));

    preencher(v,tam);

    par = verificaPar(v,tam);

    impar = tam - par;

    mostrar(v,tam,par,impar);

    free(v);



    return 0;
}
