#include <stdio.h>
#include <janela.h>

typedef struct {
    janela *jan;
    forma *fundo[5][10];
    forma *f[5][10];
} elementos;

void inicializar(elementos *el) {
    int i, j;
    el->jan = criaJanela(800, 600, "teste");
    defineCorInterna(0, 0, 255);
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 10; j++) {
            definePosicao(j * 70.0 - 315.0, -i * 70.0 + 140);
            el->fundo[i][j] = geraRetangulo(65.0, 65.0);
            adicionaForma(el->jan, el->fundo[i][j]);
            el->f[i][j] = NULL;
        }
    }
    defineCorInterna(255, 255, 255);
}

void alterarValor(elementos *el, int i, int j, int val) {
    forma *aux;
    char buf[10];
    removeForma(el->jan, el->f[i][j]);
    sprintf(buf, "%d", val);
    definePosicao(j * 70.0 - 315.0, -i * 70.0 + 140);
    aux = geraTexto(50, buf);
    adicionaForma(el->jan, aux);
    destroiForma(el->f[i][j]);
    el->f[i][j] = aux;
}

void finalizar(elementos *el) {
    int i, j;
    fechaJanela(el->jan);
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 10; j++) {
            destroiForma(el->f[i][j]);
            destroiForma(el->fundo[i][j]);
        }
    }
}

int main() {
    int v = 1, i, j;
    elementos el;
    inicializar(&el);
    while(v) {
        for(i = 0; i < 5; i++)
            for(j = 0; j < 10; j++)
                alterarValor(&el, i, j, i * 10 + j + v);
        printf("\n Escreva 0 para sair: ");
        scanf("%d", &v);
        printf("\n Voce escreveu: %d\n", v);
    }
    finalizar(&el);
    return 0;
}
