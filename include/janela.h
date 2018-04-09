#include "forma.h"

#ifndef GLAE_JANELA
#define GLAE_JANELA

typedef struct janela janela; // cria o tipo forma

struct janela { // estrutura que encapsula atributos relativos a janela
	GLFWwindow *win; // janela GLFW
	void (*especial)(); // fun��o que trabalha manualmente com o OpenGL
	forma **formas; // vetor de formas a serem desenhadas
	int nFormas; // n�mero de formas relacionadas com a janela
	int maxFormas; // n�mero posi��es que o vetor de formas possui
	cor corFundo; // cor de fundo da janela
};

janela *criaJanela(int x, int y, char *titulo); // cria janela com x tamanho horizontal, y tamanho vertical e com o t�tulo titulo
void fechaJanela(janela *j); // fecha a janela j

void mudaEspecial(janela *j, void (*especial)()); // define qual vai ser a fun��o que vai trabalhar manualmente com o OpenGL para a janela j
void mudaCorFundo(janela *j, int vermelho, int verde, int azul); // define a cor de fundo da janela j

int adicionaForma(janela *j, forma *f);  // insere a forma f na janela j
int removeForma(janela *j, forma *f);  // remove a forma f da janela j
int limpaJanela(janela *j); // remove todas formas da janela j

#endif // GLAE_JANELA
