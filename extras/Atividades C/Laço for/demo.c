#include <stdio.h>
#include <janela.h>

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
    char c;
    int i, n;
    long int v;
    elementos el;
    if(!inicializar(&el)) {
        printf("Erro de inicializacao\n");
        printf("Este programa será fechado");
        fflush(stdin);
        printf("\n Pressione Enter ");
        getchar();
        return -1;
    }
    printf("\n               Menu\n\n");
    printf("1. Para mover forma verticalmente;\n");
    printf("2. Para mover forma horizontalmente;\n\n");
    printf(" Escreva o numero relativo a sua escolha: ");
    fflush(stdin);
    scanf("%c", &c);
    switch(c) {
		case '1':	printf("\nEscreva um numero positivo para ir para cima,\n");
                    printf("ou negativo para ir para baixo.");
                    break;
		case '2':	printf("\nEscreva um numero positivo para ir para direita,\n");
                    printf("ou negativo para ir para esquerda.");
                    break;
		default:    printf("Codigo incorreto, a forma não se movera");
                    fflush(stdin);
                    printf("\n Pressione Enter ");
                    getchar();
                    finalizar(&el);
                    return 0;
    }
    printf("\n\n Escreva o numero de pixels a figura deve se mover: ");
    fflush(stdin);
    scanf("%ld", &v);
    n = v < 0 ? -1 : 1;
    v = v * 1000000 * n;
    switch(c) {
		case '1':	for(i = 0; i < v; i++)
						mover(el.circ, 0, 0.000001 * n);
					break;
		case '2':	for(i = 0; i < v; i++)
						mover(el.circ, 0.000001 * n, 0);
    }
    fflush(stdin);
    printf("\n Pressione Enter ");
    getchar();
    finalizar(&el);
    return 0;
}
