#include <extra.h>

cor geraCor(int vermelho, int verde, int azul) {
	cor c; // instância a cor
	c.vermelho = vermelho; // define a intensidade de vermelho
	c.verde = verde; // define a intensidade de verde
	c.azul = azul; // define a intensidade de azul
	return c; // retorna a cor
}

posicao geraPosicao(double x, double y) {
	posicao p; // instância a posição
	p.x = x; // define a posição horizontal
	p.y = y; // define a posição vertical
	return p; // retorna o ponto
}
