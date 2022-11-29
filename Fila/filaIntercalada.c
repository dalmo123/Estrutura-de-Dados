#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct fila
{
    int *elementos;
    int nr_elem;
    int inicio;
    int final;
};

typedef struct fila Fila;

Fila *criar(int size, bool *deuCerto)
{

    Fila *f;

    f = (Fila *) malloc(sizeof(Fila));

    if(f == NULL) *deuCerto = false;

    else
    {
        f->elementos = (int *) malloc(size * sizeof(int));
        if(f->elementos == NULL) *deuCerto = false;
        else
        {
            f->nr_elem = 0;
            f->inicio = 0;
            f->final = 0;
            *deuCerto = true;
        }
    }

    return f;
}

void destruir(Fila *f)
{

    free(f->elementos);
    free(f);
}

bool cheia(Fila *f, int size)
{

    if(f->nr_elem == size)
        return true;
    else
        return false;

}

bool vazia(Fila *f)
{

    if(f->nr_elem == 0)
        return true;
    else
        return false;

}

bool insere(Fila *f, int size, int valor)
{

    if(cheia(f,size))
        return false;

    else
    {
        f->elementos[f->final] = valor;
        f->nr_elem +=1 ;

        if(f->final == size-1) f->final = 0;
        else f->final += 1;

        return true;
    }
}

bool retira(Fila *f, int *valor, int size)
{

    if(vazia(f))
        return false;

    else
    {
        *valor = f->elementos[f->inicio];
        f->elementos[f->inicio] = 0; //seta 0 pra deixar a fila vazia..
        f->nr_elem -= 1;

        if(f->inicio == size-1) f->inicio = 0;
        else f->inicio += 1;
    }
}

Fila *alterna(Fila *f, Fila *f2,int size)
{

    Fila *f3;
    bool deuCerto;
    int sizeResul;
    int aux;

    sizeResul = size * 2;
    f3 = criar(sizeResul, &deuCerto);
    if(deuCerto == false)
    {
        printf("Nao foi possivel alocar a fila..");
        exit(1);
    }else{

        for(int i=0; i<sizeResul; i++){
            if(i%2 == 0){
                aux = f->elementos[f->inicio];
                insere(f3,sizeResul,aux);
                f->inicio += 1;
            }else{
                aux = f2->elementos[f2->inicio];
                insere(f3,sizeResul,aux);
                f2->inicio += 1;
            }
        }


    }


    return f3;

}

void mostrar(Fila *f, int size)
{

    f->inicio = 0;

    for(int i=0; i<size; i++)
    {
        printf("%d ", f->elementos[f->inicio]);
        f->inicio += 1;
    }
}



int main()
{


    Fila *f;
    Fila *f2;
    Fila *fAlternada;
    int size,size2,sizeFinal,valor;
    bool deuCerto;

    printf("Insira o tamanho das fila: ");
    scanf("%d", &size);


    f = criar(size,&deuCerto);
    if(deuCerto == false)
    {
        printf("Nao foi possivel alocar a fila..");
        exit(1);
    }

    for(int i=0; i<size; i++)
    {
        printf("Insira um numero pra 1a fila:: ");
        scanf("%d", &valor);
        insere(f,size,valor);
    }

    printf("-------------------------------------\n");

    f2 = criar(size,&deuCerto);
    if(deuCerto == false)
    {
        printf("Nao foi possivel alocar a fila..");
        exit(1);
    }

    for(int i=0; i<size; i++)
    {
        printf("Insira um numero pra 2a fila:: ");
        scanf("%d", &valor);
        insere(f2,size,valor);
    }


    fAlternada = alterna(f,f2,size);

    printf("Fila 1->");
    mostrar(f,size);
    printf("\n");


    printf("Fila 2->");
    mostrar(f2,size);
    printf("\n");


    printf("Fila Alternada->");
    mostrar(fAlternada,4);
    printf("\n");

    destruir(f);
    destruir(f2);
    destruir(fAlternada);

    return 0;
}
