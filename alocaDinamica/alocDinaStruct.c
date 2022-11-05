#include <stdio.h>
#include <stdlib.h>

struct ponto
{
    int x;
    int y;
};

typedef struct ponto Ponto;



int main()
{
    Ponto *p;
    int tam;
    int x,y;


    printf("Insira quantos pontos deseja digitar: ");
    scanf("%d", &tam);

    p = (Ponto*) malloc(tam * sizeof(Ponto));

    for(int i=0; i<tam; i++)
    {
        printf("Entre com a coordenada x do ponto %d: ",i+1);
        scanf("%d", &p[i].x);
        printf("Entre com a coordenada y do ponto %d: ",i+1);
        scanf("%d", &p[i].y);
    }

    printf("Pontos digitados:");

    for(int i=0; i<tam ; i++)
    {
        printf(" (%d,%d);", p[i].x, p[i].y);
    }


    free(p);



    return 0 ;
}
