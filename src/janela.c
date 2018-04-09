#include <stdlib.h>
#include <janela.h>

int n_janelas = 0; // quantidade de janelas GLFW ativas
mtx_t mutex; // vari�vel necess�ria para exclus�o mutua das threads
cor corFundo; // valor padr�o para cor de fundo

struct janInfo { // estrutura de auxilio na cria��o da janela
	janela *j; // inst�ncia da estrutura janela
	int x; // tamanho horizontal
	int y; // tamanho vertical
	char *titulo; // t�tulo
};

void desenhaForma(forma *f) { // desenha a forma a partir das informa��es contidas em f
	int i;
	if(!f || !f->pontos) return; // verifica se a forma e os pontos est�o alocados
	if(f->letras) { // verifica se � texto
		glColor3ub(f->corInterna.vermelho, f->corInterna.verde, f->corInterna.azul); // d� a cor para a borda
		for(i = 0; i < f->qtdLetras; i++) { // enquanto houver pontos
			glEnable(GL_TEXTURE_2D); // ativa o uso de textura
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // define o tipo de filtragem para aumentar a textura
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // define o tipo de filtragem para diminuir a textura
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, f->letras[i]->xprop, f->letras[i]->yprop,
                         0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, f->letras[i]->bmp); // define a textura a ser usada
			glBegin(f->tipo); // inicia o desenho
			glTexCoord2f(0.0, 0.0); // define a posi��o para a textura
			glVertex2d(f->pos.x + f->pontos[4 * i].x,
					   f->pos.y + f->pontos[4 * i].y); // desenha o ponto
			glTexCoord2f(0.0, (GLfloat)f->letras[i]->y / (GLfloat)f->letras[i]->yprop); // define a posi��o para a textura
			glVertex2d(f->pos.x + f->pontos[4 * i + 1].x,
					   f->pos.y + f->pontos[4 * i + 1].y); // desenha o ponto
			glTexCoord2f((GLfloat)f->letras[i]->x / (GLfloat)f->letras[i]->xprop, (GLfloat)f->letras[i]->y / (GLfloat)f->letras[i]->yprop); // define a posi��o para a textura
			glVertex2d(f->pos.x + f->pontos[4 * i + 2].x,
					   f->pos.y + f->pontos[4 * i + 2].y); // desenha o ponto
			glTexCoord2f((GLfloat)f->letras[i]->x / (GLfloat)f->letras[i]->xprop, 0.0); // define a posi��o para a textura
			glVertex2d(f->pos.x + f->pontos[4 * i + 3].x,
					   f->pos.y + f->pontos[4 * i + 3].y); // desenha o ponto
			glEnd(); // termina o desenho
			glDisable(GL_TEXTURE_2D); // disabilita a textura
		}
		return; // finaliza essa fun��o
	}
	if(f->tipo == GL_POINTS || f->tipo == GL_LINES || f->tipo == GL_LINE_LOOP || f->tipo == GL_LINE_STRIP) { // para pontos, linhas e formas vazadas
		glPushMatrix(); // in�cio da �rea de desenho
		glPointSize((GLfloat)f->tamBorda); // define o tamanho do ponto
		glLineWidth((GLfloat)f->tamBorda); // define o tamanho da linha ou borda
		glEnable(GL_LINE_SMOOTH);
		glBegin(f->tipo); // inicia o desenho
		glColor3ub(f->corBorda.vermelho, f->corBorda.verde, f->corBorda.azul); // d� a cor para a borda
		for(i = 0; i < f->qtdPontos; i++) { // enquanto houver pontos
			glVertex2d(f->pos.x + f->pontos[i].x,
					   f->pos.y + f->pontos[i].y); // desenha o ponto
		}
		glEnd(); // termina o desenho
		glPopMatrix(); // fim da �rea de desenho
		return; // finaliza essa fun��o
	}
	glPushMatrix(); // in�cio da �rea de desenho
	glPointSize((GLfloat)f->tamBorda); // define o tamanho do ponto
	glLineWidth((GLfloat)f->tamBorda); // define o tamanho da linha ou borda
	glEnable(GL_LINE_SMOOTH);
	if(f->tipo == GL_POLYGON) { // para c�rculo, pol�gono, el�pse, estrela, pentagrama
		glBegin(GL_TRIANGLE_FAN); // inicia o desenho
		glColor3ub(f->corInterna.vermelho, f->corInterna.verde, f->corInterna.azul); // d� a cor para a forma
		glVertex2d(f->pos.x, f->pos.y); // desenha o ponto de origem da forma, isso evita deforma��es
		for(i = 0; i < f->qtdPontos; i++) { // enquanto houver pontos
			glVertex2d(f->pos.x + f->pontos[i].x,
					   f->pos.y + f->pontos[i].y); // desenha o ponto
		}
		glVertex2d(f->pos.x + f->pontos[0].x,
				   f->pos.y + f->pontos[0].y); // desenha o ponto
		glEnd(); // termina o desenho
	}
	else { // outras formas
		glBegin(f->tipo); // inicia o desenho
		glColor3ub(f->corInterna.vermelho, f->corInterna.verde, f->corInterna.azul); // d� a cor para a forma
		for(i = 0; i < f->qtdPontos; i++) { // enquanto houver pontos
			glVertex2d(f->pos.x + f->pontos[i].x,
					   f->pos.y + f->pontos[i].y); // desenha o ponto
		}
		glEnd(); // termina o desenho
	}
	glBegin(GL_LINE_LOOP); // tra�a a borda
	glColor3ub(f->corBorda.vermelho, f->corBorda.verde, f->corBorda.azul); // d� a cor para a borda
	for(i = 0; i < f->qtdPontos; i++) { // enquanto houver pontos
		glVertex2d(f->pos.x + f->pontos[i].x,
				   f->pos.y + f->pontos[i].y); // desenha o ponto
	}
	glEnd(); // termina o desenho
	glPopMatrix(); // fim da �rea de desenho
}

