#include<stdio.h>
#include<stdbool.h>


#define  MAX  10    // tamanho maximo do vetor

// Declaracao da estrutura de dados
struct vetor
{
    int elem[MAX];  // armazena os dados do vetor
    int tam;        // armazena o tamanho do vetor
};

// Definicao do tipo Vetor a partir da estrutura de dados
typedef struct vetor Vetor;

/*
 * Retorna o maior elemento do vetor
 */
int maior_v1(Vetor vet, int *erro)
{
    int i, m = -1;

    // tratamento de erro
    /* opções:
        2 - usar parametro auxiliar para erro
    */

    if (vet.tam == 0)
        *erro = 1;
    else
    {
        m = vet.elem[0];

        for (i = 1; i < vet.tam; i++)
            if (vet.elem[i] > m)
                m = vet.elem[i];
    }

    return m;
}

int maior(Vetor vet, int *m)
{
    int i;

    // tratamento de erro
    /* opções:
        1 - retornar um codigo de erro
            (0 se funcionou, 1 caso contrario)
    */

    if (vet.tam == 0)
        return 1;

    *m = vet.elem[0];
    for (i = 1; i < vet.tam; i++)
        if (vet.elem[i] > *m)
            *m = vet.elem[i];

    return 0;
}

int criar(Vetor *vet)
{
    vet->tam = 0;

    return 0; // nao tem erro
}

// Insere o valor x no vetor vet
int inserir(Vetor *vet, int x)
{
    int i;

    if (vet->tam >= MAX)
        return 1; // erro
    i = vet->tam;
    vet->elem[i] = x;
    vet->tam++;
    return 0; // nao tem erro


    // alternativamente
    // vet->elem[vet->tam++] = x;
}

bool procurar(Vetor vet, int *x)
{

    int compara;

    for(int i = 0 ; i < vet.tam ; i++)
    {

        if(vet.elem[i] == *x )
            return true;
    }

    return false;
}

void destruir(Vetor *vet)
{

    int x = 0;

    for(int i = 0 ; i < vet->tam ; i++)
    {
        //inserir(&vet,x);
        vet->elem[i] = 0 ;
    }

}

int main()
{

    int numero,maiorElemento, tam, x;
    Vetor vet;
    bool teste;


    criar(&vet);

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);


    for(int i = 0 ; i < tam; i++)
    {
        printf("Entre com um numero: ");
        scanf("%d", &numero);
        inserir(&vet, numero);
    }

    maior(vet, &maiorElemento);

    printf("O maior numero eh: %d\n", maiorElemento);

    x = 1 ;

    teste = procurar(vet, &x);

    if(teste == true)
    {
        printf("Esse numero foi encontrado no vetor..\n");
    }
    else
    {
        printf("Esse numero nao foi encontrado no vetor..\n");
    }

    destruir(&vet);

    for(int i = 0 ; i < vet.tam ; i++)
    {
        printf("o vet [%d] = %d\n",i, vet.elem[i]);
    }



    return 0;
}
