#include <extra.h>

cor geraCor(int vermelho, int verde, int azul) {
	cor c; // inst�ncia a cor
	c.vermelho = vermelho; // define a intensidade de vermelho
	c.verde = verde; // define a intensidade de verde
	c.azul = azul; // define a intensidade de azul
	return c; // retorna a cor
}

posicao geraPosicao(double x, double y) {
	posicao p; // inst�ncia a posi��o
	p.x = x; // define a posi��o horizontal
	p.y = y; // define a posi��o vertical
	return p; // retorna o ponto
}
