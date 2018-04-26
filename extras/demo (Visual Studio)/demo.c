#include "stdafx.h"

/************************************************************************
*   Este programa exibe todas as formas que a biblioteca GLAE pode      *
*   gerar e as modifica com transformações de rotação, translação e     *
*   redimensionamento. Também mostra o funcionamento da janela de       *
*   desenho em paralelo com a janela de comandos.                       *
************************************************************************/

forma *f[24]; // vetor de formas
janela *jl; // ponteiro para a janela
int it = 0; // posição da iteração
int cres = 1; // sinal que define se a iteração é crescente ou decrescente

void alocador(); // função que aloca os elementos da janela
void alterador(); // função que atualiza o desenho
void desalocar(); // função que limpa a memória usada pelo programa

int _tmain(int argc, _TCHAR* argv[]) { // função principal
    char t[40]; //string que armazena o texto escrito pelo usuário
    int i; // iterador para o comando "for"
    alocador(); // chama a função de alocação
    do { // entra no laço
        printf("\n Escreva um texto (sair para encerrar): ");
        scanf("%s", t); // é lido o texto que o usuário escreveu
        printf("\n Voce escreveu: %s\n", t); // exibe o texto escrito pelo usuário
        for(i = 0; t[i]; i++) t[i] = tolower(t[i]); // converte todo texto para minúsculo para fazer a comparação
    } while(strcmp(t, "sair")); // enquanto o texto for diferente de "sair" o laço se repete
    desalocar(); // depois que o usuário escreve sair o programa chama a função de limpeza de memória
    return 0; // retorna sinal de sucesso
}

void alocador() {
    int i; // iterador para o comando "for"
    jl = criaJanela(800, 600, "DemoTeste"); // cria a janela com 800px na horizontal e 600px na vertical com o nome "DemoTeste"

    defineCorInterna(255, 0, 0); // define a cor vermelho como cor interna
    defineCorBorda(255, 255, 0); // define a cor amarelo como cor de borda
    // como o tamanho de borda não foi definido ele será 1px

    definePosicao(-350, -200); // define a posição de desenho
    f[0] = geraArco(30, 60); // gera um arco de 60º sólido

    definePosicao(-250, -200); // define a posição de desenho
    f[1] = geraArcoAberto(30, 60); // gera um arco de 60º aberto

    definePosicao(-150, -200); // define a posição de desenho
    f[2] = geraArcoVazado(30, 60); // gera um arco de 60º vazado

    definePosicao(-50, -200); // define a posição de desenho
    f[3] = geraCirculo(30); // gera um círculo sólido

    definePosicao(50, -200); // define a posição de desenho
    f[4] = geraCirculoVazado(30); // gera um círculo vazado

    definePosicao(150, -200); // define a posição de desenho
    f[5] = geraElipse(30, 10); // gera uma elipse sólida

    definePosicao(250, -200); // define a posição de desenho
    f[6] = geraElipseVazado(30, 10); // gera uma elipse vazada

    definePosicao(350, -200); // define a posição de desenho
    f[7] = geraEstrela(30, 10, 7); // gera uma estrela de sete pontas sólida

    defineCorInterna(0, 205, 0); // define a cor verde como cor interna
    defineCorBorda(0, 255, 255); // define a cor ciano como cor de borda

    definePosicao(-350, 0); // define a posição de desenho
    f[8] = geraEstrelaVazado(30, 10, 7); // gera uma estrela de sete pontas vazada

    definePosicao(-250, 0); // define a posição de desenho
    f[9] = geraLinha(30); // gera uma linha

    definePosicao(-150, 0); // define a posição de desenho
    f[10] = geraPentagrama(30, 10); // gera um pentagrama sólido

    definePosicao(-50, 0); // define a posição de desenho
    f[11] = geraPentagramaVazado(30, 10); // gera um pentagrama vazado

    definePosicao(50, 0); // define a posição de desenho
    f[12] = geraPoligono(30, 6); // gera um hexágono sólido

    definePosicao(150, 0); // define a posição de desenho
    f[13] = geraPoligonoVazado(30, 6); // gera um hexágono vazado

    definePosicao(250, 0); // define a posição de desenho
    f[14] = geraPonto(); // gera um ponto

    definePosicao(350, 0); // define a posição de desenho
    f[15] = geraRetangulo(60, 40); // gera um retângulo sólido

    defineCorInterna(0, 0, 255); // define a cor azul como cor interna
    defineCorBorda(255, 0, 255); // define a cor magenta como cor de borda

    definePosicao(-350, 200); // define a posição de desenho
    f[16] = geraRetanguloVazado(60, 40); // gera um retângulo vazado

    definePosicao(-250, 200); // define a posição de desenho
    f[17] = geraSeta(30); // gera uma seta sólida

    definePosicao(-150, 200); // define a posição de desenho
    f[18] = geraSetaVazado(30); // gera uma seta vazada

    definePosicao(-50, 200); // define a posição de desenho
    f[19] = geraSetor(30, 120); // gera um setor sólido

    definePosicao(50, 200); // define a posição de desenho
    f[20] = geraSetorVazado(30, 120); // gera um setor vazado

    definePosicao(150, 200); // define a posição de desenho
    f[21] = geraTexto(90, "oi"); // gera um texto com a palavra "oi"

    definePosicao(250, 200); // define a posição de desenho
    f[22] = geraTriangulo(60, 60); // gera um triângulo sólido

    definePosicao(350, 200); // define a posição de desenho
    f[23] = geraTrianguloVazado(60, 60); // gera um triângulo vazado

    for(i = 0; i < 24; i++) adicionaForma(jl, f[i]); // adiciona todas as formas à janela
    mudaEspecial(jl, &alterador); // define a função "alterador" como função especial
}

void alterador() {
    int i; // iterador para o comando "for"
    if(cres) { // se o sinal "cres" está com o valor 1
        if(it <= 360) { // se o iterador é menor que 360
            for(i = 0; i < 8; i++) redimensionar(f[i], 1.001, 1.001); // aumenta as formas numeradas de 0 a 7
            for(i = 8; i < 16; i++) mover(f[i], 0.05, 0); // move para a direita as formas numeradas de 8 a 15
            for(i = 16; i < 24; i++) rodar(f[i], 0.5); // roda no sentido anti-horário as formas numeradas de 16 a 23
            it++; // incrementa o iterador
        }
        else cres = 0; // se o valor for maior que 360 muda o sinal para 0
    }
    else { // se o sinal "cres" está com o valor 0
        if(it >= -360) { // se o iterador é maior que -360
            for(i = 0; i < 8; i++) redimensionar(f[i], 1.0 / 1.001, 1.0 / 1.001); // diminui as formas numeradas de 0 a 7
            for(i = 8; i < 16; i++) mover(f[i], -0.05, 0); // move para a esquerda as formas numeradas de 8 a 15
            for(i = 16; i < 24; i++) rodar(f[i], -0.5); // roda no sentido horário as formas numeradas de 16 a 23
            it--; // reduz o iterador
        }
        else cres = 1; // se o valor for menor que -360 muda o sinal para 1
    }
}

void desalocar() {
    int i; // iterador para o comando "for"
    fechaJanela(jl); // fecha a janela
    for(i = 0; i < 24; i++) destroiForma(f[i]); // destrói todas as formas
}