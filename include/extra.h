#include <GLFW/glfw3.h>

#ifndef GLAE_EXTRA
#define GLAE_EXTRA

typedef struct posicao posicao; // cria o tipo posicao
typedef struct cor cor; // cria o tipo cor
typedef struct textura textura; // cria o tipo textura
typedef GLubyte ubyte; // cria o tipo ubyte

struct posicao { // estrutura que define uma posi��o
	double x, y; // coordenadas x e y
};

struct cor { // estrutura que define uma cor
	int vermelho, verde, azul; // cores b�sicas vermelho, verde e azul
};

struct textura { // estrutura que define uma textura
	int x, y, xprop, yprop; // informa��es de tamanho do bitmap
	ubyte *bmp; // bitmap
};

cor geraCor(int vermelho, int verde, int azul); // cria uma estrutura cor a partir dos par�metros
posicao geraPosicao(double x, double y); // cria uma estrutura ponto a partir dos par�metros

#endif // GLAE_EXTRA
