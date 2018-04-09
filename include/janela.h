#include "forma.h"

#ifndef GLAE_JANELA
#define GLAE_JANELA

typedef struct janela janela; // cria o tipo forma

struct janela { // estrutura que encapsula atributos relativos a janela
	GLFWwindow *win; // janela GLFW
	void (*especial)(); // função que trabalha manualmente com o OpenGL
	forma **formas; // vetor de formas a serem desenhadas
	int nFormas; // número de formas relacionadas com a janela
	int maxFormas; // número posições que o vetor de formas possui
	cor corFundo; // cor de fundo da janela
};

janela *criaJanela(int x, int y, char *titulo); // cria janela com x tamanho horizontal, y tamanho vertical e com o título titulo
void fechaJanela(janela *j); // fecha a janela j

void mudaEspecial(janela *j, void (*especial)()); // define qual vai ser a função que vai trabalhar manualmente com o OpenGL para a janela j
void mudaCorFundo(janela *j, int vermelho, int verde, int azul); // define a cor de fundo da janela j

int adicionaForma(janela *j, forma *f);  // insere a forma f na janela j
int removeForma(janela *j, forma *f);  // remove a forma f da janela j
int limpaJanela(janela *j); // remove todas formas da janela j

#endif // GLAE_JANELA
