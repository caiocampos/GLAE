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
	posicao pos; // posição central onde a forma será desenhada
	textura **letras; // lista de texturas que representam letras
	int qtdLetras; // número de letras
	int nJanelas; // número de janelas que usam essa forma
};

forma *geraPonto(); // gera um ponto a partir dos parâmetros
forma *geraLinha(double tamanho); // gera uma linha a partir dos parâmetros
forma *geraTriangulo(double base, double altura); // gera um triângulo a partir dos parâmetros
forma *geraTrianguloVazado(double base, double altura); // gera um triângulo a partir dos parâmetros
forma *geraRetangulo(double base, double altura); // gera um retângulo a partir dos parâmetros
forma *geraRetanguloVazado(double base, double altura); // gera um retângulo a partir dos parâmetros
forma *geraCirculo(double raio); // gera um círculo a partir dos parâmetros
forma *geraCirculoVazado(double raio); // gera um círculo a partir dos parâmetros
forma *geraPoligono(double raio, int nVertices); // gera um polígono regular a partir dos parâmetros
forma *geraPoligonoVazado(double raio, int nVertices); // gera um polígono regular a partir dos parâmetros
forma *geraElipse(double raio1, double raio2); // gera uma elipse a partir dos parâmetros
forma *geraElipseVazado(double raio1, double raio2); // gera uma elipse a partir dos parâmetros
forma *geraSetor(double raio, int angulo); // gera um setor a partir dos parâmetros
forma *geraSetorVazado(double raio, int angulo); // gera um setor a partir dos parâmetros
forma *geraArco(double raio, int angulo); // gera um arco a partir dos parâmetros
forma *geraArcoVazado(double raio, int angulo); // gera um arco a partir dos parâmetros
forma *geraArcoAberto(double raio, int angulo); // gera um arco a partir dos parâmetros
forma *geraEstrela(double raio1, double raio2, int nPontas); // gera uma estrela a partir dos parâmetros
forma *geraEstrelaVazado(double raio1, double raio2, int nPontas); // gera uma estrela a partir dos parâmetros
forma *geraPentagrama(double raio1, double raio2); // gera um pentagrama a partir dos parâmetros
forma *geraPentagramaVazado(double raio1, double raio2); // gera um pentagrama a partir dos parâmetros
forma *geraSeta(double proporcao); // gera uma seta a partir dos parâmetros
forma *geraSetaVazado(double proporcao); // gera uma seta a partir dos parâmetros
forma *geraTexto(double tamanho, char *texto); // gera um texto a partir dos parâmetros
int destroiForma(forma *f); // tenta liberar a memória usada pela forma f

void definePosicao(double x, double y); // define a posição onde as próximas formas serão geradas
void defineTamanhoBorda(double t); // define o tamanho da borda das próximas formas que serão geradas
void defineCorInterna(int vermelho, int verde, int azul); // define a cor interna das próximas formas que serão geradas
void defineCorBorda(int vermelho, int verde, int azul); // define a cor de borda das próximas formas que serão geradas

void rodar(forma *f, double a); // roda a forma
void redimensionar(forma *f, double x, double y); // redimensiona a forma nos eixos x e y
void mover(forma *f, double x, double y); // move a forma nos eixos x e y
void moverPara(forma *f, double x, double y); // move a forma para determinada posição

void mudaTexto(forma *f, double tamanho, char *texto); // atualiza o texto exibido pela forma
void mudaTamanhoBorda(forma *f, double t); // atualiza o tamanho de borda da forma
void mudaCorInterna(forma *f, GLubyte vermelho, GLubyte verde, GLubyte azul); // atualiza a cor interna da forma
void mudaCorBorda(forma *f, GLubyte vermelho, GLubyte verde, GLubyte azul); // atualiza a cor de borda da forma

#endif // GLAE_FORMA
