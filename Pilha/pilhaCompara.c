#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

struct pilha{
    int topo;
    int elementos[MAX];
};

typedef struct pilha Pilha;

//criar, destruir, empilhar, desempilahr, cheio , vazio
void criar(Pilha *p){
    p->topo = -1;
}
void destruir(Pilha *p){
    p->topo = -1;
}

bool cheio(Pilha p){

    if(p.topo == MAX-1){
        return true;
    }

    else{
        return false;
    }

}

bool vazio(Pilha p)
{

    if(p.topo == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool desempilhar(Pilha *p, char *c)
{

    if(vazio(*p))
    {
        return false;
    }
    else
    {
        *c = p->elementos[p->topo];
        p->topo -= 1;
        return true;
    }

}

bool empilhar(Pilha *p, char c)
{

    if(cheio(*p))
    {
        return false;
    }
    else
    {
        p->topo += 1;
        p->elementos[p->topo] = c;
        return true;
    }

}

bool empilharExp(char exp[],Pilha *p){

    char c;

    for(int i=0; i<4; i++){
        c = exp[i];
        empilhar(p,c);

    }

}

void compara(Pilha *p1, Pilha *p2){

    char c;
    char c1;

   for(int i=0; i<4; i++){
    desempilhar(p1,&c);
    desempilhar(p2,&c1);
    if(c != c1){
        printf("Nao sao iguais..\n");
        exit(1);
    }
   }

}

void mostrar(char exp[]){

    for(int i=0; i<MAX; i++){
        printf("%c", exp[i]);
    }

    printf("\n");

}



int main()
{

    Pilha p1;
    Pilha p2;
    bool teste;
    char c;
    char expX[MAX] = {"ABCD"};
    char expY[MAX] = {"ABCD"};


    criar(&p1);
    criar(&p2);



    empilharExp(expX,&p1);
    empilharExp(expY,&p2);


    compara(&p1, &p2);


    printf("Sao iguais..\n");
    mostrar(expX);
    mostrar(expY);





    return 0;
}
