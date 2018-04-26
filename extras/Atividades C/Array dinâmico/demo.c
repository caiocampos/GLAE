#include <stdio.h>
#include <janela.h>

typedef struct {
    janela *jan;
    forma *fundo[6];
    forma *f[6];
    int vals[6];
} elementos;

void inicializar(elementos *el) {
    int i;
    char buf[15];
    el->jan = criaJanela(800, 600, "teste");
    for(i = 0; i < 6; i++) {
        definePosicao((i - 2.5) * 120.0, 0.0);
        defineCorInterna(0, 0, 255);
        el->fundo[i] = geraRetangulo(110.0, 40.0);
        defineCorInterna(255, 255, 255);
        sprintf(buf, "%d", el->vals[i]);
        el->f[i] = geraTexto(30, buf);
		adicionaForma(el->jan, el->fundo[i]);
		adicionaForma(el->jan, el->f[i]);
    }
}

void gerarVetor(elementos *el) {
    int i;
    char buf[15];
    defineCorInterna(255, 255, 255);
    for(i = 0; i < 6; i++) {
        definePosicao((i - 2.5) * 120.0, 0.0);
        sprintf(buf, "%d", el->vals[i]);
        mudaTexto(el->f[i], 30, buf);
    }
}

void finalizar(elementos *el) {
    int i;
    fechaJanela(el->jan);
    for(i = 0; i < 6; i++) {
        destroiForma(el->f[i]);
        destroiForma(el->fundo[i]);
    }
}

int main() {
    int i, tam;
    char c;
    elementos el;
    inicializar(&el);
    do {
        do {
            printf("\n Digite o numero de valores (entre 1 e 6): ");
            fflush(stdin);
            scanf("%d", &tam);
            printf("\n");
        } while(tam <= 0 || tam > 6);
        for(i = 0; i < tam; i++) {
            printf("digite o %d%c valor: ", i + 1, 0xF8);
            fflush(stdin);
            scanf("%d", &(el.vals[i]));
            gerarVetor(&el);
        }
        do {
            printf("\n Escreva 0 para sair ou 1 para inserir outro vetor: ");
            fflush(stdin);
            scanf("%c", &c);
            printf("\n Voce escreveu: %c\n", c);
        } while(c != '0' && c != '1');
    } while(c == '1');
    fflush(stdin);
    printf("\n Pressione Enter para continuar. ");
    getchar();
    finalizar(&el);
    return 0;
}
