#include <stdio.h>
#include <janela.h>

typedef struct {
    janela *jan;
    forma *fundo[10];
    forma *f[10];
} elementos;

void inicializar(elementos *el) {
    int i;
    el->jan = criaJanela(800, 600, "teste");
    defineCorInterna(0, 0, 255);
    for(i = 0; i < 10; i++) {
        definePosicao(i * 70.0 - 315.0, 0.0);
        el->fundo[i] = geraRetangulo(65.0, 65.0);
        adicionaForma(el->jan, el->fundo[i]);
        el->f[i] = NULL;
    }
    defineCorInterna(255, 255, 255);
}

void alterarValor(elementos *el, int pos, int val) {
    forma *aux;
    char buf[10];
    removeForma(el->jan, el->f[pos]);
    sprintf(buf, "%d", val);
    definePosicao(pos * 70.0 - 315.0, 0.0);
    aux = geraTexto(50, buf);
    adicionaForma(el->jan, aux);
    destroiForma(el->f[pos]);
    el->f[pos] = aux;
}

void finalizar(elementos *el) {
    int i;
    fechaJanela(el->jan);
    for(i = 0; i < 10; i++) {
        destroiForma(el->f[i]);
        destroiForma(el->fundo[i]);
    }
}

int main() {
    int v = 1, i;
    elementos el;
    inicializar(&el);
    while(v) {
        for(i = 0; i < 10; i++) alterarValor(&el, i, i + v);
        printf("\n Escreva 0 para sair: ");
        scanf("%d", &v);
        printf("\n Voce escreveu: %d\n", v);
    }
    finalizar(&el);
    return 0;
}
