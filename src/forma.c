#include <stdlib.h>
#include <math.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include "forma.h"

// define o PI para evitar incompatibilidades
#define PI 3.1415926535897932384626

double tamBorda; // valor padrão para tamanho de borda
cor corInterna; // valor padrão para cor interna
cor corBorda; // valor padrão para cor de borda
posicao posDesenho; // valor padrão para posição de desenho

forma *geraPonto() {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 1; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POINTS; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras // anula o ponteiro para letras
	// começa a instanciar os pontos
	f->pontos[0] = geraPosicao(0.0, 0.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraLinha(double tamanho) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 2; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINES; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	f->pontos[0] = geraPosicao(-tamanho / 2.0, 0.0);
	f->pontos[1] = geraPosicao(tamanho / 2.0,  0.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraTriangulo(double base, double altura) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 3; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_TRIANGLES; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	f->pontos[0] = geraPosicao(0.0,         altura * 2.0 / 3.0);
	f->pontos[1] = geraPosicao(base / 2.0,  -altura / 3.0);
	f->pontos[2] = geraPosicao(-base / 2.0, -altura / 3.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraTrianguloVazado(double base, double altura) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 3; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	f->pontos[0] = geraPosicao(0.0,         altura * 2.0 / 3.0);
	f->pontos[1] = geraPosicao(base / 2.0,  -altura / 3.0);
	f->pontos[2] = geraPosicao(-base / 2.0, -altura / 3.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraRetangulo(double base, double altura) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 4; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_QUADS; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	f->pontos[0] = geraPosicao(-base / 2.0, altura / 2.0);
	f->pontos[1] = geraPosicao(base / 2.0,  altura / 2.0);
	f->pontos[2] = geraPosicao(base / 2.0,  -altura / 2.0);
	f->pontos[3] = geraPosicao(-base / 2.0, -altura / 2.0);
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraRetanguloVazado(double base, double altura) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 4; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
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
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 360; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POLYGON; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posição relativa ao centro a partir do raio e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraCirculoVazado(double raio) {
	int i;
	double ang, passo;
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 360; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posição relativa ao centro a partir do raio e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraPoligono(double raio, int nVertices) {
	int i;
	double ang, passo;
	forma *f;
	if(nVertices < 3) return NULL; // verifica se o número de vértices for menor que 3
	f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = nVertices; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(nVertices * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POLYGON; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	passo = 2 * PI / (double)f->qtdPontos; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posição relativa ao centro a partir do raio e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraPoligonoVazado(double raio, int nVertices) {
	int i;
	double ang, passo;
	forma *f;
	if(nVertices < 3) return NULL; // verifica se o número de vértices for menor que 3
	f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = nVertices; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	passo = 2 * PI / (double)f->qtdPontos; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posição relativa ao centro a partir do raio e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraElipse(double raio1, double raio2) {
	int i;
	double ang, passo;
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 360; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POLYGON; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio1, sin(ang) * raio2); // gera a posição relativa ao centro a partir dos 2 raios e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraElipseVazado(double raio1, double raio2) {
	int i;
	double ang, passo;
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 360; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio1, sin(ang) * raio2); // gera a posição relativa ao centro a partir dos 2 raios e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraSetor(double raio, int angulo) {
	int i;
	double ang, passo;
	forma *f;
	if(angulo < 1 || angulo > 360) return NULL; // verifica se o ângulo está entre 1° e 360°
	f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = angulo + 2; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_TRIANGLE_FAN; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	f->pontos[0] = geraPosicao(0.0, 0.0); // gera o primeiro ponto na origem
	for (ang = 0, i = 1; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posição relativa ao centro a partir do raio e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraSetorVazado(double raio, int angulo) {
	int i;
	double ang, passo;
	forma *f;
	if(angulo < 1 || angulo > 360) return NULL; // verifica se o ângulo está entre 1° e 360°
	f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = angulo + 2; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	f->pontos[0] = geraPosicao(0.0, 0.0); // gera o primeiro ponto na origem
	for (ang = 0, i = 1; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posição relativa ao centro a partir do raio e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraArco(double raio, int angulo) {
	int i;
	double ang, passo;
	forma *f;
	if(angulo < 1 || angulo > 360) return NULL; // verifica se o ângulo está entre 1° e 360°
	f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = angulo + 1; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_TRIANGLE_FAN; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posição relativa ao centro a partir do raio e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraArcoVazado(double raio, int angulo) {
	int i;
	double ang, passo;
	forma *f;
	if(angulo < 1 || angulo > 360) return NULL; // verifica se o ângulo está entre 1° e 360°
	f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = angulo + 1; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posição relativa ao centro a partir do raio e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraArcoAberto(double raio, int angulo) {
	int i;
	double ang, passo;
	forma *f;
	if(angulo < 1 || angulo > 360) return NULL; // verifica se o ângulo está entre 1° e 360°
	f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = angulo + 1; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_STRIP; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	passo = PI / 180.0; // calcula o passo
	for (ang = i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = geraPosicao(cos(ang) * raio, sin(ang) * raio); // gera a posição relativa ao centro a partir do raio e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}


forma *geraEstrela(double raio1, double raio2, int nPontas) {
	int i;
	double ang, passo;
	forma *f;
	if(nPontas < 2) return NULL; // verifica se o número de pontas é menor que 2
	f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = nPontas * 2; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POLYGON; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	ang = PI / 2.0; // define o ângulo inicial
	passo = 2 * PI / (double)f->qtdPontos; // calcula o passo
	for (i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = i % 2 ? geraPosicao(cos(ang) * raio2, sin(ang) * raio2)
							 : geraPosicao(cos(ang) * raio1, sin(ang) * raio1); // gera a posição relativa ao centro a partir dos 2 raios e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraEstrelaVazado(double raio1, double raio2, int nPontas) {
	int i;
	double ang, passo;
	forma *f;
	if(nPontas < 2) return NULL; // verifica se o número de pontas é menor que 2
	f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = nPontas * 2; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	ang = PI / 2.0; // define o ângulo inicial
	passo = 2 * PI / (double)f->qtdPontos; // calcula o passo
	for (i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = i % 2 ? geraPosicao(cos(ang) * raio2, sin(ang) * raio2)
							 : geraPosicao(cos(ang) * raio1, sin(ang) * raio1); // gera a posição relativa ao centro a partir dos 2 raios e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraPentagrama(double raio1, double raio2) {
	int i;
	double ang, passo;
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 10; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_POLYGON; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	ang = PI / 2.0; // define o ângulo inicial
	passo = PI / 5.0; // calcula o passo
	for (i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = i % 2 ? geraPosicao(cos(ang) * raio2, sin(ang) * raio2)
							 : geraPosicao(cos(ang) * raio1, sin(ang) * raio1); // gera a posição relativa ao centro a partir dos 2 raios e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraPentagramaVazado(double raio1, double raio2) {
	int i;
	double ang, passo;
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 10; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
	ang = PI / 2.0; // define o ângulo inicial
	passo = PI / 5.0; // calcula o passo
	for (i = 0; i < f->qtdPontos; i++) {
		f->pontos[i] = i % 2 ? geraPosicao(cos(ang) * raio2, sin(ang) * raio2)
							 : geraPosicao(cos(ang) * raio1, sin(ang) * raio1); // gera a posição relativa ao centro a partir dos 2 raios e do ângulo
		ang += passo; // incrementa o ângulo pelo passo
	}
	// termina de instanciar os pontos
	return f; // retorna a forma f
}

forma *geraSeta(double proporcao) {
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 7; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_TRIANGLE_FAN; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
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
	forma *f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	f->qtdPontos = 7; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_LINE_LOOP; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	f->letras = NULL; // anula o ponteiro para letras
	// começa a instanciar os pontos
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

int next_p2(int a) { // gera a potência de 2 mais próxima acima do valor a
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
	if(!texto || !texto[0]) return NULL; // verifica se o texto está vazio
	f = (forma *)malloc(sizeof(forma)); // aloca espaço para forma
	if(!f) return NULL; // verifica se o espaço para a forma foi alocado
	l = 1; // instância l em 1
	while(texto[l]) l++; // incrementa o valor de l até chegar no final do texto
	f->qtdLetras = l; // instância a quantidade de letras
	f->qtdPontos = 4 * f->qtdLetras; // instância a quantidade de pontos
	f->pontos = (posicao *)malloc(f->qtdPontos * sizeof(posicao)); // aloca espaço para os pontos
	if(!f->pontos) { // verifica se o espaço para os pontos foi alocado
		free(f); // libera forma
		return NULL; // retorna valor nulo
	}
	f->tipo = GL_QUADS; // instância o tipo de desenho
	f->corInterna = corInterna; // instância a cor
	f->corBorda = corBorda; // instância a cor da borda
	f->tamBorda = tamBorda; // instância o tamanho da borda
	f->pos = posDesenho; // instância a posição
	f->nJanelas = 0; // instância o número de janelas
	// começa a instanciar a textura
	f->letras = (textura **)malloc(f->qtdLetras * sizeof(textura *)); // aloca espaço para as letras
	if(!f->letras
	|| FT_Init_FreeType(&library)
	|| FT_New_Face(library, "arial.ttf", 0, &face)
	|| FT_Set_Char_Size(face, (FT_F26Dot6)0, (FT_F26Dot6)(tamanho * 64), (FT_UInt)0, (FT_UInt)300)) { // verifica se alocou o espaço para as letras e iniciou os elementos geradores das texturas
		destroiForma(f); // destrói a forma
		FT_Done_Face(face); // finaliza a face da fonte
        FT_Done_FreeType(library); // finaliza a biblioteca FreeType
		return NULL; // retorna valor nulo
	}
	for(l = 0; l < f->qtdLetras; l++) {
		f->letras[l] = (textura *)malloc(sizeof(textura)); // aloca a textura da letra
		if(!f->letras[l]
		|| FT_Load_Glyph(face, FT_Get_Char_Index(face, texto[l]), FT_LOAD_DEFAULT)
		|| FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL)) { // verifica se alocou espaço para a letra e se conseguiu gerar ela
			destroiForma(f); // destrói a forma
			FT_Done_Face(face); // finaliza a face da fonte
			FT_Done_FreeType(library); // finaliza a biblioteca FreeType
			return NULL; // retorna valor nulo
		}
		f->letras[l]->x = face->glyph->bitmap.width; // instância o tamanho horizontal  da imagem
		f->letras[l]->y = face->glyph->bitmap.rows; // instância o tamanho vertical  da imagem
		f->letras[l]->xprop = next_p2(f->letras[l]->x); // instância a margem horizontal da imagem
		f->letras[l]->yprop = next_p2(f->letras[l]->y); // instância a margem vertical da imagem
		f->letras[l]->bmp = (ubyte *)calloc(2 * f->letras[l]->xprop * f->letras[l]->yprop, sizeof(ubyte)); // aloca espaço para o bitmap da textura
		if(!f->letras[l]->bmp) { // verifica se alocou espaço para o bitmap da imagem
			destroiForma(f); // destrói a forma
			FT_Done_Face(face); // finaliza a face da fonte
			FT_Done_FreeType(library); // finaliza a biblioteca FreeType
			return NULL; // retorna valor nulo
		}
		// inicio da área onde a imagem da letra é copiada para o bitmap da textura
		for(j = 0; j < f->letras[l]->y; j++) {
            for(i = 0; i < f->letras[l]->x; i++) {
				f->letras[l]->bmp[2 * j * f->letras[l]->xprop + i]     =
				f->letras[l]->bmp[2 * j * f->letras[l]->xprop + i + 1] =
				face->glyph->bitmap.buffer[j * f->letras[l]->x + i];
			}
		}
		// fim da área onde a imagem da letra é copiada para o bitmap da textura
		ay = face->glyph->bitmap_top - face->glyph->bitmap.rows; // altera a posição vertical onde a moldura da fonte será gerada
		valx += face->glyph->bitmap_left; // incrementa a posição horizontal onde a moldura da fonte será gerada
		// inicio da área onde são definidos os pontos da moldura
		f->pontos[4 * l]     = geraPosicao(valx,                   ay + f->letras[l]->y);
		f->pontos[4 * l + 1] = geraPosicao(valx,                   ay);
		f->pontos[4 * l + 2] = geraPosicao(valx + f->letras[l]->x, ay);
		f->pontos[4 * l + 3] = geraPosicao(valx + f->letras[l]->x, ay + f->letras[l]->y);
		// fim da área onde são definidos os pontos da moldura
		valx += face->glyph->advance.x >> 7; // incrementa a posição horizontal onde a próxima moldura será gerada
		ay = ay + f->letras[l]->y; // coloca em ay o tamanho vertical usado pela fonte
		if(ay > valy) valy = ay; // se ay é maior que valy, então instância o valor de valy com ay
		// no fim valy e valx vão possuir o tamanho máximo do texto na vertical e horizontal respectivamente
	}
	valx /= -2.0; // instância o valx com a metade do valor do valx original negativado
	valy /= -2.0; // instância o valy com a metade do valor do valy original negativado
	// início da área onde é somado a todos os pontos de todas as molduras os valores valx e valy
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
	// fim da área onde é somado a todos os pontos de todas as molduras os valores valx e valy
	// para que o texto fique centralizado com o ponto de origem
	FT_Done_Face(face); // finaliza a face da fonte
	FT_Done_FreeType(library); // finaliza a biblioteca FreeType
	redimensionar(f, 0.25, 0.25); // divide por 4 o tamanho da forma
	return f; // retorna a forma f
}

int destroiForma(forma *f) {
	int i;
	if(!f || f->nJanelas > 0) return -1; // se existir alguma janela usando a forma f, sai da função
	if(f->letras) { // verifica se as letras estão alocadas
		for(i = 0; i < f->qtdLetras; i++) {
			if(f->letras[i]) { // verifica se a letra na posição i está alocada
                free(f->letras[i]->bmp); // libera o bitmap
                free(f->letras[i]); // libera a letra
			}
		}
		f->qtdLetras = 0; // zera o número de letras
		free(f->letras); // libera o vetor de letras
	}
	f->qtdPontos = 0; // zera o número de pontos
	free(f->pontos); // libera a memória usada pelos pontos
	free(f); // libera a memória usada pela forma f
	return 0; // retorna sucesso
}

void definePosicao(double x, double y) {
	posDesenho = geraPosicao(x, y); // define a posição atual para desenho
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
	double a1 = a * PI / 180.0; // ângulo a em radiano
	double sa = sin(a1); // seno do ângulo a
	double ca = cos(a1); // cosseno do ângulo a
	for(i = 0; i < f->qtdPontos; i++) { // enquanto houver pontos
		aux            = f->pontos[i].x * ca - f->pontos[i].y * sa; // rotaciona a posição x em relação ao centro
		f->pontos[i].y = f->pontos[i].x * sa + f->pontos[i].y * ca; // rotaciona a posição y em relação ao centro
		f->pontos[i].x = aux; // instância novamente a posição x
	}
}

void redimensionar(forma *f, double x, double y) {
	int i;
	for(i = 0; i < f->qtdPontos; i++) { // enquanto houver pontos
		f->pontos[i].x *= x; // altera, a certa porcentagem, a distância de x do centro
		f->pontos[i].y *= y; // altera, a certa porcentagem, a distância de y do centro
	}
}

void mover(forma *f, double x, double y) {
	f->pos.x += x; // move a posição de x
	f->pos.y += y; // move a posição de y
}

void moverPara(forma *f, double x, double y) {
	f->pos.x = x; // move a posição de x
	f->pos.y = y; // move a posição de y
}

void mudaTexto(forma *f, double tamanho, char *texto) {
	forma *aux, *temp;
	mtx_t mutex;
	if(mtx_init(&mutex, mtx_plain) != thrd_success) return; // tenta inicializar a trava de exclusão mútua
	temp = (forma *)malloc(sizeof(forma)); // aloca espaço para a forma de cópia
	if(!temp) return; // verifica se foi alocado espaço para a forma de cópia
	aux = geraTexto(tamanho, texto); // gera o novo texto
	if(!aux) return; // verifica se foi possível gerar o novo texto
	mtx_lock(&mutex); // inicia a trava de exclusão mutua
	// início da área onde os dados em f são passados para temp
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
	// fim da área onde os dados em f são passados para temp
	// início da área onde os dados em aux são passados para f
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
	// fim da área onde os dados em aux são passados para f
    destroiForma(temp); // destrói a forma antiga
    free(aux); // libera o espaço de aux
	mtx_unlock(&mutex); // libera a trava de exclusão mútua
	mtx_destroy(&mutex); // destrói a trava de exclusão mútua
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
