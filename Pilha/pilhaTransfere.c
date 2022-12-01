#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pilha{
    int *elementos;
    int topo;
};

typedef struct pilha Pilha;

//criar , destruir, cheio, vazio, empilha, desempilha


Pilha *criar(int tam, bool *deuCerto){

    Pilha *p;

    p = (Pilha *) malloc(sizeof(Pilha));
    if(p == NULL)  *deuCerto = false;

    else{
        p->elementos = (int *) malloc (tam * sizeof(int));
        if(p->elementos == NULL) *deuCerto = false;
        else{
            *deuCerto = true;
            p->topo = -1;
        }
    }

    return p;
}

void destruir(Pilha *p){

    free(p->elementos);
    free(p);
    printf("Foi destruido..\n");
}

bool vazio(Pilha *p){

    if(p->topo == -1)
        return true;
    else
        return false;
}

bool cheio(Pilha *p, int tam){

    if(p->topo == tam-1)
        return true;
    else
        return false;
}

bool empilhar(Pilha *p, int valor, int tam){

    if(cheio(p, tam)){
        return false;
    }
    else{
        p->topo +=1 ;
        p->elementos[p->topo] = valor;
        return true;
    }
}

bool desempilhar(Pilha *p, int *valor){

    if(vazio(p)){
        return false;
    }
    else{
        *valor = p->elementos[p->topo];
        p->topo -= 1;
        return true;
    }
}

void transfereElementos(Pilha *p, Pilha *p2, Pilha *aux, int tam){

    int valor;

    while(!vazio(p)){
        desempilhar(p,&valor);
        empilhar(aux,valor,tam);
    }

    while(!vazio(aux)){
        desempilhar(aux,&valor);
        empilhar(p2,valor,tam);
    }

}


int main()
{


    Pilha *p;
    Pilha *p2;
    Pilha *aux;
    int tam;
    bool deuCerto;
    int valor, x;

    printf("Digite o tamanho da Pilha: ");
    scanf("%d", &tam);

    p = criar(tam, &deuCerto);
    if(deuCerto == false){
        printf("Nao foi alocado..\n");
        exit(1);
    }
    p2 = criar(tam, &deuCerto);
    if(deuCerto == false){
        printf("Nao foi alocado..\n");
        exit(1);
    }
    aux = criar(tam, &deuCerto);
    if(deuCerto == false){
        printf("Nao foi alocado..\n");
        exit(1);
    }

    while(!cheio(p,tam)){
        scanf("%d", &valor);
        empilhar(p,valor,tam);
    }

    transfereElementos(p,p2,aux,tam);

    printf("Elementos transferidos e inalterados..\n");
    while(!vazio(p2)){
        desempilhar(p2,&valor);
        printf("%d\n", valor);
    }

    destruir(p);
    destruir(p2);
    destruir(aux);

    return 0;
}