int mainLoop(void *arg) { // thread que gera o la�o que desenha na tela
	int i, x, y;
	struct janInfo *ji;
	mtx_lock(&mutex); // inicia a trava de exclus�o mutua
	n_janelas++; // aumenta a quantidade de janelas
	ji = (struct janInfo *)arg; // converte o argumento recebido em um tipo utiliz�vel
	ji->j->win = glfwCreateWindow(ji->x, ji->y, ji->titulo, NULL, NULL); // cria a janela GLFW
	if(!ji || !ji->j || !ji->j->win || !ji->j->formas) { // verifica se janela n�o foi criada
		n_janelas--; // diminui quantidade de janelas
		mtx_unlock(&mutex); // termina a trava de exclus�o mutua
		if(n_janelas == 0) { // se n�o existem mais janelas
			mtx_destroy(&mutex); // destr�i a vari�vel de exclus�o mutua
			glfwTerminate(); // finaliza o GLFW
		}
		return -1; // retorna um sinal de erro
	}
	glfwMakeContextCurrent(ji->j->win); // faz com que essa thread tenha controle sobre essa janela
	mtx_unlock(&mutex); // termina a trava de exclus�o mutua
    while(!glfwWindowShouldClose(ji->j->win)) { // enquanto a janela n�o for fechada executa o la�o
		// inicio da �rea onde ser� definida a �rea de desenho
		glfwGetFramebufferSize(ji->j->win, &x, &y); // pega o tamanho vertical e horizontal da janela e joga em x e y, respectivamente
		glViewport(0, 0, x, y);
		glClearColor((GLclampf)(ji->j->corFundo.vermelho / 255.0),
					 (GLclampf)(ji->j->corFundo.verde    / 255.0),
					 (GLclampf)(ji->j->corFundo.azul     / 255.0),
					 1.0f); // limpa a tela com a cor de fundo
		glClear(GL_COLOR_BUFFER_BIT); // limpa o buffer de cor
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-x / 2, x / 2, -y / 2, y / 2, -1, 1); // define o eixo cartesiano
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // permite efeitos de transpar�ncia
		// final da �rea onde ser� definida a �rea de desenho
		mtx_lock(&mutex); // inicia a trava de exclus�o mutua
		for(i = 0; i < ji->j->nFormas; i++) { // enquanto existirem poss�veis formas instanciadas
			desenhaForma(ji->j->formas[i]); // se a forma estiver instanciada, a desenha
		}
		mtx_unlock(&mutex); // termina a trava de exclus�o mutua
		if(ji->j->especial) ji->j->especial(); // se foi instanciada uma fun��o que trabalha manualmente com o OpenGL, a executa
		glDisable(GL_BLEND);
		glfwSwapBuffers(ji->j->win); // refresca os buffers
		glfwPollEvents(); // verifica eventos pendentes
	}
	glfwDestroyWindow(ji->j->win); // destr�i a janela GLFW
	if(n_janelas == 0) { // se n�o existem mais janelas
		mtx_destroy(&mutex); // destr�i a vari�vel de exclus�o mutua
		glfwTerminate(); // finaliza o GLFW
	}
    n_janelas--; // diminui quantidade de janelas
    free(ji->j->formas); // libera o espa�o para as formas
    free(ji->j); // libera o espa�o para a janela
	free(ji); // libera a mem�ria usada pelas informa��es da janela
	return 0; // retorna sinal de sucesso
}

