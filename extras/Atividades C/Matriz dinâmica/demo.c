#include <stdio.h>
#include <janela.h>

typedef struct {
    janela *jan;
    forma *fundo[10][6];
    forma *f[10][6];
    int vals[10][6];
} elementos;

void inicializar(elementos *el) {
    int i, j;
    char buf[15];
    el->jan = criaJanela(800, 600, "teste");
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 6; j++) {
            definePosicao((j - 2.5) * 120.0, -(i - 4.5) * 50.0);
            defineCorInterna(0, 0, 255);
            el->fundo[i][j] = geraRetangulo(110.0, 40.0);
            defineCorInterna(255, 255, 255);
            sprintf(buf, "%d", el->vals[i][j]);
            el->f[i][j] = geraTexto(30, buf);
            adicionaForma(el->jan, el->fundo[i][j]);
            adicionaForma(el->jan, el->f[i][j]);
        }
    }
}

void gerarMatriz(elementos *el) {
    int i, j;
    char buf[15];
    defineCorInterna(255, 255, 255);
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 6; j++) {
            definePosicao((j - 2.5) * 120.0, -(i - 4.5) * 50.0);
            sprintf(buf, "%d", el->vals[i][j]);
            mudaTexto(el->f[i][j], 30, buf);
        }
    }
}

void finalizar(elementos *el) {
    int i, j;
    fechaJanela(el->jan);
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 6; j++) {
            destroiForma(el->f[i][j]);
            destroiForma(el->fundo[i][j]);
        }
    }
}

int main() {
    int i, j, tami, tamj;
    char c;
    elementos el;
    inicializar(&el);
    do {
        do {
            printf("\n Digite o tamanho da linha (entre 1 e 6): ");
            fflush(stdin);
            scanf("%d", &tamj);
            printf("\n");
        } while(tamj <= 0 || tamj > 6);
        do {
            printf("\n Digite o tamanho da coluna (entre 1 e 10): ");
            fflush(stdin);
            scanf("%d", &tami);
            printf("\n");
        } while(tami <= 0 || tami > 10);
        for(i = 0; i < tami; i++) {
            for(j = 0; j < tamj; j++) {
                printf("digite o valor i = %d e j = %d: ", i, j);
                fflush(stdin);
                scanf("%d", &el.vals[i][j]);
                gerarMatriz(&el);
            }
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
