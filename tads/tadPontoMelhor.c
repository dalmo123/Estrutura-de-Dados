/*
    Este programa cria um TAD PONTO, no qual
    representa um ponto em R²
*/
#include <stdio.h>
#include <math.h>
/*
    Definição da estrutura de dados
    -dois inteiros representando coordenada x e y
*/

struct ponto
{
    int x;
    int y;
};

//Definição do Tipo de dados Ponto
typedef struct ponto Ponto;

/*
    Nome: criaPonto
    Entrada: Dois numeros inteiros indicando uma coordenada x,y
    Processo:cria um ponto com os valores das coordenadas x,y
             atribuindo os valores inseridos pelo usuario
    Saida : Um Ponto dado as coordenadas x,y inseridas.
*/

Ponto criaPonto(int X, int Y)
{

    Ponto p;

    p.x = X;
    p.y = Y;

    return p;

}

/*
    Nome: acessarCoordenada
    Entrada: Struct de um ponto contendo as coordendas x e y
    Processo: Mostrar a coordenda desses  passando a struct Ponto criada.
    Saida: coordendas do ponto sendo mostrada pro usuario
*/
void acessarCoordenada(Ponto pontoX)
{
    printf("%d %d \n", pontoX);
}

/*
    Nome: Calcula Distancia
    Entrada: Dois pontos nos quais, configuram as coordenadas x e y sendo x1,y1 e x2,y2
    Processo: Realiza o calculo da distancia entre 2 pontos dada as coordenadas x e y
    sendo feito da seguinte maneira:
    resul  = (x2 - x1)² + (y2-y1)
    resul  = sqrt(resul)
    Saida: Retorna o double resul indicando a distancia entre dois pontos dada coordenada x,y
*/
double calculaDistancia(int x1, int y1, int x2, int y2)
{
    double resul;

    resul = (x2-x1)*(x2-x1) + (y2-y1) * (y2-y1);
    resul = sqrt(resul);


    return resul;

}

int main()
{

    int x,y,x1,y1;
    double distancia;
    Ponto pontoA;
    Ponto pontoB;

    printf("Digite as coordenadas X do ponto A \n");
    scanf("%d", &x);

    printf("Digite as coordenadas Y do ponto A\n");
    scanf("%d", &y);
    pontoA = criaPonto(x,y);


    acessarCoordenada(pontoA);

    printf("Digite as coordenadas X do ponto B \n");
    scanf("%d", &x1);

    printf("Digite as coordenadas Y do ponto B \n");
    scanf("%d", &y1);

    pontoB = criaPonto(x1,y1);

    acessarCoordenada(pontoB);


    distancia = calculaDistancia(x,y,x1,y1);

    printf("Distancia entre dois pontos: %.2f", distancia);


    return 0 ;
}