janela *criaJanela(int x, int y, char *titulo) {
	struct janInfo *ji;
	thrd_t t;
	if(n_janelas == 0) { // se n�o existem janelas abertas
		if(mtx_init(&mutex, mtx_plain) != thrd_success) return NULL; // cria a vari�vel de exclus�o mutua
		if(!glfwInit()) return NULL; // tenta inicializar o GLFW, caso der erro retorna nulo
		defineCorBorda(255, 255, 255); // define a cor inicial da borda
		defineCorInterna(255, 255, 255); // define a cor interna inicial
		definePosicao(0.0, 0.0); // define a cor inicial de desenho
		defineTamanhoBorda(1); // define o tamanho inicial da borda
		corFundo = geraCor(0, 0, 0); // define a cor inicial do fundo
	}
	ji = (struct janInfo *)malloc(sizeof(struct janInfo)); // aloca espa�o para as informa��es da janela
	if(!ji) return NULL; // verifica se as informa��es da janela foram alocadas
	ji->j = (janela *)calloc(1, sizeof(janela)); // aloca espa�o para a janela
	if(!ji->j) { // verifica de a janela foi alocada
		free(ji); // libera a mem�ria usada pelas informa��es da janela
		return NULL; // retorna valor nulo
	}
	ji->j->maxFormas = 20; // inst�ncia o m�ximo de formas da janela como 20
	ji->j->formas = (forma **)calloc(ji->j->maxFormas, sizeof(forma *)); // aloca espa�o para o vetor de formas
	if(!ji->j->formas) { // verifica se o vetor de formas foi alocado
		free(ji->j); // libera a mem�ria usada pela janela
		free(ji); // libera a mem�ria usada pelas informa��es da janela
		return NULL; // retorna valor nulo
	}
	ji->j->corFundo = corFundo; // inst�ncia a cor de fundo da janela
	ji->x = x; // inst�ncia o tamanho horizontal
	ji->y = y; // inst�ncia o tamanho vertical
	ji->titulo = titulo; // inst�ncia o t�tulo
	if(thrd_create(&t, mainLoop, (void *)ji) == thrd_success) { // cria a thread, se funcionar
		return ji->j; // retorna a janela
	}
	free(ji->j->formas); // libera a mem�ria usada pelo vetor de formas
	free(ji->j); // libera a mem�ria usada pela janela
	free(ji); // libera a mem�ria usada pelas informa��es da janela
	return NULL; // se a thread n�o for criada retorna nulo
}

