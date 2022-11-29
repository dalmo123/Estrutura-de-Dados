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

void concatena(Fila *f, int sizeFinal, Fila *f2, int size2, int size)
{

    f2->inicio= 0;
    f->final = size; // como preenchi f, passanod um size menor, o final vai pra 0...
    int x;

    for(int i=0; i<size2; i++)
    {
        x = f2->elementos[f2->inicio];
        f2->inicio += 1;
        insere(f,sizeFinal,x);
    }
}

void mostrar(Fila *f, int sizeFinal)
{

    f->inicio = 0;

    printf("Fila:: ");
    for(int i=0; i<sizeFinal; i++)
    {
        printf("%d ", f->elementos[f->inicio]);
        f->inicio += 1;
    }
}

void esvaziaFila(Fila *f2, int size2)
{


    int valor;

    f2->inicio = 0;

    for(int i=0; i<size2; i++)
    {
        if(f2->elementos[f2->inicio] != 0)
        {
            retira(f2, &valor, size2);
            printf("Removido:%d Posicao %d\n", valor, f2->inicio);
        }
        else
        {
            f2->inicio +=1;
        }
    }

}


int main()
{


    Fila *f;
    Fila *f2;
    int size,size2,sizeFinal,valor;
    bool deuCerto;

    printf("Insira o tamanho da 1a fila: ");
    scanf("%d", &size);

    printf("Insira o tamanho da 2a fila: ");
    scanf("%d", &size2);

    sizeFinal = size + size2;


    f = criar(sizeFinal,&deuCerto);
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

    f2 = criar(size2,&deuCerto);
    if(deuCerto == false)
    {
        printf("Nao foi possivel alocar a fila..");
        exit(1);
    }

    for(int i=0; i<size2; i++)
    {
        printf("Insira um numero pra 2a fila:: ");
        scanf("%d", &valor);
        insere(f2,size2,valor);
    }


    concatena(f,sizeFinal,f2,size2,size);
    mostrar(f,sizeFinal);

    printf("\n");

    esvaziaFila(f2,size2);

    mostrar(f2,size2);

    destruir(f);
    destruir(f2);

    return 0;
}
