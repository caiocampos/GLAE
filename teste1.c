#include <stdio.h>
#include <glae.h>

int main() {
	forma *f1, *f2;
    int val = 1;
    janela *j = criaJanela(800, 600, "teste");
    defineCorBorda(0, 255, 0);
    defineTamanhoBorda(14.5);
    f1 = geraRetangulo(600.0, 70.0);
    defineCorInterna(0, 0, 255);
    f2 = geraTexto(50, "Testando um texto qualquer! Funcionou?");
    adicionaForma(j, f1);
    adicionaForma(j, f2);
    mudaCorFundo(j, 127, 127, 127);
    while(val) {
        printf("\n Escreva um numero (1 para ajuda): ");
        scanf("%d", &val);
        printf("\n Voce escreveu: %d\n", val);
        switch(val) {
            case 1: printf("\n");
                    printf(" 0.  Sair\n");
                    printf(" 1.  Ajuda\n");
                    printf(" 2.  Remove o texto\n");
                    printf(" 3.  Retorna o texto\n");
                    printf(" 4.  Dobra o tamanho do texto\n");
                    printf(" 5.  Reduz pela metade o tamanho do texto\n");
                    printf(" 6.  Move o texto para direita\n");
                    printf(" 7.  Move o texto para esquerda\n");
                    printf(" 8.  Roda o texto 30 graus\n");
                    printf(" 9.  Roda o texto -30 graus\n");
                    printf("\n");
                    break;
            case 2: removeForma(j, f2);
                    break;
            case 3: adicionaForma(j, f2);
                    break;
            case 4: redimensionar(f2, 2.0, 2.0);
                    break;
            case 5: redimensionar(f2, 0.5, 0.5);
                    break;
            case 6: mover(f2, 30.0, 0.0);
                    break;
            case 7: mover(f2, -30.0, 0.0);
                    break;
            case 8: rodar(f2, 30.0);
                    break;
            case 9: rodar(f2, -30.0);
        }
    }
    fechaJanela(j);
    destroiForma(f1);
    destroiForma(f2);
    return 0;
}
