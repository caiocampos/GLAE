#include <stdio.h>
#include <janela.h>

enum cores {
	branco,
	vermelho,
	verde,
	azul,
	amarelo,
	ciano,
	magenta,
	preto,
};

typedef struct {
    janela *jan;
    forma *circ;
} elementos;

void finalizar(elementos *el) {
    fechaJanela(el->jan);
    destroiForma(el->circ);
}

int inicializar(elementos *el) {
    el->jan = criaJanela(800, 600, "teste");
    el->circ = geraCirculo(120);
    if(!(el->jan && el->circ)) {
        finalizar(el);
        return 0;
    }
    adicionaForma(el->jan, el->circ);
    return 1;
}

int main() {
    int v = branco;
    elementos el;
    if(!inicializar(&el)) {
        printf("Erro de inicializacao\n");
        printf("Este programa será fechado");
        fflush(stdin);
        printf("\nPressione Enter ");
        getchar();
        return -1;
    }
    while(v >= 0 && v <= 7) {
		printf("\n     Menu\n\n");
        printf("Entre com um valor para alterar a cor do circulo:\n\n");
        printf("0. Para mudar a cor para branco;\n");
        printf("1. Para mudar a cor para vermelho;\n");
        printf("2. Para mudar a cor para verde;\n");
        printf("3. Para mudar a cor para azul;\n");
        printf("4. Para mudar a cor para amarelo;\n");
        printf("5. Para mudar a cor para ciano;\n");
        printf("6. Para mudar a cor para magenta;\n");
        printf("7. Para mudar a cor para preto;\n");
        printf("Outro valor para sair;\n\n");
        printf(" Escreva o numero relativo a sua escolha: ");
        fflush(stdin);
        scanf("%d", &v);
        printf("\nVoce escreveu: %d\n\n", v);
		switch(v) {
			case branco:	mudaCorInterna(el.circ, 255, 255, 255);
							mudaCorBorda(el.circ, 255, 255, 255);
							break;
			case vermelho:	mudaCorInterna(el.circ, 255, 0, 0);
							mudaCorBorda(el.circ, 255, 0, 0);
							break;
			case verde:		mudaCorInterna(el.circ, 0, 255, 0);
							mudaCorBorda(el.circ, 0, 255, 0);
							break;
			case azul:		mudaCorInterna(el.circ, 0, 0, 255);
							mudaCorBorda(el.circ, 0, 0, 255);
							break;
			case amarelo:	mudaCorInterna(el.circ, 255, 255, 0);
							mudaCorBorda(el.circ, 255, 255, 0);
							break;
			case ciano:		mudaCorInterna(el.circ, 0, 255, 255);
							mudaCorBorda(el.circ, 0, 255, 255);
							break;
			case magenta:	mudaCorInterna(el.circ, 255, 0, 255);
							mudaCorBorda(el.circ, 255, 0, 255);
							break;
			case preto:		mudaCorInterna(el.circ, 0, 0, 0);
							break;
			default: printf("\nSaindo...");
		}
    }
    fflush(stdin);
    printf("\n\nPressione Enter ");
    getchar();
    finalizar(&el);
    return 0;
}
