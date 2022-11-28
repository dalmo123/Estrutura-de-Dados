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



int main(){


    Pilha *p;
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

    while(x != 3)
    {

        printf("1- Empilhar\n");
        printf("2- Desempilahr\n");
        printf("3- Sair\n");

        printf("Escolha uma opcao...\n");
        scanf("%d", &x);

        if(x == 1)
        {
            printf("Digite o numero que deseja empilhar:: ");
            scanf("%d", &valor);
            deuCerto = empilhar(p,valor,tam);
            if(deuCerto)
            {
                printf("Foi empilhado..\n\n");
            }
            else
            {
                printf("Pilha Cheia..\n\n");
            }
        }

        if(x == 2)
        {
            deuCerto = desempilhar(p,&valor);
            if(deuCerto)
            {
                printf("Desempilhado:: %d \n\n", valor);
            }
            else
            {
                printf("Pilha vazia..\n\n");
            }

        }
    }




    destruir(p);

return 0;
}