void fechaJanela(janela *j) {
	if(j) { // verifica se a janela foi alocada
        limpaJanela(j); // limpa o vetor de formas da janela
		mtx_lock(&mutex); // inicia a trava de exclus�o mutua
        if(!glfwWindowShouldClose(j->win)) { // se a janela est� aberta
            glfwSetWindowShouldClose(j->win, GL_TRUE); // for�a a janela a fechar
        }
        mtx_unlock(&mutex); // termina a trava de exclus�o mutua
	}
}

void mudaEspecial(janela *j, void (*especial)()) {
	if(j) j->especial = especial; // inst�ncia a fun��o que ir� trabalhar manualmente com o OpenGL
}

void mudaCorFundo(janela *j, int vermelho, int verde, int azul) {
	if(j) j->corFundo = geraCor(vermelho, verde, azul); // define a cor de fundo da janela
}

int adicionaForma(janela *j, forma *f) {
	int i, newMax;
	if(!j || !f || !f->pontos) return -1; // se a forma ou a janela forem ponteiros inv�lidos, retorna erro
	for(i = 0; i < j->nFormas; i++) { // para todas as formas
		if(j->formas[i] == f) {
			return 0; // se a forma f j� est� adicionada, retorna sucesso
		}
	}
	if(j->nFormas == j->maxFormas) { // se o limite foi alcan�ado
		newMax = j->maxFormas + 20; // aumenta em 20 o m�ximo
		j->formas = (forma **)realloc(j->formas, newMax * sizeof(forma *)); // realoca a mem�ria
		if(!j->formas) return -1; // se n�o conseguiu realocar retorna erro
		for(i = j->nFormas; i < newMax; i++) j->formas[i] = NULL; // limpa o lixo de mem�ria
		j->maxFormas = newMax; // atualiza o limite de formas
	}
	j->formas[j->nFormas] = f; // inst�ncia a forma
	j->nFormas++; // aumenta a quantidade de formas relacionadas a janela j
	f->nJanelas++; // aumenta a quantidade de janelas relacionadas a forma f
	return 0; // retorna sinal de sucesso
}

int removeForma(janela *j, forma *f) {
	int i, k, oldMax;
	if(!j || !f || !f->nJanelas) return -1;
	oldMax = j->nFormas; // inst�ncia o n�mero de formas antes da remo��o
	mtx_lock(&mutex); // inicia a trava de exclus�o mutua
	for(i = k = 0; i < oldMax; i++) { // enquanto existirem poss�veis formas instanciadas
		if(k == 0 && j->formas[i] == f) k = 1; // se encontrou a forma, muda o estado de k
		if(k == 1) { // se a forma j� foi encontrada
            if(i + 1 < oldMax) j->formas[i] = j->formas[i+1]; // move a pr�xima forma para o ponteiro atual
            else j->formas[i] = NULL; // se forma a �ltima forma, anula seu ponteiro
		}
	}
	j->nFormas--; // diminui a quantidade de formas relacionadas a janela j
	f->nJanelas--; // diminui a quantidade de janelas relacionadas a forma f
	mtx_unlock(&mutex); // termina a trava de exclus�o mutua
	return 0; // retorna sinal de sucesso
}

int limpaJanela(janela *j) {
	int i, t;
	if(!j) return -1; // verifica se a janela foi alocada
	mtx_lock(&mutex); // inicia a trava de exclus�o mutua
	t = j->nFormas; // inst�ncia o n�mero de formas antes da limpeza
	j->nFormas = 0; // zera o n�mero de formas
	for(i = 0; i < t; i++) { // enquanto existirem poss�veis formas instanciadas
		if(j->formas[i]) { // se a �rea foi instanciada
			j->formas[i]->nJanelas--; // diminui a quantidade de janelas relacionadas a forma
			j->formas[i] = NULL; // anula a forma
		}
	}
	mtx_unlock(&mutex); // termina a trava de exclus�o mutua
	return 0; // retorna sinal de sucesso
}
