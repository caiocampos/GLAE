#include <stdio.h>
#include <janela.h>

typedef struct {
    janela *jan;
    forma *fundo[5];
    forma *fundoT;
    forma *f[5];
    forma *fT;
    char *texto;
} elementos;

void inicializar(elementos *el) {
    int i;
    char buf[10];
    el->texto = "teste";
    el->jan = criaJanela(800, 600, "teste");
    for(i = 0; i < 5; i++) {
        definePosicao(i * 70.0 - 140.0, 0.0);
        defineCorInterna(0, 0, 255);
        el->fundo[i] = geraRetangulo(65.0, 65.0);
        sprintf(buf, "%c", el->texto[i]);
        defineCorInterna(255, 255, 255);
        el->f[i] = geraTexto(50, buf);
        adicionaForma(el->jan, el->fundo[i]);
        adicionaForma(el->jan, el->f[i]);
    }
    definePosicao(0.0, 80.0);
    defineCorInterna(0, 0, 255);
    el->fundoT = geraRetangulo(100.0, 65.0);
    defineCorInterna(255, 255, 255);
    el->fT = geraTexto(50, el->texto);
    adicionaForma(el->jan, el->fundoT);
    adicionaForma(el->jan, el->fT);
}

void finalizar(elementos *el) {
    int i;
    fechaJanela(el->jan);
    for(i = 0; i < 5; i++) {
        destroiForma(el->f[i]);
        destroiForma(el->fundo[i]);
    }
    destroiForma(el->fT);
    destroiForma(el->fundoT);
}

int main() {
    int v = 1;
    elementos el;
    inicializar(&el);
    while(v) {
        printf("\n Escreva 0 para sair: ");
        scanf("%d", &v);
        printf("\n Voce escreveu: %d\n", v);
    }
    finalizar(&el);
    return 0;
}
