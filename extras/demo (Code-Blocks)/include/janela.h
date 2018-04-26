#include "forma.h"

typedef struct {/* estrutura que encapsula atributos relativos a janela */
	GLFWwindow *win; /* janela GLFW */
	void (*especial)();/* função que trabalha manualmente com o OpenGL */
	forma **formas; /* vetor de formas a serem desenhadas */
	int nFormas;/* número de formas relacionadas com a janela */
	int maxFormas;
	cor corFundo;
} janela;

janela *criaJanela(int x, int y, char *titulo);  /* cria janela com x tamanho horizontal, y tamanho vertical e com o título titulo */
void fechaJanela(janela *j); /* fecha a janela j */

void mudaEspecial(janela *j, void (*especial)()); /* define qual vai ser a função que vai trabalhar manualmente com o OpenGL para a janela j */
void mudaCorFundo(janela *j, GLubyte vermelho, GLubyte verde, GLubyte azul);

int adicionaForma(janela *j, forma *f);  /* insere a forma f na janela j */
int removeForma(janela *j, forma *f);  /* remove a forma f da janela j */
int limpaJanela(janela *j);
