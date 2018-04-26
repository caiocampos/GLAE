#include <stdio.h>
#include <janela.h>

enum formas {
	ponto,
	linha,
	triangulo,
	quadrado,
	pentagono,
	hexagono,
	heptagono,
	octogono,
	eneagono,
	decagono,
	circulo
};

typedef struct {
    janela *jan;
    forma *f[11];
} elementos;

void finalizar(elementos *el) {
    fechaJanela(el->jan);
    destroiForma(el->f[ponto]);
    destroiForma(el->f[linha]);
    destroiForma(el->f[triangulo]);
    destroiForma(el->f[quadrado]);
    destroiForma(el->f[pentagono]);
    destroiForma(el->f[hexagono]);
    destroiForma(el->f[heptagono]);
    destroiForma(el->f[octogono]);
    destroiForma(el->f[eneagono]);
    destroiForma(el->f[decagono]);
    destroiForma(el->f[circulo]);
}

int inicializar(elementos *el) {
    int i;
    el->jan = criaJanela(800, 600, "teste");
    if(!el->jan) return 0;
    el->f[ponto] = geraPonto();
    el->f[linha] = geraLinha(120);
    el->f[triangulo] = geraPoligono(200, 3);
    el->f[quadrado] = geraPoligono(200, 4);
    el->f[pentagono] = geraPoligono(200, 5);
    el->f[hexagono] = geraPoligono(200, 6);
    el->f[heptagono] = geraPoligono(200, 7);
    el->f[octogono] = geraPoligono(200, 8);
    el->f[eneagono] = geraPoligono(200, 9);
    el->f[decagono] = geraPoligono(200, 10);
    el->f[circulo] = geraCirculo(200);
    for(i = 0; i < 11; i++) {
        if(!el->f[i]) {
            finalizar(el);
            return 0;
        }
    }
    return 1;
}

int main() {
    char c;
    elementos el;
    if(!inicializar(&el)) {
        printf("Erro de inicializacao\n");
        printf("Este programa será fechado");
        fflush(stdin);
        printf("\n Pressione Enter ");
        getchar();
        return -1;
    }
    printf("Atividade de switch - case:\n");
    printf("\n     Menu\n\n");
    printf("a. Para mostrar um ponto;\n");
    printf("b. Para mostrar uma linha;\n");
    printf("c. Para mostrar um triangulo;\n");
    printf("d. Para mostrar um quadrado;\n");
    printf("e. Para mostrar um pentagono;\n");
    printf("f. Para mostrar um hexagono;\n");
    printf("g. Para mostrar um heptagono;\n");
    printf("h. Para mostrar um octogono;\n");
    printf("i. Para mostrar um eneagono;\n");
    printf("j. Para mostrar um decagono;\n");
    printf("Outro caracter para mostrar um circulo;\n\n");
    printf(" Escreva o caracter relativo a sua escolha: ");
    fflush(stdin);
    scanf("%c", &c);
    printf("\n Voce escreveu: %c\n\n", c);
    switch(c) {
		case 'a':	printf("Adicionando um ponto!\n");
					adicionaForma(el.jan, el.f[ponto]);
					break;
        case 'b':	printf("Adicionando uma linha!\n");
					adicionaForma(el.jan, el.f[linha]);
					break;
        case 'c':	printf("Adicionando um triangulo!\n");
					adicionaForma(el.jan, el.f[triangulo]);
					break;
        case 'd':	printf("Adicionando um quadrado!\n");
					adicionaForma(el.jan, el.f[quadrado]);
					break;
        case 'e':	printf("Adicionando um pentagono!\n");
					adicionaForma(el.jan, el.f[pentagono]);
					break;
        case 'f':	printf("Adicionando um hexagono!\n");
					adicionaForma(el.jan, el.f[hexagono]);
					break;
        case 'g':	printf("Adicionando um heptagono!\n");
					adicionaForma(el.jan, el.f[heptagono]);
					break;
        case 'h':	printf("Adicionando um octogono!\n");
					adicionaForma(el.jan, el.f[octogono]);
					break;
        case 'i':	printf("Adicionando um eneagono!\n");
					adicionaForma(el.jan, el.f[eneagono]);
					break;
        case 'j':	printf("Adicionando um decagono!\n");
					adicionaForma(el.jan, el.f[decagono]);
					break;
		default:	printf("Adicionando um circulo!\n");
					adicionaForma(el.jan, el.f[circulo]);
    }
    fflush(stdin);
    printf("\n Pressione Enter ");
    getchar();
    finalizar(&el);
    return 0;
}
