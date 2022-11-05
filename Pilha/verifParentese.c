#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 50

struct pilha
{
    char elementos[MAX];
    int topo;
};

typedef struct pilha Pilha;

//criar, destruir, empilhar, desempilhar, cheia, vazia
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
    if(p.topo == MAX -1)
        return true;

    return false;
}

bool vazia(Pilha p)
{
    if(p.topo == -1)
        return true;

    return false;
}

bool empilhar(Pilha *p, char *x)
{

    bool deuCerto;

    if(cheia(*p) == true)
    {
        deuCerto = false;
        return deuCerto;
    }
    else
    {
        p->topo = p->topo + 1;
        p->elementos[p->topo] = *x;
        deuCerto = true;
        return deuCerto;
    }

}

bool desempilhar(Pilha *p, char *x)
{

    bool deuCerto;

    if(vazia(*p) == true)
    {
        deuCerto = false;
        return deuCerto;
    }
    else
    {
        *x = p->elementos[p->topo];
        p->topo = p->topo -1;
        deuCerto = true;
        return deuCerto;
    }


}

bool resolver(char exp[])
{
    Pilha pi;
    char *pc;
    bool teste;

    criar(&pi);

    pc = strtok(exp, "");
    while(pc)
    {
        if (pc[0] == '(')
            empilhar(&pi,pc);

        else
            desempilhar(&pi,pc);

        pc = strtok(NULL, "");

    }


    teste = vazia(pi);

    return teste;


}

int main()
{
    Pilha pi;
    bool teste;
    char exp[MAX] = {"(())(()())()()"};
    //char exp[MAX] = {")((()())(("};



    teste = resolver(exp);
    if(teste == true)
        printf("Incorreto:%s \n", exp);
    else
        printf("Correto:%s \n",exp);



    return 0;
}
