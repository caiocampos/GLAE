#include "tinycthread.h"
#include "extra.h"

typedef struct {/* estrutura que define uma forma */
	posicao *pontos; /* pontos da forma */
	int qtdPontos;/* quantidade de pontos que a forma possui */
	int tipo;/* tipo de desenho a ser usado */
	cor corInterna;/* cor da forma */
	cor corBorda;
	double tamBorda;
	posicao pos;/* posição central onde a forma será desenhada */
	textura **letras;
	int qtdLetras;
	int nJanelas;/* número de janelas que usam essa forma */
} forma;

forma *geraPonto(); /* gera um ponto a partir dos parâmetros */
forma *geraLinha(double tamanho); /* gera uma linha a partir dos parâmetros */
forma *geraTriangulo(double base, double altura); /* gera um triângulo a partir dos parâmetros */
forma *geraTrianguloVazado(double base, double altura); /* gera um triângulo a partir dos parâmetros */
forma *geraRetangulo(double base, double altura); /* gera um retângulo a partir dos parâmetros */
forma *geraRetanguloVazado(double base, double altura); /* gera um retângulo a partir dos parâmetros */
forma *geraCirculo(double raio); /* gera um círculo a partir dos parâmetros */
forma *geraCirculoVazado(double raio); /* gera um círculo a partir dos parâmetros */
forma *geraPoligono(double raio, int nVertices);
forma *geraPoligonoVazado(double raio, int nVertices);
forma *geraElipse(double raio1, double raio2);
forma *geraElipseVazado(double raio1, double raio2);
forma *geraSetor(double raio, int angulo);
forma *geraSetorVazado(double raio, int angulo);
forma *geraArco(double raio, int angulo);
forma *geraArcoVazado(double raio, int angulo);
forma *geraArcoAberto(double raio, int angulo);
forma *geraEstrela(double raio1, double raio2, int nPontas);
forma *geraEstrelaVazado(double raio1, double raio2, int nPontas);
forma *geraPentagrama(double raio1, double raio2);
forma *geraPentagramaVazado(double raio1, double raio2);
forma *geraSeta(double proporcao);
forma *geraSetaVazado(double proporcao);
forma *geraTexto(double tamanho, char *texto);
int destroiForma(forma *f); /* tenta liberar a memória usada pela forma f */

void definePosicao(double x, double y);
void defineTamanhoBorda(double t);
void defineCorInterna(GLubyte vermelho, GLubyte verde, GLubyte azul);
void defineCorBorda(GLubyte vermelho, GLubyte verde, GLubyte azul);

void rodar(forma *f, double a); /* roda a forma */
void redimensionar(forma *f, double x, double y); /* redimensiona a forma nos eixos x e y */
void mover(forma *f, double x, double y); /* move a forma nos eixos x e y */
void moverPara(forma *f, double x, double y);

void mudaTexto(forma *f, double tamanho, char *texto);
void mudaTamanhoBorda(forma *f, double t);
void mudaCorInterna(forma *f, GLubyte vermelho, GLubyte verde, GLubyte azul);
void mudaCorBorda(forma *f, GLubyte vermelho, GLubyte verde, GLubyte azul);

int formaMutexInit();
void formaMutexDestroy();