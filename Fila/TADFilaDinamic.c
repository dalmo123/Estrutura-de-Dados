#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct fila{
    char *elementos;
    int n_elem;
    int inicio;
    int final;
};

typedef struct fila Fila;

Fila *criar(int tam, bool *deuCerto)
{

    Fila *F;

    F = (Fila *) malloc(sizeof(Fila));

    if(F == NULL) *deuCerto = false;


    else
    {
        F->elementos = (char *) malloc(tam * sizeof(char));
        if(F->elementos == NULL) *deuCerto =false;
        else
        {
            *deuCerto = true;
            F->n_elem = 0;
            F->final = 0;
            F->inicio = 0;
        }
    }

    return F;

}

void destruir(Fila *f)
{
    if(f != NULL)
    {
        free(f->elementos);
        free(f);
    }

}

bool vazia(Fila *f)
{

    if(f->n_elem ==0) return true;
    else return false;

}

bool cheia(Fila *f, int tam){

        if(f->n_elem == tam) return true;
        else return false;

}

bool insere(Fila *f, char valor, int tam){

    if(cheia(f,tam)){
        return false;
    }
    else{
        f->elementos[f->final] = valor;
        f->n_elem += 1;

        if(f->final == (tam-1))  f->final = 0;
        else f->final += 1;

        return true;

    }

}

bool retira(Fila *f, char *valor, int tam){

    if(vazia(f)){
        return false;
    }
    else{
        *valor = f->elementos[f->inicio];
        f->n_elem -= 1;

        if(f->inicio == tam-1) f->inicio = 0;
        else f->inicio += 1;

        return true;
    }

}




int main(){


    Fila *f;
    bool deuCerto;
    int tam;
    char valor;

    printf("Insira o tamanho da fila..\n");
    scanf("%d", &tam);

    f = criar(tam,&deuCerto);
    if(deuCerto == false){
        printf("Nao foi possivel criar..\n");
        exit(1);
    }

    while (cheia(f,tam) == false){
        scanf(" %c", &valor);
        insere(f,valor, tam);
    }


    while(!vazia(f)){
        retira(f,&valor,tam);
        printf("Retirado: %c\n", valor);
    }


    printf("\n");

    destruir(f);


return 0;
}
