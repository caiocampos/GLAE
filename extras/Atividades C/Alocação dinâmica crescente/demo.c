#include <stdlib.h>
#include <stdio.h>
#include <janela.h>

typedef struct {
    janela *jan;
    forma **fundo;
    forma **f;
    int tam;
} elementos;

void adicionaValor(elementos *el, int v) {
    int i;
    char buf[20];
    el->fundo = (forma **)realloc(el->fundo, (el->tam + 1) * sizeof(forma *));
    el->f     = (forma **)realloc(el->f, (el->tam + 1) * sizeof(forma *));
    for(i = 0; i < el->tam; i++) {
        mover(el->fundo[i], -35, 0);
        mover(el->f[i],     -35, 0);
    }
    el->tam = el->tam + 1;
    definePosicao(((el->tam - 1.0) / 2.0) * 70.0, 0.0);
    defineCorInterna(0, 0, 255);
    el->fundo[el->tam-1] = geraRetangulo(65.0, 65.0);
    defineCorInterna(255, 255, 255);
    sprintf(buf, "%d", v);
    el->f[el->tam-1] = geraTexto(50, buf);
    adicionaForma(el->jan, el->fundo[el->tam-1]);
    adicionaForma(el->jan, el->f[el->tam-1]);
}

void inicializar(elementos *el) {
    el->jan   = criaJanela(800, 600, "teste");
    el->tam   = 0;
    el->f     = NULL;
    el->fundo = NULL;
}

void finalizar(elementos *el) {
    int i;
    fechaJanela(el->jan);
    for(i = 0; i < el->tam; i++) {
        destroiForma(el->f[i]);
        destroiForma(el->fundo[i]);
    }
}

int main() {
    char c = '1';
    int v;
    elementos el;
    inicializar(&el);
    do {
        printf("\n Digite um valor inteiro: ");
        fflush(stdin);
        scanf("%d", &v);
        adicionaValor(&el, v);
        do {
            printf("\n Escreva 0 para sair ou 1 para inserir outro elemento: ");
            fflush(stdin);
            scanf("%c", &c);
            printf("\n Voce escreveu: %c\n", c);
        } while(c != '0' && c != '1');
    } while(c == '1' && el.tam < 11);
    if(el.tam == 11) printf("\n Limite atingido\n");
    fflush(stdin);
    printf("\n Pressione Enter para sair. ");
    getchar();
    finalizar(&el);
    return 0;
}
