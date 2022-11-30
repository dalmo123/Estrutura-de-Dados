#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pilha
{
    int *elementos;
    int topo;
};
typedef struct pilha Pilha;

struct fila
{
    int *elementos;
    int nr_elem;
    int inicio;
    int fim;
};

typedef struct fila Fila;

Pilha *criarPilha(int size, bool *deuCerto)
{

    Pilha *p;

    p = (Pilha *) malloc(sizeof(Pilha));
    if(p == NULL) *deuCerto = false;

    else
    {
        p->elementos = (int *) malloc(size * sizeof(int));
        if(p->elementos == NULL) *deuCerto = false;
        else
        {
            p->topo = -1;
            *deuCerto = true;
        }
    }

    return p;

}

Fila *criarFila(int size,bool *deuCerto)
{

    Fila *f;

    f = (Fila*) malloc(sizeof(Fila));
    if(f == NULL) *deuCerto = false;

    else
    {
        f->elementos = (int *) malloc(size * sizeof(int));
        if(f->elementos == NULL) *deuCerto = false;
        else
        {
            f->inicio = 0;
            f->fim = 0;
            f->nr_elem =0 ;
            *deuCerto = true;
        }
    }

    return f;

}

bool vaziaPilha(Pilha *p)
{

    if(p->topo == -1)
        return true;
    else
        return false;
}

bool vaziaFila(Fila *f)
{
    if(f->nr_elem == 0)
        return true;
    else
        return false;
}

bool cheiaPilha(Pilha *p, int tam)
{

    if(p->topo == tam-1)
        return true;
    else
        return false;
}

bool cheiaFila(Fila *f, int tam)
{

    if(f->nr_elem == tam) return true;
    else return false;

}

bool push(Pilha *p, int valor, int tam)
{

    if(cheiaPilha(p,tam))
        return false;

    else
    {
        p->topo += 1;
        p->elementos[p->topo] = valor;
        return true;
    }


}

bool pop(Pilha *p, int *valor)
{


    if(vaziaPilha(p))
    {
        return false;
    }

    else
    {
        *valor = p->elementos[p->topo];
        p->topo -= 1;

        return true;
    }
}

bool enqueue(Fila *f, int valor, int size)
{


    if(cheiaFila(f,size))
        return false;

    else
    {
        f->elementos[f->fim] = valor;
        f->nr_elem += 1;

        if(f->fim == (size-1)) f->fim = 0;
        else f->fim += 1;
        return true;
    }

}

bool dequeue(Fila *f, int *valor, int tam)
{

    if(vaziaFila(f))
    {
        return false;
    }
    else
    {
        *valor = f->elementos[f->inicio];
        f->nr_elem -= 1;

        if(f->inicio == tam-1) f->inicio = 0;
        else f->inicio += 1;

        return true;
    }

}

void inverteFila(Pilha *p, Fila *f, int size)
{

    int valor;


    while(!vaziaPilha(p))
    {
        pop(p,&valor);
        enqueue(f,valor,size);
    }

    while(!vaziaFila(f))
    {
        dequeue(f,&valor,size);
        push(p,valor,size);
    }


    while(!vaziaPilha(p))
    {
        pop(p,&valor);
        printf("%d\n", valor);
    }

}




int main()
{

    int size,valor,aux;
    bool deuCerto;
    Fila *f;
    Pilha *p;


    printf("Insira o numero de elementos da Pilha e Fila: ");
    scanf("%d", &size);

    p = criarPilha(size,&deuCerto);
    if(deuCerto)
    {
        printf("Criado Pilha..\n");
    }
    f = criarFila(size,&deuCerto);
    if(deuCerto)
    {
        printf("Criado Fila..\n");
    }

    printf("Preencha a Pilha \n");

    while(cheiaPilha(p,size) == false)
    {
        scanf(" %d", &valor);
        push(p,valor,size);
    }


    printf("Desempilhando Pilha invertida\n");
    inverteFila(p,f,size);




    return 0;
}
