#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct pilha
{
    int topo;
    int elementos[MAX];
};


typedef struct pilha Pilha;

void criar(Pilha *p)
{
    p->topo = -1;
}
void destruir(Pilha *p)
{
    p->topo = -1;
}

bool cheia(Pilha p)
{
    if(p.topo == (MAX-1)){
        return true;
    }

    return false;
}

bool vazia(Pilha p){
    if(p.topo == -1)
    {
        return true;
    }

    return false;
}

bool empilhar(Pilha *p, char x)
{
    if(cheia(*p)){
        return false;
    }
    else{
        p->topo += 1;
        p->elementos[p->topo] = x;
        return true;
    }
}

bool desempilhar(Pilha *p, char *valor)
{
    if(vazia(*p))
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

void compara(Pilha p1, Pilha p2){

    if(p1.topo == p2.topo){
        printf("Sao do mesmo tamanho\n");
    }
    if(p1.topo > p2.topo){
        printf("P1 tem mais elementos que P2\n");
    }
    if(p1.topo < p2.topo){
        printf("P2 tem mais elemetnos que P1\n");
    }

}


int main(){

    Pilha p1;
    Pilha p2;
    char valor;
    bool deuCerto;

    criar(&p1);
    criar(&p2);

    empilhar(&p1, 'A');
    empilhar(&p1, 'B');
    empilhar(&p1, 'C');


    empilhar(&p2, 'A');
    empilhar(&p2, 'B');
    empilhar(&p2, 'C');
    empilhar(&p2, 'D');

    compara(p1,p2);


    destruir(&p1);
    destruir(&p2);




return 0;
}
