#include <stdio.h>
#include <stdbool.h>
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

//passar o char pra pegar o valor desempilhado
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

int main ()
{

    bool teste;
    Pilha pi;

    criar(&pi);

    teste = empilhar(&pi, 'A');
    if(teste == false){
        printf("Nao foi possivel inserir\n");
    }
    teste = empilhar(&pi, 'B');
    if(teste == false){
        printf("Nao foi possivel inserir\n");
    }
    teste = empilhar(&pi, 'C');
    if(teste == false){
        printf("Nao foi possivel inserir\n");
    }
    teste = empilhar(&pi, 'D');
    if(teste == false){
        printf("Nao foi possivel inserir\n");
    }
    teste = empilhar(&pi, 'E');
    if(teste == false){
        printf("Nao foi possivel inserir\n");
    }
    teste = empilhar(&pi, 'F');
    if(teste == false){
        printf("Nao foi possivel inserir\n");
    }

    char valor;

    teste = desempilhar(&pi, &valor);
    if(teste == false){
        printf("Nao foi possivel desempilhar\n");
    }else{
        printf("Foi desempilhado..\n");
        printf("%c\n\n", valor);
    }
    teste = desempilhar(&pi, &valor);
    if(teste == false){
        printf("Nao foi possivel desempilhar\n");
    }else{
        printf("Foi desempilhado..\n");
        printf("%c\n\n", valor);
    }
    teste = desempilhar(&pi, &valor);
    if(teste == false){
        printf("Nao foi possivel desempilhar\n");
    }else{
        printf("Foi desempilhado..\n");
        printf("%c\n\n", valor);
    }

    printf("%d", pi.topo);

    destruir(&pi);


    return 0 ;
}
