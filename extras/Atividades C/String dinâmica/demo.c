#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <janela.h>

typedef struct {
    janela *jan;
    forma *fundo[11];
    forma *fundoT;
    forma *f[11];
    forma *fT;
    char texto[11];
} elementos;

void gerarStrings(elementos *el) {
    int i;
    char buf[3];
    defineCorInterna(255, 255, 255);
    for(i = 0; i < 11; i++) {
        definePosicao(i * 70.0 - 350.0, 0.0);
        defineCorInterna(255, 255, 255);
        if(el->texto[i] == '\0') sprintf(buf, "\\0");
        else sprintf(buf, "%c", el->texto[i]);
        mudaTexto(el->f[i], 50, buf);
    }
    if(el->texto[0] == '\0') return;
    definePosicao(0.0, 80.0);
    mudaTexto(el->fT, 50, el->texto);
}

void inicializar(elementos *el) {
    int i;
    char buf[3];
    el->jan = criaJanela(800, 600, "teste");
    for(i = 0; i < 11; i++) {
        definePosicao(i * 70.0 - 350.0, 0.0);
        defineCorInterna(0, 0, 255);
        el->fundo[i] = geraRetangulo(65.0, 65.0);
        defineCorInterna(255, 255, 255);
        if(el->texto[i] == '\0') sprintf(buf, "\\0");
        else sprintf(buf, "%c", el->texto[i]);
        el->f[i] = geraTexto(50, buf);
        adicionaForma(el->jan, el->fundo[i]);
        adicionaForma(el->jan, el->f[i]);
    }
    if(el->texto[0] == '\0') return;
    definePosicao(0.0, 80.0);
    defineCorInterna(0, 0, 255);
    el->fundoT = geraRetangulo(160.0, 65.0);
    defineCorInterna(255, 255, 255);
    el->fT = geraTexto(50, el->texto);
    adicionaForma(el->jan, el->fundoT);
    adicionaForma(el->jan, el->fT);
}

void finalizar(elementos *el) {
    int i;
    fechaJanela(el->jan);
    for(i = 0; i < 11; i++) {
        if(el->f[i] != NULL) destroiForma(el->f[i]);
        destroiForma(el->fundo[i]);
    }
    destroiForma(el->fT);
    destroiForma(el->fundoT);
}

int main() {
    char aux[11];
    int i;
    elementos el;
    inicializar(&el);
    do {
        printf(" Entre com um texto para ser exibido na tela.\n");
        printf(" Se for escrito \"sair\" o programa sera finalizado.\n\n");
        fflush(stdin);
        scanf("%10s", el.texto);
        gerarStrings(&el);
        printf("\n");
        for(i = 0; i < 11; i++) aux[i] = tolower(el.texto[i]);
    } while(strcmp(aux, "sair"));
    printf(" Saindo...\n\n");
    fflush(stdin);
    printf(" Pressione Enter para continuar. ");
    getchar();
    finalizar(&el);
    return 0;
}
