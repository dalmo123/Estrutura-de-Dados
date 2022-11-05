#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX  50

struct pilha
{
    float elementos[MAX];
    int topo;
};

typedef struct pilha Pilha;
//criar, destruir, estaCheia, estaVazia, desempilha, empilha,

void criar (Pilha *p)
{
    p->topo = -1;
}

void destruir (Pilha *p)
{
    p-> topo = -1;
}

bool vazia(Pilha p)
{
    if(p.topo == -1)  return true;

    else return false;
}

bool cheia(Pilha p)
{
    if(p.topo == (MAX-1)) return true;
    else return false;
}

bool empilhar(Pilha *p, float x)
{
    bool deuCerto;

    if(cheia(*p) == true)
    {
        deuCerto = false;
        return deuCerto;
    }
    else
    {
        p->topo = p->topo + 1 ;
        p->elementos[p->topo] = x;
        deuCerto = true;
        return deuCerto;
    }
}

bool desempilhar(Pilha *p, float *x)
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
        p->topo = p->topo - 1;
        deuCerto = true;
        return deuCerto;
    }

}

float operacao(float A, float B, char x )
{

    switch(x)
    {

    case '+':
        return A + B;
        break;
    case '-':
        return A - B;
        break;
    case '/':
        return A / B;
        break;
    case '*':
        return A * B;
        break;
    default:
        return 0.0;
    }

}

float resolucao(char exp[])
{
    Pilha pi;
    char *p;
    float x,y;
    float resul, num;

    criar(&pi);

    p = strtok(exp, " ");

    while(p)
    {
        if(       p[0] == '+'
                  ||p[0] == '-'
                  ||p[0] == '*'
                  ||p[0] == '/')
        {
            desempilhar(&pi,&y);
            desempilhar(&pi,&x);
            resul = operacao(x,y,p[0]);
            empilhar(&pi, resul);
        }
        else
        {
            num = strtol(p, NULL, 10);
            empilhar(&pi, num);
        }

        p = strtok(NULL, " ");
    }

    desempilhar(&pi, &resul);

    destruir(&pi);

    return resul;
}




int main()
{
    //char exp[MAX] = {"5 3 2 4 6 7 1 + * + * + *"};
    char exp[MAX] = {"5 3 2 + * 4 / 6 -"};
    float resultado;

    printf("Resultado de %s:\t", exp);

    resultado = resolucao(exp);
    printf("%.2f\n", resultado);

    return 0;
}
