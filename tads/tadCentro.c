/*
    Este programa utliza um TAD Ponto, no qual
    representa um ponto em R² com cordenada x e y
    e tem o intuito de criar um novo TAD Circulo
    utilizando o tad Ponto criado
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
    Definição da estrutura de dados para Ponto
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
    Definição da estrutura de dados para Circulo
    utilizando a Struct ponto e com um inteiro representando o raio
*/
struct circulo
{
    Ponto ponto;
    int raio;
};

typedef struct circulo Circulo;

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
    Nome: criaCirculo
    Entrada: De entrada teremos um int raio e uma Struct do tipo ponto
    Processo:Atribui o ponto criado pra dentro da struct circulo e adiciona o raio
    Saida : Um circulo com coordenadas x e y e raio.
*/
Circulo criaCirculo(Ponto ponto,int raio){
    Circulo c;

    c.ponto = ponto;
    c.raio = raio;

    return c;

}
/*
    Nome: calculaArea
    Entrada: Recebe uma struct do tipo circulo
    Processo: É feito o calculo da area atraves da formula:
    A = pi * r^2
    Saida: De saida temos a area do circulo
*/
double calculaArea(Circulo c){
    double area;
    float pi = 3.14;

    area = pi* c.raio * c.raio ;



    return area;

}
/*
    Nome: verificaPonto
    Entrada: Pontos x1,y1(indicando os pontos do centro do circulo), x2,y2(do ponto a comparar) e raio do circulo
    Processo: Realiza o calculo da distancia entre 2 pontos dada as coordenadas x e y
    sendo feito da seguinte maneira:
    resul  = (x2 - x1)² + (y2-y1)
    resul  = sqrt(resul)
    se resul < raio, significa que o ponto está dentro do circulo
    Saida: Retorna um bool de true se estiver contido e false se nao estiver, alem de uma mensagem quando estiver contido.
*/

//OBS: Queria passar de entrada pra func Circ e o novo ponto como pontoTeste para diminuir os paramentros
// mas tive dificuldade na hora de calcular  ..

bool verificaPonto(int x1, int y1, int x2, int y2, int raio)
{
    bool teste = false;
    double resul;

    resul = (x2-x1)*(x2-x1) + (y2-y1) * (y2-y1);
    resul = sqrt(resul);


    if(resul < raio){
        teste = true;
        printf("O ponto inserido esta contido no circulo!!\n");
        return teste;
    }

    return teste;

}


int main()
{

    int x,y,x1,y1,raio;
    double resul;
    bool teste;
    Circulo circ;
    Ponto ponto;
    Ponto pontoTeste;

    printf("Digite as coordenadas X do ponto A \n");
    scanf("%d", &x);

    printf("Digite as coordenadas Y do ponto A\n");
    scanf("%d", &y);

    ponto = criaPonto(x,y);


    printf("Insira um raio pro circulo: ");
    scanf("%d", &raio);

    circ = criaCirculo(ponto,raio);

    printf("Coordenadas do Circulo:\nCoord X: %d\nCoord Y: %d\nRaio: %d\n",circ.ponto.x,circ.ponto.y,circ.raio);

    resul = calculaArea(circ);

    printf("Area do circulo: %.2f\n", resul);


    printf("Novo ponto teste: \n");

    printf("Insira a coordenada X do ponto\n");
    scanf("%d", &x1);

    printf("Insira a coordenada Y do ponto\n");
    scanf("%d", &y1);


    teste = verificaPonto(x,y,x1,y1,raio);

    printf("%s", teste ? "true" : "false");


    return 0 ;
}
