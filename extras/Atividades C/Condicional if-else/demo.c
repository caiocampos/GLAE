#include <stdio.h>
#include <janela.h>

enum formas {
	quadrado,
	circulo,
	triangulo,
	estrela,
	arco
};

typedef struct {
    janela *jan;
    forma *f[5];
} elementos;

void finalizar(elementos *el) {
    fechaJanela(el->jan);
    destroiForma(el->f[quadrado]);
    destroiForma(el->f[circulo]);
    destroiForma(el->f[triangulo]);
    destroiForma(el->f[estrela]);
    destroiForma(el->f[arco]);
}

int inicializar(elementos *el) {
    el->jan = criaJanela(800, 600, "teste");
    el->f[quadrado] = geraRetangulo(200, 200);
    el->f[circulo] = geraCirculo(120);
    el->f[triangulo] = geraTrianguloVazado(300, 200);
    el->f[estrela] = geraEstrela(100, 25, 4);
    el->f[arco] = geraArcoVazado(120, 180);
    if(!(el->jan && el->f[quadrado] && el->f[circulo] &&
		 el->f[triangulo] && el->f[estrela] && el->f[arco])) {
        finalizar(el);
        return 0;
    }
    return 1;
}

int main() {
    int v;
    elementos el;
    if(!inicializar(&el)) {
        printf("Erro de inicializacao\n");
        printf("Este programa será fechado");
        fflush(stdin);
        printf("\n Pressione Enter ");
        getchar();
        return -1;
    }
    printf("Atividade de if - else:\n");
    printf("\n     Menu\n\n");
    printf("Entre com um valor para x, sendo:\n\n");
    printf("       x <= -150. Para mostrar um quadrado;\n");
    printf("-150 < x <= -50.  Para mostrar um circulo;\n");
    printf("-50  < x <= 50.   Para mostrar um triangulo;\n");
    printf("50   < x <= 150.  Para mostrar um estrela;\n");
    printf("150  < x.         Para mostrar um arco;\n\n");
    printf(" Escreva o numero relativo a sua escolha: ");
    fflush(stdin);
    scanf("%d", &v);
    printf("\nVoce escreveu: %d\n\n", v);
    if(v <= -150) {
		printf("Adicionando um quadrado!\n");
		adicionaForma(el.jan, el.f[quadrado]);
    }
    else if(v <= -50) {
		printf("Adicionando um circulo!\n");
		adicionaForma(el.jan, el.f[circulo]);
    }
    else if(v <= 50) {
		printf("Adicionando um triangulo!\n");
		adicionaForma(el.jan, el.f[triangulo]);
    }
    else if(v <= 150) {
		printf("Adicionando um estrela!\n");
		adicionaForma(el.jan, el.f[estrela]);
    }
    else {
		printf("Adicionando um arco!\n");
		adicionaForma(el.jan, el.f[arco]);
    }
    fflush(stdin);
    printf("\nPressione Enter ");
    getchar();
    finalizar(&el);
    return 0;
}
