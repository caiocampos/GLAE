#include <stdlib.h>
#include <stdio.h>
#include <janela.h>

typedef struct {
    janela *jan;
    forma **fundo;
    forma **f;
    int tam;
    int *vals;
} elementos;

void reiniciar(elementos *el) {
    int i;
    limpaJanela(el->jan);
    if(el->f == NULL) {
        el->fundo = NULL;
        return;
    }
    if(el->fundo == NULL) {
        el->f = NULL;
        return;
    }
    for(i = 0; i < el->tam; i++) {
        destroiForma(el->f[i]);
        destroiForma(el->fundo[i]);
    }
    el->f     = NULL;
    el->fundo = NULL;
}

void mudaTamVetor(elementos *el, int tam) {
    int i;
    char buf[20];
    reiniciar(el);
	el->tam = tam;
    el->fundo = (forma **)realloc(el->fundo, (el->tam) * sizeof(forma *));
    el->f     = (forma **)realloc(el->f, (el->tam) * sizeof(forma *));
    for(i = 0; i < el->tam; i++) {
        definePosicao((i - (el->tam - 1.0) / 2.0) * 120.0, 0.0);
        defineCorInterna(0, 0, 255);
        el->fundo[i] = geraRetangulo(110.0, 65.0);
        defineCorInterna(255, 255, 255);
        sprintf(buf, "%d", el->vals[i]);
        el->f[i] = geraTexto(50, buf);
        adicionaForma(el->jan, el->fundo[i]);
        adicionaForma(el->jan, el->f[i]);
    }
}

void atualizaVetor(elementos *el) {
    int i;
    char buf[20];
    defineCorInterna(255, 255, 255);
    for(i = 0; i < el->tam; i++) {
        definePosicao((i - (el->tam - 1.0) / 2.0) * 120.0, 0.0);
        sprintf(buf, "%d", el->vals[i]);
        mudaTexto(el->f[i], 50, buf);
    }
}

void inicializar(elementos *el) {
    el->jan   = criaJanela(800, 600, "teste");
    el->tam   = 0;
    el->f     = NULL;
    el->fundo = NULL;
    el->vals  = NULL;
}

void finalizar(elementos *el) {
    int i;
    fechaJanela(el->jan);
    free(el->vals);
    if(el->f == NULL || el->fundo == NULL) return;
    for(i = 0; i < el->tam; i++) {
        destroiForma(el->f[i]);
        destroiForma(el->fundo[i]);
    }
}

int main() {
    char c = '1';
    int i, tam;
    elementos el;
    inicializar(&el);
    do {
        printf("\n Menu:\n");
        printf("0 - Sair\n");
        printf("1 - Mudar o tamanho do vetor\n");
        printf("2 - Reinserir os valores\n\n");
        printf("Digite sua escolha: ");
        setbuf(stdin, NULL);
        scanf("%c", &c);
        printf("\n Voce escreveu: %c\n", c);
        switch(c) {
            case '0':   printf("\nSaindo..\n");
                        break;
            case '1':   do {
                            printf("\n Digite o numero de valores (entre 1 e 6): ");
                            setbuf(stdin, NULL);
                            scanf("%d", &tam);
                            printf("\n");
                        } while(tam <= 0 || tam > 6);
                        el.vals = (int*)realloc(el.vals, tam * sizeof(int));
                        mudaTamVetor(&el, tam);
                        break;
            case '2':   if(el.tam <= 0) {
                            printf("\nO vetor possui tamanho insuficiente,\n");
                            printf("por favor aumente o espaco antes de inserir os valores.\n");
                        }
                        else {
                            for(i = 0; i < el.tam; i++) {
                                printf("digite o %d%c valor: ", i + 1, 0xF8);
                                setbuf(stdin, NULL);
                                scanf("%d", &(el.vals[i]));
                                atualizaVetor(&el);
                            }
                        }
                        break;
            default:    printf("\nCodigo errado!!\n");
        }
    } while(c != '0');
    setbuf(stdin, NULL);
    printf("\n Pressione Enter para sair. ");
    getchar();
    finalizar(&el);
    return 0;
}
