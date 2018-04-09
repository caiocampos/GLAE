#include "tinycthread.h"
#include "extra.h"

#ifndef GLAE_FORMA
#define GLAE_FORMA

typedef struct forma forma; // cria o tipo forma

struct forma { // estrutura que define uma forma
	posicao *pontos; // pontos da forma
	int qtdPontos; // quantidade de pontos que a forma possui
	int tipo; // tipo de desenho a ser usado
	cor corInterna; // cor da forma
	cor corBorda; // cor de borda
	double tamBorda; // espessura da borda
	posicao pos; // posi��o central onde a forma ser� desenhada
	textura **letras; // lista de texturas que representam letras
	int qtdLetras; // n�mero de letras
	int nJanelas; // n�mero de janelas que usam essa forma
};

forma *geraPonto(); // gera um ponto a partir dos par�metros
forma *geraLinha(double tamanho); // gera uma linha a partir dos par�metros
forma *geraTriangulo(double base, double altura); // gera um tri�ngulo a partir dos par�metros
forma *geraTrianguloVazado(double base, double altura); // gera um tri�ngulo a partir dos par�metros
forma *geraRetangulo(double base, double altura); // gera um ret�ngulo a partir dos par�metros
forma *geraRetanguloVazado(double base, double altura); // gera um ret�ngulo a partir dos par�metros
forma *geraCirculo(double raio); // gera um c�rculo a partir dos par�metros
forma *geraCirculoVazado(double raio); // gera um c�rculo a partir dos par�metros
forma *geraPoligono(double raio, int nVertices); // gera um pol�gono regular a partir dos par�metros
forma *geraPoligonoVazado(double raio, int nVertices); // gera um pol�gono regular a partir dos par�metros
forma *geraElipse(double raio1, double raio2); // gera uma elipse a partir dos par�metros
forma *geraElipseVazado(double raio1, double raio2); // gera uma elipse a partir dos par�metros
forma *geraSetor(double raio, int angulo); // gera um setor a partir dos par�metros
forma *geraSetorVazado(double raio, int angulo); // gera um setor a partir dos par�metros
forma *geraArco(double raio, int angulo); // gera um arco a partir dos par�metros
forma *geraArcoVazado(double raio, int angulo); // gera um arco a partir dos par�metros
forma *geraArcoAberto(double raio, int angulo); // gera um arco a partir dos par�metros
forma *geraEstrela(double raio1, double raio2, int nPontas); // gera uma estrela a partir dos par�metros
forma *geraEstrelaVazado(double raio1, double raio2, int nPontas); // gera uma estrela a partir dos par�metros
forma *geraPentagrama(double raio1, double raio2); // gera um pentagrama a partir dos par�metros
forma *geraPentagramaVazado(double raio1, double raio2); // gera um pentagrama a partir dos par�metros
forma *geraSeta(double proporcao); // gera uma seta a partir dos par�metros
forma *geraSetaVazado(double proporcao); // gera uma seta a partir dos par�metros
forma *geraTexto(double tamanho, char *texto); // gera um texto a partir dos par�metros
int destroiForma(forma *f); // tenta liberar a mem�ria usada pela forma f

void definePosicao(double x, double y); // define a posi��o onde as pr�ximas formas ser�o geradas
void defineTamanhoBorda(double t); // define o tamanho da borda das pr�ximas formas que ser�o geradas
void defineCorInterna(int vermelho, int verde, int azul); // define a cor interna das pr�ximas formas que ser�o geradas
void defineCorBorda(int vermelho, int verde, int azul); // define a cor de borda das pr�ximas formas que ser�o geradas

void rodar(forma *f, double a); // roda a forma
void redimensionar(forma *f, double x, double y); // redimensiona a forma nos eixos x e y
void mover(forma *f, double x, double y); // move a forma nos eixos x e y
void moverPara(forma *f, double x, double y); // move a forma para determinada posi��o

void mudaTexto(forma *f, double tamanho, char *texto); // atualiza o texto exibido pela forma
void mudaTamanhoBorda(forma *f, double t); // atualiza o tamanho de borda da forma
void mudaCorInterna(forma *f, GLubyte vermelho, GLubyte verde, GLubyte azul); // atualiza a cor interna da forma
void mudaCorBorda(forma *f, GLubyte vermelho, GLubyte verde, GLubyte azul); // atualiza a cor de borda da forma

#endif // GLAE_FORMA
