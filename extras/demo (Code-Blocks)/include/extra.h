#include <GLFW/glfw3.h>

typedef struct {/* estrutura que define uma posição */
	double x, y;/* coordenadas x e y */
} posicao;

typedef struct {/* estrutura que define uma cor */
	int vermelho, verde, azul;/* cores básicas, vermelho, verde e azul */
} cor;

typedef struct {
	int x, y, xprop, yprop;
	GLubyte *bmp;
} textura;

cor geraCor(GLubyte vermelho, GLubyte verde, GLubyte azul);/* cria uma estrutura cor a partir dos parâmetros */
posicao geraPosicao(double x, double y);/* cria uma estrutura ponto a partir dos parâmetros */
