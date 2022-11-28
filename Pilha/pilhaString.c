#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 5

struct pilha
{
    char elementos[MAX];
    int topo;
};

typedef struct pilha Pilha;

void criar (Pilha *p)
{
    p->topo = -1;
}

void destruir (Pilha *p)
{
    p->topo = -1;
}

bool vazia (Pilha p)
{

    if(p.topo == -1)
        return true;

    else
        return false;
}

bool cheia(Pilha p)
{
    if(p.topo == (MAX-1) )
        return true;

    else
        return false;
}

bool empilhar(Pilha *p, char x)
{

    bool deuCerto;

    if(cheia(*p)== true)
    {
        deuCerto = false;
        return deuCerto;
    }
    else
    {
        p->topo += 1;
        p->elementos[p->topo] = x;
        deuCerto = true;
        return deuCerto;
    }
}

bool desempilhar(Pilha *p, char *x){
    bool deuCerto;

    if(vazia(*p) == true){
        deuCerto = false;
        return deuCerto;
    }else{
        *x = p->elementos[p->topo];
        p->topo -= 1;
        deuCerto = true;
        return deuCerto;
    }

}

void desempilhaEmpilha(Pilha *p, Pilha *p2){

    char c;

    for(int i=0; i<4; i++){
        desempilhar(p, &c);
        empilhar(p2, c);
    }


}

void compara(Pilha *p, Pilha *p2){

    char c;
    char c1;


        for(int i=0; i<4; i++){
        desempilhar(p,&c);
        desempilhar(p2,&c1);
        if(c != c1){
            printf("Nao sao reverso..\n");
            exit(1);
        }

        }
}

void mostrar(char exp[], char exp1[]){

    printf("As expressoes sao do tipo XY\n");
    for(int i=0; i<4; i++){
        printf("%c", exp[i]);
    }
    for(int i=0; i<4; i++){
        printf("%c", exp1[i]);
    }



}




int main()
{

    Pilha p1;
    Pilha p2;
    Pilha p3;
    char c;
    char valor;
    bool deuCerto;
    char expX[MAX] = {"ABCD"};
    char expY[MAX] = {"DCBA"};

    criar(&p1);
    criar(&p2);
    criar(&p3);

    for(int i=0; i<4; i++)
    {
        c = expX[i];
        empilhar(&p1,c);
    }

    for(int i=0; i<4 ;i++){
        c = expY[i];
        empilhar(&p2,c);
    }

    desempilhaEmpilha(&p2, &p3);
    compara(&p1, &p3);
    mostrar(expX, expY);





    return 0;
}
