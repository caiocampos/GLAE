#include <stdlib.h>
#include <math.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include "forma.h"

// define o PI para evitar incompatibilidades
#define PI 3.1415926535897932384626

double tamBorda; // valor padr�o para tamanho de borda
cor corInterna; // valor padr�o para cor interna
cor corBorda; // valor padr�o para cor de borda
posicao posDesenho; // valor padr�o para posi��o de desenho

forma *geraPonto() {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 1; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POINTS; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras // anula o ponteiro para letras
	// come�a a instanciar os pontos
	f->pontos[0] = geraPosicao(0.0, 0.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraLinha(double tamanho) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 2; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINES; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	f->pontos[0] = geraPosicao(-tamanho / 2.0, 0.0);
	f->pontos[1] = geraPosicao(tamanho / 2.0,  0.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraTriangulo(double base, double altura) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 3; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_TRIANGLES; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	f->pontos[0] = geraPosicao(0.0,         altura * 2.0 / 3.0);
	f->pontos[1] = geraPosicao(base / 2.0,  -altura / 3.0);
	f->pontos[2] = geraPosicao(-base / 2.0, -altura / 3.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraTrianguloVazado(double base, double altura) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 3; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	f->pontos[0] = geraPosicao(0.0,         altura * 2.0 / 3.0);
	f->pontos[1] = geraPosicao(base / 2.0,  -altura / 3.0);
	f->pontos[2] = geraPosicao(-base / 2.0, -altura / 3.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraRetangulo(double base, double altura) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 4; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_QUADS; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	f->pontos[0] = geraPosicao(-base / 2.0, altura / 2.0);
	f->pontos[1] = geraPosicao(base / 2.0,  altura / 2.0);
	f->pontos[2] = geraPosicao(base / 2.0,  -altura / 2.0);
	f->pontos[3] = geraPosicao(-base / 2.0, -altura / 2.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraRetanguloVazado(double base, double altura) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 4; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	f->pontos[0] = geraPosicao(-base / 2.0, altura / 2.0);
	f->pontos[1] = geraPosicao(base / 2.0,  altura / 2.0);
	f->pontos[2] = geraPosicao(base / 2.0,  -altura / 2.0);
	f->pontos[3] = geraPosicao(-base / 2.0, -altura / 2.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraCirculo(double raio) {
	int i;
	double ang, passo;
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 360; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POLYGON; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posi��o relativa ao centro a partir do raio e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraCirculoVazado(double raio) {
	int i;
	double ang, passo;
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 360; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posi��o relativa ao centro a partir do raio e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraPoligono(double raio, int nVertices) {
	int i;
	double ang, passo;
	forma *f;
	if(nVertices < 3) return NULL; // verifica se o n�mero de v�rtices for menor que 3
	f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = nVertices; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(nVertices * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POLYGON; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	passo = 2 * PI / (double)f->qtdPontos; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posi��o relativa ao centro a partir do raio e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraPoligonoVazado(double raio, int nVertices) {
	int i;
	double ang, passo;
	forma *f;
	if(nVertices < 3) return NULL; // verifica se o n�mero de v�rtices for menor que 3
	f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = nVertices; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	passo = 2 * PI / (double)f->qtdPontos; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posi��o relativa ao centro a partir do raio e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraElipse(double raio1, double raio2) {
	int i;
	double ang, passo;
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 360; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POLYGON; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio1, sin(ang) * raio2); // gera a posi��o relativa ao centro a partir dos 2 raios e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraElipseVazado(double raio1, double raio2) {
	int i;
	double ang, passo;
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 360; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio1, sin(ang) * raio2); // gera a posi��o relativa ao centro a partir dos 2 raios e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraSetor(double raio, int angulo) {
	int i;
	double ang, passo;
	forma *f;
	if(angulo < 1 || angulo > 360) return NULL; // verifica se o �ngulo est� entre 1� e 360�
	f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = angulo + 2; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_TRIANGLE_FAN; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	f->pontos[0] = geraPosicao(0.0, 0.0); // gera o primeiro ponto na origem
	for (ang = 0, i = 1; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posi��o relativa ao centro a partir do raio e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraSetorVazado(double raio, int angulo) {
	int i;
	double ang, passo;
	forma *f;
	if(angulo < 1 || angulo > 360) return NULL; // verifica se o �ngulo est� entre 1� e 360�
	f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = angulo + 2; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	f->pontos[0] = geraPosicao(0.0, 0.0); // gera o primeiro ponto na origem
	for (ang = 0, i = 1; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posi��o relativa ao centro a partir do raio e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraArco(double raio, int angulo) {
	int i;
	double ang, passo;
	forma *f;
	if(angulo < 1 || angulo > 360) return NULL; // verifica se o �ngulo est� entre 1� e 360�
	f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = angulo + 1; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_TRIANGLE_FAN; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posi��o relativa ao centro a partir do raio e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraArcoVazado(double raio, int angulo) {
	int i;
	double ang, passo;
	forma *f;
	if(angulo < 1 || angulo > 360) return NULL; // verifica se o �ngulo est� entre 1� e 360�
	f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = angulo + 1; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posi��o relativa ao centro a partir do raio e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraArcoAberto(double raio, int angulo) {
	int i;
	double ang, passo;
	forma *f;
	if(angulo < 1 || angulo > 360) return NULL; // verifica se o �ngulo est� entre 1� e 360�
	f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = angulo + 1; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_STRIP; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posi��o relativa ao centro a partir do raio e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}


forma *geraEstrela(double raio1, double raio2, int nPontas) {
	int i;
	double ang, passo;
	forma *f;
	if(nPontas < 2) return NULL; // verifica se o n�mero de pontas � menor que 2
	f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = nPontas * 2; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POLYGON; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	ang = PI / 2.0; // define o �ngulo inicial
	passo = 2 * PI / (double)f->qtdPontos; // calcula o passo
	for (i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = i % 2 ? geraPosicao(cos(ang) * raio2, sin(ang) * raio2)
							 : geraPosicao(cos(ang) * raio1, sin(ang) * raio1); // gera a posi��o relativa ao centro a partir dos 2 raios e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraEstrelaVazado(double raio1, double raio2, int nPontas) {
	int i;
	double ang, passo;
	forma *f;
	if(nPontas < 2) return NULL; // verifica se o n�mero de pontas � menor que 2
	f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = nPontas * 2; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	ang = PI / 2.0; // define o �ngulo inicial
	passo = 2 * PI / (double)f->qtdPontos; // calcula o passo
	for (i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = i % 2 ? geraPosicao(cos(ang) * raio2, sin(ang) * raio2)
							 : geraPosicao(cos(ang) * raio1, sin(ang) * raio1); // gera a posi��o relativa ao centro a partir dos 2 raios e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraPentagrama(double raio1, double raio2) {
	int i;
	double ang, passo;
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 10; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POLYGON; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	ang = PI / 2.0; // define o �ngulo inicial
	passo = PI / 5.0; // calcula o passo
	for (i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = i % 2 ? geraPosicao(cos(ang) * raio2, sin(ang) * raio2)
							 : geraPosicao(cos(ang) * raio1, sin(ang) * raio1); // gera a posi��o relativa ao centro a partir dos 2 raios e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraPentagramaVazado(double raio1, double raio2) {
	int i;
	double ang, passo;
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 10; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	ang = PI / 2.0; // define o �ngulo inicial
	passo = PI / 5.0; // calcula o passo
	for (i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = i % 2 ? geraPosicao(cos(ang) * raio2, sin(ang) * raio2)
							 : geraPosicao(cos(ang) * raio1, sin(ang) * raio1); // gera a posi��o relativa ao centro a partir dos 2 raios e do �ngulo
		ang += passo; // incrementa o �ngulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraSeta(double proporcao) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 7; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_TRIANGLE_FAN; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	f->pontos[0] = geraPosicao(proporcao * 1.0,  proporcao * 0.0);
	f->pontos[1] = geraPosicao(proporcao * 0.0,  proporcao * 1.0);
	f->pontos[2] = geraPosicao(proporcao * 0.0,  proporcao * 0.5);
	f->pontos[3] = geraPosicao(proporcao * -1.0, proporcao * 0.5);
	f->pontos[4] = geraPosicao(proporcao * -1.0, proporcao * -0.5);
	f->pontos[5] = geraPosicao(proporcao * 0.0,  proporcao * -0.5);
	f->pontos[6] = geraPosicao(proporcao * 0.0,  proporcao * -1.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraSetaVazado(double proporcao) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	f->qtdPontos = 7; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// come�a a instanciar os pontos
	f->pontos[0] = geraPosicao(proporcao * 1.0,  proporcao * 0.0);
	f->pontos[1] = geraPosicao(proporcao * 0.0,  proporcao * 1.0);
	f->pontos[2] = geraPosicao(proporcao * 0.0,  proporcao * 0.5);
	f->pontos[3] = geraPosicao(proporcao * -1.0, proporcao * 0.5);
	f->pontos[4] = geraPosicao(proporcao * -1.0, proporcao * -0.5);
	f->pontos[5] = geraPosicao(proporcao * 0.0,  proporcao * -0.5);
	f->pontos[6] = geraPosicao(proporcao * 0.0,  proporcao * -1.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

int next_p2(int a) { // gera a pot�ncia de 2 mais pr�xima acima do valor a
	int rval = 1;
	while(rval < a) rval <<= 1;
	return rval;
}

forma *geraTexto(double tamanho, char *texto) {
	FT_Library library;
	FT_Face face;
	int i, j, l;
	double valx = 0, valy = 0, ay;
	forma *f;
	if(!texto || !texto[0]) return NULL; // verifica se o texto est� vazio
	f = (forma *)malloc(sizeof(forma)); // aloca espa�o para forma
	if(!f) return NULL; // verifica se o espa�o para a forma foi alocado
	l = 1; // inst�ncia l em 1
	while(texto[l]) l++; // incrementa o valor de l at� chegar no final do texto
	f->qtdLetras = l; // inst�ncia a quantidade de letras
	f->qtdPontos = 4 * f->qtdLetras; // inst�ncia a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espa�o para os pontos
	if(!f->pontos) { // verifica se o espa�o para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_QUADS; // inst�ncia o tipo de desenho
	f->corInterna = corInterna; // inst�ncia a cor
	f->corBorda = corBorda; // inst�ncia a cor da borda
	f->tamBorda = tamBorda; // inst�ncia o tamanho da borda
	f->pos = posDesenho; // inst�ncia a posi��o
	f->nJanelas = 0; // inst�ncia o n�mero de janelas
	// come�a a instanciar a textura
	f->letras = (textura **)malloc(f->qtdLetras * sizeof(textura *)); // aloca espa�o para as letras
	if(!f->letras
	|| FT_Init_FreeType(&library)
	|| FT_New_Face(library, "arial.ttf", 0, &face)
	|| FT_Set_Char_Size(face, (FT_F26Dot6)0, (FT_F26Dot6)(tamanho * 64), (FT_UInt)0, (FT_UInt)300)) { // verifica se alocou o espa�o para as letras e iniciou os elementos geradores das texturas
		destroiForma(f); // destr�i a forma
		FT_Done_Face(face); // finaliza a face da fonte
        FT_Done_FreeType(library); // finaliza a biblioteca FreeType
		return NULL; // retorna valor nulo
	}
	for(l = 0; l < f->qtdLetras; l++) {
		f->letras[l] = (textura *)malloc(sizeof(textura)); // aloca a textura da letra
		if(!f->letras[l]
		|| FT_Load_Glyph(face, FT_Get_Char_Index(face, texto[l]), FT_LOAD_DEFAULT)
		|| FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL)) { // verifica se alocou espa�o para a letra e se conseguiu gerar ela
			destroiForma(f); // destr�i a forma
			FT_Done_Face(face); // finaliza a face da fonte
			FT_Done_FreeType(library); // finaliza a biblioteca FreeType
			return NULL; // retorna valor nulo
		}
		f->letras[l]->x = face->glyph->bitmap.width; // inst�ncia o tamanho horizontal  da imagem
		f->letras[l]->y = face->glyph->bitmap.rows; // inst�ncia o tamanho vertical  da imagem
		f->letras[l]->xprop = next_p2(f->letras[l]->x); // inst�ncia a margem horizontal da imagem
		f->letras[l]->yprop = next_p2(f->letras[l]->y); // inst�ncia a margem vertical da imagem
		f->letras[l]->bmp = (ubyte *)calloc(2 * f->letras[l]->xprop * f->letras[l]->yprop, sizeof(ubyte)); // aloca espa�o para o bitmap da textura
		if(!f->letras[l]->bmp) { // verifica se alocou espa�o para o bitmap da imagem
			destroiForma(f); // destr�i a forma
			FT_Done_Face(face); // finaliza a face da fonte
			FT_Done_FreeType(library); // finaliza a biblioteca FreeType
			return NULL; // retorna valor nulo
		}
		// inicio da �rea onde a imagem da letra � copiada para o bitmap da textura
		for(j = 0; j < f->letras[l]->y; j++) {
            for(i = 0; i < f->letras[l]->x; i++) {
				f->letras[l]->bmp[2 * j * f->letras[l]->xprop + i]     =
				f->letras[l]->bmp[2 * j * f->letras[l]->xprop + i + 1] =
				face->glyph->bitmap.buffer[j * f->letras[l]->x + i];
			}
		}
		// fim da �rea onde a imagem da letra � copiada para o bitmap da textura
		ay = face->glyph->bitmap_top - face->glyph->bitmap.rows; // altera a posi��o vertical onde a moldura da fonte ser� gerada
		valx += face->glyph->bitmap_left; // incrementa a posi��o horizontal onde a moldura da fonte ser� gerada
		// inicio da �rea onde s�o definidos os pontos da moldura
		f->pontos[4 * l]     = geraPosicao(valx,                   ay + f->letras[l]->y);
		f->pontos[4 * l + 1] = geraPosicao(valx,                   ay);
		f->pontos[4 * l + 2] = geraPosicao(valx + f->letras[l]->x, ay);
		f->pontos[4 * l + 3] = geraPosicao(valx + f->letras[l]->x, ay + f->letras[l]->y);
		// fim da �rea onde s�o definidos os pontos da moldura
		valx += face->glyph->advance.x >> 7; // incrementa a posi��o horizontal onde a pr�xima moldura ser� gerada
		ay = ay + f->letras[l]->y; // coloca em ay o tamanho vertical usado pela fonte
		if(ay > valy) valy = ay; // se ay � maior que valy, ent�o inst�ncia o valor de valy com ay
		// no fim valy e valx v�o possuir o tamanho m�ximo do texto na vertical e horizontal respectivamente
	}
	valx /= -2.0; // inst�ncia o valx com a metade do valor do valx original negativado
	valy /= -2.0; // inst�ncia o valy com a metade do valor do valy original negativado
	// in�cio da �rea onde � somado a todos os pontos de todas as molduras os valores valx e valy
	// para que o texto fique centralizado com o ponto de origem
	for(l = 0; l < f->qtdLetras; l++) {
		f->pontos[4 * l].x     += valx;
		f->pontos[4 * l + 1].x += valx;
		f->pontos[4 * l + 2].x += valx;
		f->pontos[4 * l + 3].x += valx;
		f->pontos[4 * l].y     += valy;
		f->pontos[4 * l + 1].y += valy;
		f->pontos[4 * l + 2].y += valy;
		f->pontos[4 * l + 3].y += valy;
	}
	// fim da �rea onde � somado a todos os pontos de todas as molduras os valores valx e valy
	// para que o texto fique centralizado com o ponto de origem
	FT_Done_Face(face); // finaliza a face da fonte
	FT_Done_FreeType(library); // finaliza a biblioteca FreeType
	redimensionar(f, 0.25, 0.25); // divide por 4 o tamanho da forma
	return f; // retorna a forma f
}

int destroiForma(forma *f) {
	int i;
	if(!f || f->nJanelas > 0) return -1; // se existir alguma janela usando a forma f, sai da fun��o
	if(f->letras) { // verifica se as letras est�o alocadas
		for(i = 0; i < f->qtdLetras; i++) {
			if(f->letras[i]) { // verifica se a letra na posi��o i est� alocada
                free(f->letras[i]->bmp); // libera o bitmap
                free(f->letras[i]); // libera a letra
			}
		}
		f->qtdLetras = 0; // zera o n�mero de letras
		free(f->letras); // libera o vetor de letras
	}
	f->qtdPontos = 0; // zera o n�mero de pontos
	free(f->pontos); // libera a mem�ria usada pelos pontos
	free(f); // libera a mem�ria usada pela forma f
	return 0; // retorna sucesso
}

void definePosicao(double x, double y) {
	posDesenho = geraPosicao(x, y); // define a posi��o atual para desenho
}

void defineTamanhoBorda(double t) {
	if(t > 0.0 && t <= 15.0) tamBorda = t; // define o tamanho atual para a borda
}

void defineCorInterna(int vermelho, int verde, int azul) {
	corInterna = geraCor(vermelho, verde, azul); // define a cor atual para a parte interna da forma
}

void defineCorBorda(int vermelho, int verde, int azul) {
	corBorda = geraCor(vermelho, verde, azul); // define a cor atual para pontos, linhas e bordas de forma
}

void rodar(forma *f, double a) {
	int i;
	double aux;
	double a1 = a * PI / 180.0; // �ngulo a em radiano
	double sa = sin(a1); // seno do �ngulo a
	double ca = cos(a1); // cosseno do �ngulo a
	for(i = 0; i < f->qtdPontos; i++) { // enquanto houver pontos
		aux            = f->pontos[i].x * ca - f->pontos[i].y * sa; // rotaciona a posi��o x em rela��o ao centro
		f->pontos[i].y = f->pontos[i].x * sa + f->pontos[i].y * ca; // rotaciona a posi��o y em rela��o ao centro
		f->pontos[i].x = aux; // inst�ncia novamente a posi��o x
	}
}

void redimensionar(forma *f, double x, double y) {
	int i;
	for(i = 0; i < f->qtdPontos; i++) { // enquanto houver pontos
		f->pontos[i].x *= x; // altera, a certa porcentagem, a dist�ncia de x do centro
		f->pontos[i].y *= y; // altera, a certa porcentagem, a dist�ncia de y do centro
	}
}

void mover(forma *f, double x, double y) {
	f->pos.x += x; // move a posi��o de x
	f->pos.y += y; // move a posi��o de y
}

void moverPara(forma *f, double x, double y) {
	f->pos.x = x; // move a posi��o de x
	f->pos.y = y; // move a posi��o de y
}

void mudaTexto(forma *f, double tamanho, char *texto) {
	forma *aux, *temp;
	mtx_t mutex;
	if(mtx_init(&mutex, mtx_plain) != thrd_success) return; // tenta inicializar a trava de exclus�o m�tua
	temp = (forma *)malloc(sizeof(forma)); // aloca espa�o para a forma de c�pia
	if(!temp) return; // verifica se foi alocado espa�o para a forma de c�pia
	aux = geraTexto(tamanho, texto); // gera o novo texto
	if(!aux) return; // verifica se foi poss�vel gerar o novo texto
	mtx_lock(&mutex); // inicia a trava de exclus�o mutua
	// in�cio da �rea onde os dados em f s�o passados para temp
	temp->pontos     = f->pontos;
	temp->qtdPontos  = f->qtdPontos;
	temp->tipo       = f->tipo;
	temp->corInterna = f->corInterna;
	temp->corBorda   = f->corBorda;
	temp->tamBorda   = f->tamBorda;
	temp->pos        = f->pos;
	temp->letras     = f->letras;
	temp->qtdLetras  = f->qtdLetras;
	temp->nJanelas   = f->nJanelas;
	// fim da �rea onde os dados em f s�o passados para temp
	// in�cio da �rea onde os dados em aux s�o passados para f
    f->pontos     = aux->pontos;
	f->qtdPontos  = aux->qtdPontos;
	f->tipo       = aux->tipo;
	f->corInterna = aux->corInterna;
	f->corBorda   = aux->corBorda;
	f->tamBorda   = aux->tamBorda;
	f->pos        = aux->pos;
	f->letras     = aux->letras;
	f->qtdLetras  = aux->qtdLetras;
	f->nJanelas   = aux->nJanelas;
	// fim da �rea onde os dados em aux s�o passados para f
    destroiForma(temp); // destr�i a forma antiga
    free(aux); // libera o espa�o de aux
	mtx_unlock(&mutex); // libera a trava de exclus�o m�tua
	mtx_destroy(&mutex); // destr�i a trava de exclus�o m�tua
}

void mudaTamanhoBorda(forma *f, double t) {
	if(f && t > 0.0 && t <= 15.0) f->tamBorda = t; // muda o tamanho da borda na forma
}

void mudaCorInterna(forma *f, GLubyte vermelho, GLubyte verde, GLubyte azul) {
	if(f) f->corInterna = geraCor(vermelho, verde, azul); // muda a cor interna da forma
}

void mudaCorBorda(forma *f, GLubyte vermelho, GLubyte verde, GLubyte azul) {
	if(f) f->corBorda = geraCor(vermelho, verde, azul); // muda a cor da borda da forma
}
