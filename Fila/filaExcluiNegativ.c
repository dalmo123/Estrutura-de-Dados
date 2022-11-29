#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct fila{
    int *elementos;
    int nr_elem;
    int inicio;
    int final;
};

typedef struct fila Fila;

Fila *criar(int size, bool *deuCerto){

    Fila *f;

    f = (Fila *) malloc(sizeof(Fila));

    if(f == NULL) *deuCerto = false;

    else{
        f->elementos = (int *) malloc(size * sizeof(int));
        if(f->elementos == NULL) *deuCerto = false;
        else{
            f->nr_elem = 0;
            f->inicio = 0;
            f->final = 0;
            *deuCerto = true;
        }
    }

    return f;
}

void destruir(Fila *f){

   free(f->elementos);
   free(f);
}

bool cheia(Fila *f, int size){

    if(f->nr_elem == size)
        return true;
    else
        return false;

}

bool vazia(Fila *f){

    if(f->nr_elem == 0)
        return true;
    else
        return false;

}

bool insere(Fila *f, int size, int valor){

    if(cheia(f,size))
        return false;

    else{
        f->elementos[f->final] = valor;
        f->nr_elem +=1 ;

        if(f->final == size-1) f->final = 0;
        else f->final += 1;

        return true;
    }
}

bool retira(Fila *f, int *valor, int size){

    if(vazia(f))
        return false;

    else{
        *valor = f->elementos[f->inicio];
        f->elementos[f->inicio] = 0;
        f->nr_elem -= 1;

        if(f->inicio == size-1) f->inicio = 0;
        else f->inicio += 1;
    }
}

bool retiraNegativos(Fila *f, int size){

    int valor;

    for(int i=0; i<size; i++){

        if(f->elementos[f->inicio] < 0){
            retira(f,&valor,size);
            printf("Removido:%d Posicao %d\n", valor, f->inicio);
        }else{
            f->inicio += 1;
            continue;
        }

    }

    printf("\n\n");
}

void mostrar(Fila *f, int size){

    f->inicio = 0;

    for(int i=0; i<size; i++){
        printf("%d \n", f->elementos[f->inicio]);
        f->inicio += 1;
    }
}


int main(){


    Fila *f;
    int size,valor;
    bool deuCerto;

    printf("Insira o tamanho da fila: ");
    scanf("%d", &size);

    f = criar(size,&deuCerto);
    if(deuCerto == false){
        printf("Nao foi possivel alocar a fila..");
        exit(1);
    }

    while(cheia(f,size) == false){
        printf("Insira um numero pra fila:: ");
        scanf("%d", &valor);
        insere(f,size,valor);
    }

    retiraNegativos(f,size);

    mostrar(f,size);

    destruir(f);


return 0;
}
