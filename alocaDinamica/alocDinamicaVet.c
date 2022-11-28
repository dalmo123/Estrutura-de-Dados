#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct vetor
{
    float *elem;
    int max;
    int total;
};

typedef struct vetor Vetor;


Vetor *criar (int n, bool *deuCerto)
{

    Vetor *v;

    v = (Vetor *) malloc(sizeof(Vetor));

    if(v == NULL) *deuCerto = false;

    else
    {
        v->elem = (float *) malloc(n * sizeof(float));
        if(v->elem == NULL) *deuCerto = false;
        else
        {
            *deuCerto = true;
            v->max = n;
            v->total = 0;
        }
    }

    return v;

}

void destruir(Vetor *v)
{
    free(v->elem);
    free(v);

}

bool cheio(Vetor *v)
{

    if(v->max == v->total)
        return true;

    else
        return false;

}

bool vazio(Vetor *v)
{

    if(v->total == 0)
        return true;

    else
        return false;
}

bool inserir(Vetor *v, float valor)
{


    if(cheio(v))
    {
        return false;
    }

    else
    {
        v->elem[v->total] = valor;
        v->total += 1;
        return true;
    }
}

void mostrar(Vetor *v, int index, float *valor, bool *deuCerto)
{

    if(vazio(v)== false)
    {
        if( index >=0 && index < v->max)
        {
            *deuCerto = true;
            *valor = v->elem[index];
        }
        else *deuCerto = false;
    }
    else *deuCerto = false;

}



int main()
{
    Vetor *v;
    int n;
    bool deuCerto;
    float valor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&n);

    v = criar(n, &deuCerto);
    if(deuCerto == false)
    {
        printf("Nao foi possivel alocar o vetor..\n");
        exit(1);
    }

    printf("Insira os valores do vetor: \n");

    while(cheio(v) == false)
    {
        scanf("%f", &valor);
        inserir(v, valor);
    }


    for(int i=0; i<n ; i++)
    {
        mostrar(v, i, &valor, &deuCerto);
        printf("%.2f ", valor);
    }


    printf("\n");


    destruir(v);



    return 0;
}
