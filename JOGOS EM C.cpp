#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <time.h>


//JOGOS EM C
//Nomes : Thiago Santos, Vinicius Torcheto

typedef struct {
	char nome[20];
	int idade;
	int pontos;
}JOGADORES;

void esperatecla(void);
void passaavez(void);
void esperateclaparasair(void);
void esperateclaparavoltar(void);
void selecaodejogos(void);
//Jogo da velha
void mapajogodavelha(void);
void instrucaojogodavelha(void);
void velhajogadores(void);
void mapajogodavelha2(void);
void ImprimeMapaDoJogoEmAndamento(char a,char b,char c,char d,char e,char f,char g,char h,char i);
void ValidaVitoriaJogador1eJogador2(char a,char b,char c,char d,char e,char f,char g,char h,char i, int *controle, int *p);
//Jogo do milhão
void milhaoperguntascomresp(int *errado, int *certo, int *numperguntas);
void intrucaojogodomilhao(void); 
void resultadosmilhao(int errado, int certo, int numperguntas);
//jogo do roda-roda (UTILIZADO VETORES NESSE JOGO)
void intrucaojogorodaroda(void);
int roletarodaroda(void);
void logicajogorodaroda(int pontuacaorodaroda,char palavradarodaroda[ ],char letras[ ],int numpalavradarodaroda);
void funcaopalavradarodaroda(char palavradarodaroda[ ],char letras[ ], int *numpalavradarodaroda);
//jogo caça-palabra 	(UTILIZADO VETORES NESSE JOGO)
void intrucaojogocacapalavra(void);
void mapacacapalavra1(void);
void mapacacapalavra2(void);
void mapacacapalavra3(void);
void selecaocacapalavra1(void);
void selecaocacapalavra2(void);
void selecaocacapalavra3(void);
//jogo runball
void intrucaojogorunball(void);
void opcaojogorunball(void);
int cadastrojogadorrunball(FILE *ARQ,JOGADORES jog,int *idade,char nome[ ]);
void relatoriojogadoresrunball(FILE *ARQ,JOGADORES jog);
void JogoRunBall(FILE *ARQ,JOGADORES jog,int idaderunball,char nomerunball[ ]);
void imprimemap(int matrizmap[10][10], int posy, int posx, int pontos[]);
void instrucaomovimentacaojogador(void);
void ControleEixoYJogador(int posx, int *controle_y);
void ControleEixoXJogadorPontosEsquerda(int posx, int *controle_x, int pontos[]);
void ControleEixoXJogador(int posx, int *controle_x);
void MovimenParedeDireitaEmX_Pontos(int posx, int *controle_x, int pontos[], int p);
void MovimenParedeDireitaEmX(int posx, int *controle_x);
int verificacolisao(int contr_y, int contr_x);
int AdicionaPontos(int pontos[], int *velocidade);
void criaarquivobinario(FILE *ARQ,JOGADORES jog);
 
 int main(void) //LAÇO PARA RODAR O JOGO
{
selecaodejogos();
}

//######################### SELEÇÃO_DOS_JOGOS #################################

void selecaodejogos(void) //função para selecionar entre os jogos
{
	int jogo=0;
	int errado=0, certo=0, numperguntas=0;
	int pontuacaorodaroda, numpalavradarodaroda;
	char palavradarodaroda[60], letras[10];
	do{
	printf("Selecione o Jogo que você quer jogar conforme a numeração e digite o número correspondente. \n\n",setlocale(LC_ALL,"")); //  Comando setlocale(LC_ALL,"") utilizado para possibilitar a utilização de acentos ortograficos
	printf("1 - JOGO DA VELHA \n");
	printf("2 - JOGO DO MILHÃO \n");
	printf("3 - JOGO DO RODA-RODA\n");
	printf("4 - JOGO CACA PALAVRA\n");
	printf("5 - JOGO RUNBALL\n");
	printf("6 - SAIR\n\n");
	fflush(stdin);
	jogo = getche();
	if((jogo != 49) && (jogo != 50) && (jogo != 51) && (jogo != 52) && (jogo != 53) && (jogo != 54)){
		printf("\nO número digitado não é uma opção de um jogo. \n\n");
	}
	}while((jogo != 49) && (jogo != 50) && (jogo != 51) && (jogo != 52) && (jogo != 53) && (jogo != 54)); // Comando while utilizado para apenas aceitar um imput de 1,2,3,4,5 ou 6 que são respectivamente os jogos.
	system("cls");
	switch(jogo) //utilizado comando switch para selecionar entre os jogos criados.
	{
		case 49:
			printf("	JOGO DA VELHA \n");
			instrucaojogodavelha();
			mapajogodavelha();
			esperatecla();
			system("cls");
			mapajogodavelha2();
			velhajogadores();
			printf("\n");
			system("pause");
			system("cls");
			selecaodejogos();
			break;
		case 50:
			printf("	JOGO DO MILHÃO \n");
			intrucaojogodomilhao();
			esperatecla();
			system("cls");
			milhaoperguntascomresp(&errado, &certo, &numperguntas);
			resultadosmilhao(errado, certo, numperguntas);
			printf("\n");
			system("pause");
			system("cls");
			selecaodejogos();
			break;
		case 51:
			printf("	JOGO DO RODA-RODA \n");
			intrucaojogorodaroda();
			esperatecla();
			system("cls");
			pontuacaorodaroda = roletarodaroda();
			funcaopalavradarodaroda(palavradarodaroda,letras,&numpalavradarodaroda);
			logicajogorodaroda(pontuacaorodaroda,palavradarodaroda,letras,numpalavradarodaroda);
			printf("\n");
			system("pause");
			system("cls");
			selecaodejogos();
			break;
		
		case 52:
			printf("	JOGO CACA PALAVRA \n");
			intrucaojogocacapalavra();
			esperatecla();
			system("cls");
			selecaocacapalavra1();
			esperatecla();
			selecaocacapalavra2();
			esperatecla();
			selecaocacapalavra3();
			printf("\n");
			system("pause");
			system("cls");
			selecaodejogos();
			break;
		case 53:
			printf("	JOGO RUNBALL\n");
			opcaojogorunball();
			system("cls");
			selecaodejogos();
		case 54:
			printf("\nSAINDO DA SELEÇÃO DE JOGOS");
			break;
	}
}

//######################### INSTRUÇÔES_PADRÔES ################################

void esperatecla(void) //função para esperar um avança
{
	int tecla;
	printf("\n\nPressione a tecla [A] quando estiver pronto. \n");
	do {
		tecla = getch(); //comando para ler a tecla do teclado
		if (tecla != 65 && tecla != 97) { //numero da tecla retirado da tabela asci 
			printf("Pressione a tecla [A] quando estiver pronto. \n");
		}
	}while(tecla != 65 && tecla != 97);
	return;
}

void passaavez(void) //função para esperar um avança utilizando a tecla P
{
	int tecla;
	printf("\n\nPressione a tecla [P] para passar a vez. \n");
	do {
		tecla = getch(); //comando para ler a tecla do teclado
		if (tecla != 80 && tecla != 112) { //numero da tecla retirado da tabela asci 
			printf("Pressione a tecla [P] para passar a vez. \n");
		}
	}while(tecla != 80 && tecla != 112);
	return;
}

void esperateclaparasair(void) //função para esperar um "S"
{
	int tecla;
	printf("\n\nPressione a tecla [S] para sair. \n");
	do {
		tecla = getch(); //comando para ler a tecla do teclado
		if (tecla != 83 && tecla != 115) { //numero da tecla retirado da tabela asci 
			printf("Pressione a tecla [S] para sair. \n");
		}
	}while(tecla != 83 && tecla != 115);
	return;
}

void esperateclaparavoltar(void) //função para esperar um "V"
{
	int tecla;
	printf("\n\nPressione a tecla [V] para voltar. \n");
	do {
		tecla = getch(); //comando para ler a tecla do teclado
		if (tecla != 86 && tecla != 118) { //numero da tecla retirado da tabela asci
			printf("Pressione a tecla [V] para voltar. \n");
		}
	}while(tecla != 86 && tecla != 118);
	return;
}

//########################### INSTRUÇÔES ######################################

void instrucaojogodavelha(void) // função para printar as informações necessarias para jogar o jogo da velha
{
	printf("\nCOMO JOGAR: \n\n");
	printf("Na grade abaixo foram adicionados 9 números, cada número representa um espaço. \nPara jogar este jogo é necessário dois jogadores, aonde o  JOGADOR 1 será o 'X' e o JOGADOR 2 será o 'O'. \nOs jogadores deverão digitar o número referente ao espaço a qual desejam posicionar seu símbolo representante, \nsempre respeitando a vez de cada jogador. \n \n");
	
}

void intrucaojogodomilhao(void) // função para printar as informações necessarias para jogar o jogo do milhão
{
	printf("\nCOMO JOGAR: \n\n");
	printf("O jogo do milhão é jogado por apenas um jogador, e funciona da seguinte forma, o jogador recebera uma pergunta \ne 4 alternativas, dentre elas uma será a alternativa correta. Para o jogador responder a pergunta \nele deve digitar o número que esta representando a alternativa e pressionar a tecla enter.");	
}

void intrucaojogorodaroda(void) // função para printar as informações necessarias para jogar o jogo roda roda
{
	printf("\nCOMO JOGAR: \n\n");
	printf("1 - Digite o comando para iniciar;\n\n");
	printf("2 - Jogo é jogado por 2 jogadores;\n\n");
	printf("3 - O desafio é completar a palavra acertando letra a letra;\n\n");
	printf("4 - Antes de cada letra será rodado a roleta para definir o valor das letras;\n\n");
	printf("5 - Os valores são de 1000 até 9000, e possui uma armadilha que passa a vez do jogador;\n\n");
	printf("6 - Caso a letra digitada não possua na palavra, será passado a vez para o próximo jogador;\n\n");
	printf("7 - Vence o jogador que completar a palavra;\n\n");
	printf("8 - Ao final, é mostrado o valor total acumulado do vencedor;\n\n");		
}

void intrucaojogorunball(void) // função para printar as informações necessarias para jogar o jogo caça-palavra
{
	printf("\nCOMO JOGAR: \n\n");	
	printf("1 - Utilize as teclas 'W,A,S,D' para movimentar o personagem no jogo;\n\n");
	printf("2 - No jogo você será a bolinha, que inicialmente estará no centro do quadrado;\n\n");
	printf("3 - O objetivo é passar por cima dos quadrados que irão aparecer durante o jogo;\n\n");
	printf("4 - Caso o personagem encoste nas extremidades do quadrado você perde;\n\n");
	printf("5 - Preencha o cadastro assim que o jogo iniciar, voce ganhara pontos a medida que for ganhando o jogo\n\n");
}

void intrucaojogocacapalavra(void)
{
	printf("\nCOMO JOGAR: \n\n");
	printf("1 - Digite o comando para iniciar;\n\n");	
	printf("2 - Procure as palavras na tabela e digite-as com todas as letras no campo indicado;\n\n");
	printf("3 - Caso a palavra tenha espaçamentos o jogador deve utilizar o '_', para substituir os espaços;\n\n");
	printf("4 - Não utilize acéntos ao digitar a palavra;\n\n");
	printf("4 - Ao digitar a palavra correta, ela será descrita na tela\n\n");
	printf("5 - Cada estágio possui 5 ou 6 palavras. Para passar de fase, o jogador deve acertar todas as palavras do nível;\n\n");	
}

//########################### MAPAS ###########################################

void mapajogodavelha(void) //função para aparecer a grade do jogo da velha
{
   printf("1|2|3\n");
   printf("-----\n");
   printf("4|5|6\n");
   printf("-----\n");
   printf("7|8|9\n");
   
}

void mapajogodavelha2(void) //função para aparecer a grade do com mais informações do jogo da velha
{
   printf("\n");
   printf("JOGO DA VELHA\n\n");
   printf("JOGADOR 1 = X | ");
   printf("JOGADOR 2 = O\n\n");
   printf("1|2|3\n");
   printf("-----\n");
   printf("4|5|6\n");
   printf("-----\n");
   printf("7|8|9\n");
   
}

void mapacacapalavra1(void) //função para aparecer as palavras misturadas da 1 fase no jogo caça palavras
{
//FRUTAS: BERGAMOTA, BANANA, GOIABA, MELANCIA, UVA, LARANJA
	printf("				FASE 1(FRUTAS)");
	printf("\n\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | B | G | R | T | Y | X | C | R | Q | W | E | R | T | Y | G |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | A | E | R | T | Y | V | F | E | A | A | W | W | A | O | A |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | N | G | R | T | Y | Z | M | M | I | I | I | J | I | L | A |\n");	
	printf("  -------------------------------------------------------------\n");
	printf("  | A | G | R | G | Y | R | Y | B | C | C | E | A | O | I | A |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | N | G | R | T | A | A | R | R | T | N | B | Z | M | Q | E |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | A | G | R | T | Y | M | H | B | T | A | A | A | B | B | F |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | U | G | R | T | Y | O | O | O | L | L | I | M | N | X | V |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | V | G | R | T | Y | Z | Q | T | T | E | V | I | J | T | W |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | A | G | R | T | Y | D | R | E | A | M | Y | A | N | N | J |\n");
	printf("  -------------------------------------------------------------\n");	
}

void mapacacapalavra2(void) //função para aparecer as palavras misturadas da 2 fase no jogo caça palavras
{
//MARVEL: WOLVERINE, HOMEM_DE_FERRO, GAMBIT, HULK, CAPITAO_AMERICA
	printf("				FASE 2(SUPER-HERÓIS DA MARVEL)");
	printf("\n\n\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | B | G | R | T | Y | X | C | R | Q | W | E | R | T | Y | G |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | A | A | R | T | Y | V | F | E | A | A | W | W | A | O | A |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | N | M | R | T | Y | Z | M | M | I | I | I | J | I | L | A |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | A | B | R | G | Y | R | Y | B | C | C | E | A | O | I | A |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | N | I | R | T | A | A | R | R | T | N | B | Z | M | Q | E |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | C | A | P | I | T | A | O | A | M | E | R | I | C | A | F |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | U | W | O | L | V | E | R | I | N | E | I | M | N | X | V |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | V | G | R | O | R | R | E | F | E | D | M | E | M | O | H |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | H | U | L | K | Y | D | R | E | A | M | Y | A | N | N | J |\n");
	printf("  -------------------------------------------------------------\n");	
}

void mapacacapalavra3(void) //função para aparecer as palavras misturadas da 3 fase no jogo caça palavras
{
	//UTENCÍLIOS DOMESTICOS: COPO, TOALHA, FORNO, MICROONDAS, CAFETEIRA
	printf("				FASE 3(UTENCÍLIOS DOMESTICOS)"); 
	printf("\n\n\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | A | C | O | P | O | X | C | R | Q | W | E | R | T | Y | G |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | A | R | R | O | T | A | F | E | I | R | A | W | A | O | A |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | M | M | I | C | R | O | O | N | D | A | S | J | I | L | A |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | A | G | R | E | A | R | Y | B | C | C | E | A | O | I | A |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | N | G | R | T | T | A | R | R | T | O | B | Z | M | Q | E |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | A | G | R | T | H | E | H | B | T | N | A | A | B | B | F |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | U | G | R | T | A | O | F | O | L | R | I | M | N | X | V |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | T | O | A | L | H | A | Q | A | T | O | V | I | J | T | W |\n");
	printf("  -------------------------------------------------------------\n");
	printf("  | A | G | R | T | Y | D | R | E | C | F | Y | A | N | N | J |\n");
	printf("  -------------------------------------------------------------\n");


}


//########################### TESTES ##########################################

void velhajogadores(void) // função que controla o direcionamento da opção escolhida pelos jogadores juntamente com a validação do resultado.
{
	int controle, jogador=1, p, cont=1;
	char a='1',b='2',c='3',d='4',e='5',f='6',g='7',h='8',i='9';
	for(controle=1;controle<=9;controle++){	
	
	if(jogador==1){ //DIRECIONAMETO DO JOGADOR 1 (X) 
	do{	
		do{
	printf("\n\nJOGADOR 1\nDigite o número e pressione enter: "); 
	scanf("%d",&p);
	
	if( (a=='X' && p==1) || (a=='O' && p==1) || (b=='X' && p==2) || (b=='O' && p==2) || (c=='X' && p==3) || (c=='O' && p==3) || (d=='X' && p==4) || (d=='O' && p==4) || (e=='X' && p==5) || (e=='O' && p==5) || (f=='X' && p==6) || (f=='O' && p==6) || (g=='X' && p==7) || (g=='O'&& p==7) || (h=='X' && p==8) || (h=='O' && p==8) || (i=='X' && p==9) || (i=='O' && p==9) )  {
		printf("\nJogador 1 você digitou um número que já foi digitado. Digite novamente o número!",setlocale(LC_ALL,"")); // Teste do if para verificar se o numero ja foi digitado	
	}
		}while((a=='X' && p==1) || (a=='O' && p==1) || (b=='X' && p==2) || (b=='O' && p==2) || (c=='X' && p==3) || (c=='O' && p==3) || (d=='X' && p==4) || (d=='O' && p==4) || (e=='X' && p==5) || (e=='O' && p==5) || (f=='X' && p==6) || (f=='O' && p==6) || (g=='X' && p==7) || (g=='O'&& p==7) || (h=='X' && p==8) || (h=='O' && p==8) || (i=='X' && p==9) || (i=='O' && p==9));
	if(p==1){ 
		a = 'X';		
	}
	else{
		if(p==2){
			b = 'X';	
		}
		else{
			if(p==3){
				c = 'X';	
			}
			else{
				if(p==4){
					d = 'X';
				}
				else {
					if(p==5){
						e = 'X';
					}
					else{
						if(p==6){
							f = 'X';
						}
						else{
							if(p==7){
								g = 'X';
							}
							else{
								if(p==8){
									h = 'X';
								}
								else{
									if(p==9){
										i = 'X';
									}
								}
							}
						}
					}
				}	
			}
		}
	}
	if(p<1 || p>9){ //Teste para verificar se o numero esta dentro do intervalo 1 a 9
		printf("\nJogador 1 você digitou um número que não esta na grade do jogo. Digite novamente o número!");
	}
	}while(p<1 || p>9 );
	jogador = jogador + 1;
	system("cls");
	}
	
	else{ //DIRECIONAMENTO DO JOGADOR 2 (O)
	do{
		do{		
	printf("\n\nJOGADOR 2\nDigite o número e pressione o enter: ");
	scanf("%d",&p);
	
	if( (a=='X' && p==1) || (a=='O' && p==1) || (b=='X' && p==2) || (b=='O' && p==2) || (c=='X' && p==3) || (c=='O' && p==3) || (d=='X' && p==4) || (d=='O' && p==4) || (e=='X' && p==5) || (e=='O' && p==5) || (f=='X' && p==6) || (f=='O' && p==6) || (g=='X' && p==7) || (g=='O'&& p==7) || (h=='X' && p==8) || (h=='O' && p==8) || (i=='X' && p==9) || (i=='O' && p==9) )  {
		printf("\nJogador 2 você digitou um número que já foi digitado. Digite novamente o número!"); // Teste do if para verificar se o numero ja foi digitado	
	}
		}while((a=='X' && p==1) || (a=='O' && p==1) || (b=='X' && p==2) || (b=='O' && p==2) || (c=='X' && p==3) || (c=='O' && p==3) || (d=='X' && p==4) || (d=='O' && p==4) || (e=='X' && p==5) || (e=='O' && p==5) || (f=='X' && p==6) || (f=='O' && p==6) || (g=='X' && p==7) || (g=='O'&& p==7) || (h=='X' && p==8) || (h=='O' && p==8) || (i=='X' && p==9) || (i=='O' && p==9));
		
	if(p==1){
		a = 'O';
	}
	else{
		if(p==2){
			b = 'O';	
		}
		else{
			if(p==3){
				c = 'O';	
			}
			else{
				if(p==4){
					d = 'O';
				}
				else {
					if(p==5){
						e = 'O';
					}
					else{
						if(p==6){
							f = 'O';
						}
						else{
							if(p==7){
								g = 'O';
							}
							else{
								if(p==8){
									h = 'O';
								}
								else{
									if(p==9){
										i = 'O';
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(p<1 || p>9){
		printf("\nJogador 2 você digitou um número que não esta na grade do jogo. Digite novamente o número!");
	}
	}while(p<1 || p>9);
	jogador = 1;
	system("cls");	
	}

	ImprimeMapaDoJogoEmAndamento(a,b,c,d,e,f,g,h,i);
   
			//############# TESTE_VALIDAÇÂO ##############   
	ValidaVitoriaJogador1eJogador2(a,b,c,d,e,f,g,h,i,&controle,&p);
	
	}
}

void ImprimeMapaDoJogoEmAndamento(char a,char b,char c,char d,char e,char f,char g,char h,char i){
   printf("\n");
   printf("JOGO DA VELHA\n\n");
   printf("JOGADOR 1 = X | ");
   printf("JOGADOR 2 = O\n\n");
   printf("%c|%c|%c\n",a,b,c);
   printf("-----\n");
   printf("%c|%c|%c\n",d,e,f);
   printf("-----\n");
   printf("%c|%c|%c\n",g,h,i);
}

void ValidaVitoriaJogador1eJogador2(char a,char b,char c,char d,char e,char f,char g,char h,char i, int *controle, int *p){
	//######## VALIDA VITORIA JOGADOR 1 ##########
	if(a=='X' && b=='X' && c=='X'){
		printf("\n JOGADOR 1 GANHOU");
		*controle = 10;
		}
	else{
		if(d=='X' && e=='X' && f=='X'){
		printf("\n JOGADOR 1 GANHOU");
		*controle = 10;
		}
		else{
			if(g=='X' && h=='X' && i=='X'){
			printf("\n JOGADOR 1 GANHOU");
			*controle = 10;	
			}
			else{
				if(a=='X' && d=='X' && g=='X'){
				printf("\n JOGADOR 1 GANHOU");
				*controle = 10;	
				}
				else{
					if(b=='X' && e=='X' && h=='X'){
					printf("\n JOGADOR 1 GANHOU");
					*controle = 10;	
					}
					else{
						if(c=='X' && f=='X' && i=='X'){
						printf("\n JOGADOR 1 GANHOU");
						*controle = 10;
						}
						else{
							if(a=='X' && e=='X' && i=='X'){
							printf("\n JOGADOR 1 GANHOU");
							*controle = 10;
							}
							else{
								if(c=='X' && e=='X' && g=='X'){
								printf("\n JOGADOR 1 GANHOU");
								*controle = 10;
								}
								else{
									//######## VALIDA VITORIA JOGADOR 2 ##########
									if(a=='O' && b=='O' && c=='O'){
										printf("\n JOGADOR 2 GANHOU");
										*controle = 10;
										}
									else{
										if(d=='O' && e=='O' && f=='O'){
										printf("\n JOGADOR 2 GANHOU");
										*controle = 10;
										}
										else{
											if(g=='O' && h=='O' && i=='O'){
											printf("\n JOGADOR 2 GANHOU");
											*controle = 10;	
											}
											else{
												if(a=='O' && d=='O' && g=='O'){
												printf("\n JOGADOR 2 GANHOU");
												*controle = 10;	
												}
												else{
													if(b=='O' && e=='O' && h=='O'){
													printf("\n JOGADOR 2 GANHOU");
													*controle = 10;	
													}
													else{
														if(c=='O' && f=='O' && i=='O'){
														printf("\n JOGADOR 2 GANHOU");
														*controle = 10;
														}
														else{
															if(a=='O' && e=='O' && i=='O'){
															printf("\n JOGADOR 2 GANHOU");
															*controle = 10;
															}
															else{
																if(c=='O' && e=='O' && g=='O'){
																printf("\n JOGADOR 2 GANHOU");
																*controle = 10;
																}
																else{
																	if(*controle==9){
																	printf("\n NENHUM JOGADOR GANHOU!");	
																	}
																	}
																}	
															}
														}		
													}
												}
											}
										}
									}
								}	
							}
						}		
					}
				}
			}
		}			
   *p=0;
}



void milhaoperguntascomresp(int *errado, int *certo, int *numperguntas) // função que gera as perguntas e respostas do jogo do milhao.
{
	int selecao;

//########################### RESPOSTA NA POSIÇÃO 1 #########################	
	printf("O que era Frankenstein, de Mary Shelley? \n");
	printf("1- MONSTRO 			5- SAIR\n");	
	printf("2- GORILA \n");
	printf("3- PRÍNCIPE \n");
	printf("4- SAPO \n");
	selecao = getche();
	
	if(selecao==53){
		esperateclaparasair();
		system("cls");
		selecaodejogos();
		exit(0);	
	}
	else{
		
	if(selecao != 49){ //MODELELO PARA PERGUNTA COM RESPOSTA NO 1
		printf("\nVocê digitou a resposta errada!! \n\n");
		printf("RESPOSTA CORRETA : 1-MONSTRO\n\n\n\n");
		*errado = *errado +1;
		}
		else {
		printf("\nPARABÉNS! Você acertou a pergunta! \n\n\n\n");
		*certo = *certo +1;
		}
		}
		
	*numperguntas = *numperguntas + 1;		

//########################### RESPOSTA NA POSIÇÃO 2 #########################	
	printf("		PRÓXIMA PERGUNTA\n");
	printf("Em que estado brasileiro nasceu a apresentadora Xuxa? \n");
	printf("1- RIO DE JANEIRO 		5- SAIR\n");	
	printf("2- RIO GRANDE DO SUL \n");
	printf("3- SANTA CATARINA \n");
	printf("4- GOIÁS \n\n");
	selecao = getche();
	
	if(selecao==53){
		system("cls");
		resultadosmilhao(*errado, *certo, *numperguntas);
		esperateclaparasair();
		system("cls");
		selecaodejogos();	
		exit(0);
	}
	else{
	if(selecao != 50){ //MODELELO PARA PERGUNTA COM RESPOSTA NO 2
		printf("\nVocê digitou a resposta errada!! \n\n");
		printf("RESPOSTA CORRETA : 2-RIO GRANDE DO SUL\n\n\n\n");
		*errado = *errado +1;
		}
		else {
		printf("\nPARABÉNS! Você acertou a pergunta! \n\n\n\n");	
		*certo = *certo +1;
		}
		}
		
	*numperguntas = *numperguntas + 1;	
		
//########################### RESPOSTA NA POSIÇÃO 3 #########################
	printf("		PRÓXIMA PERGUNTA\n");
	printf("Qual era o apelido da cantora Elis Regina? \n");
	printf("1- GAUCHINHA   	      		5- SAIR\n");	
	printf("2- PAULISTINHA \n");
	printf("3- PIMENTINHA \n");
	printf("4- ANDORINHA \n\n");
	selecao = getche();
	
	if(selecao==53){
		system("cls");
		resultadosmilhao(*errado, *certo, *numperguntas);
		esperateclaparasair();
		system("cls");
		selecaodejogos();	
		exit(0);
	}
	else{
	if(selecao != 51){ //MODELELO PARA PERGUNTA COM RESPOSTA NO 3
		printf("\nVocê digitou a resposta errada!! \n\n");
		printf("RESPOSTA CORRETA : 3-PIMENTINHA\n\n\n\n");
		*errado = *errado +1;
		}
		else {
		printf("\nPARABÉNS! Voce acertou a pergunta! \n\n\n\n");	
		*certo = *certo +1;
		}
		}
		
		
	*numperguntas = *numperguntas + 1;	
		
//########################### RESPOSTA NA POSIÇÃO 4 #########################
	printf("		PRÓXIMA PERGUNTA\n");	
	printf("Quem proclamou a república no Brasil em 1889? \n");
	printf("1- DUQUE DE CAXIAS 		5- SAIR\n");	
	printf("2- MARECHAL RONDON \n");
	printf("3- DOM PEDRO II \n");
	printf("4- MARECHAL DEODORO \n\n");
	selecao = getche();
	
	if(selecao==53){
		system("cls");
		resultadosmilhao(*errado, *certo, *numperguntas);
		esperateclaparasair();
		system("cls");
		selecaodejogos();
		exit(0);	
	}
	else{
	if(selecao != 52){ //MODELELO PARA PERGUNTA COM RESPOSTA NO 4
		printf("\nVocê digitou a resposta errada!! \n\n\n");
		printf("RESPOSTA CORRETA : 4- MARECHAL DEODORO\n\n\n\n");
		*errado = *errado +1;
		}
		else {
		printf("\nPARABÉNS! Voce acertou a pergunta! \n\n\n");
		*certo = *certo +1;	
		}
		}

	*numperguntas = *numperguntas + 1;
									
}

void resultadosmilhao(int errado, int certo, int numperguntas) //Mostra os resultados ao jogador
{
	float media;
	char porcento;
	
	media =  (float(certo)/float(numperguntas))*100;
	
	printf("		RESULTADOS\n\n");
	printf("TOTAL DE PERUNTAS RESPONDIDAS : %d\n",numperguntas);
	printf("ACERTOS : %d\n",certo);
	printf("ERROS : %d\n",errado);
	printf("MEDIA DE ACERTOS : %2.f%%",media);
	}

void selecaocacapalavra1(void) //Função para validar as palavras digitadas do jogador da fase 1.
{
	char palavra1[6][30]={"BERGAMOTA","BANANA","GOIABA","MELANCIA","UVA","LARANJA"};
	int retorno[6], i, fimpalavra1=0, incrementocaca=0;
	char resposta[60];
	char acertos[6][60];
		
	mapacacapalavra1();
	
	
	while(fimpalavra1<6){
	system("cls");
	mapacacapalavra1();	
	printf("\nPALAVRAS ENCONTRADAS :\n");
	for(i=0;i<incrementocaca;i++){
	printf("%s\n",acertos[i]);
	}
	
	printf("\n\nDIGITE A PALAVRA: ");
	scanf("%s",&resposta);
	strupr(resposta);
	for(i=0;i<6;i++){
		if(retorno[i]==4){
		}
		else{
		retorno[i] = strcmp(palavra1[i],resposta); // VERIFICA SE O CONTEUDO DA VARIAVEL PALAVRA1 É O MESMO DO CONTEUDO DA RESPOSTA
		}
	}
	for(i=0;i<6;i++){
	if(retorno[i] == 0){
		retorno[i] = 4; // ARMAZENA O NUMERO 4 A TODAS AS PALAVRAS QUE JÁ FORAM ENCONTRADAS AFIM DE NÃO REPETIR UMA PALAVRA
		strcpy(acertos[incrementocaca], resposta); //COPIA O CONTEUDO DA REPOSTA PARA ACERTOS.
		incrementocaca++; // VARIAVEL PARA CONTROLAR AS PALAVRAS QUE SERÃO PRINTADAS NA TELA.
		fimpalavra1++;
	}
	}
	}
	system("cls");
	printf("PARABÉNS, VOCÊ ENCONTROU TODAS AS PALAVRAS!\n\n\n");
	printf("		PROXIMA FASE\n\n");
	
}

void selecaocacapalavra2(void) //Função para validar as palavras digitadas do jogador da fase 2.
{
	char palavra2[5][30]={"WOLVERINE","HOMEM_DE_FERRO","GAMBIT","HULK","CAPITAO_AMERICA"};
	int retorno[5], i, fimpalavra2=0, incrementocaca=0;
	char resposta[60];
	char acertos[5][60];
		
	mapacacapalavra2();
	
	
	while(fimpalavra2<5){
	system("cls");
	mapacacapalavra2();	
	printf("\nPALAVRAS ENCONTRADAS :\n");
	for(i=0;i<incrementocaca;i++){
	printf("%s\n",acertos[i]);
	}
	
	printf("\n\nDIGITE A PALAVRA: ");
	scanf("%s",&resposta);
	strupr(resposta);
	for(i=0;i<5;i++){
		if(retorno[i]==4){
		}
		else{
		retorno[i] = strcmp(palavra2[i],resposta); // VERIFICA SE O CONTEUDO DA VARIAVEL PALAVRA1 É O MESMO DO CONTEUDO DA RESPOSTA
		}
	}
	for(i=0;i<5;i++){
	if(retorno[i] == 0){
		retorno[i] = 4; // ARMAZENA O NUMERO 4 A TODAS AS PALAVRAS QUE JÁ FORAM ENCONTRADAS AFIM DE NÃO REPETIR UMA PALAVRA
		strcpy(acertos[incrementocaca], resposta); //COPIA O CONTEUDO DA REPOSTA PARA ACERTOS.
		incrementocaca++; // VARIAVEL PARA CONTROLAR AS PALAVRAS QUE SERÃO PRINTADAS NA TELA.
		fimpalavra2++;
	}
	}
	}
	system("cls");
	printf("PARABÉNS, VOCÊ ENCONTROU TODAS AS PALAVRAS!\n\n\n");
	printf("		PROXIMA FASE\n\n");
			
}

void selecaocacapalavra3(void) //Função para validar as palavras digitadas do jogador da fase 3.
{
	char palavra3[5][30]={"COPO","TOALHA","FORNO","MICROONDAS","CAFETEIRA"};
	int retorno[5], i, fimpalavra3=0, incrementocaca=0;
	char resposta[60];
	char acertos[5][60];
		
	mapacacapalavra2();
	
	
	while(fimpalavra3<5){
	system("cls");
	mapacacapalavra3();	
	printf("\nPALAVRAS ENCONTRADAS :\n");
	for(i=0;i<incrementocaca;i++){
	printf("%s\n",acertos[i]);
	}
	
	printf("\n\nDIGITE A PALAVRA: ");
	scanf("%s",&resposta);
	strupr(resposta);
	for(i=0;i<5;i++){
		if(retorno[i]==4){
		}
		else{
		retorno[i] = strcmp(palavra3[i],resposta); // VERIFICA SE O CONTEUDO DA VARIAVEL PALAVRA1 É O MESMO DO CONTEUDO DA RESPOSTA
		}
	}
	for(i=0;i<5;i++){
	if(retorno[i] == 0){
		retorno[i] = 4; // ARMAZENA O NUMERO 4 A TODAS AS PALAVRAS QUE JÁ FORAM ENCONTRADAS AFIM DE NÃO REPETIR UMA PALAVRA
		strcpy(acertos[incrementocaca], resposta); //COPIA O CONTEUDO DA REPOSTA PARA ACERTOS.
		incrementocaca++; // VARIAVEL PARA CONTROLAR AS PALAVRAS QUE SERÃO PRINTADAS NA TELA.
		fimpalavra3++;
	}
	}
	}
	system("cls");
	printf("PARABÉNS, VOCÊ ENCONTROU TODAS AS PALAVRAS!\n\n\n");
	printf("	MUITO BEM, VOCÊ CONCLUIU TODAS AS FASES.\n\n");
			
}	

int roletarodaroda(void) //Função para sortear um numero para o usuario	
{
	int i, pontuacaorodaroda;
  
  printf("ROLETA GEROU O VALOR : ");
  
  srand(time(NULL));
  for (i = 0; i < 1; i++)
  {
    /* gerando valores aleatórios entre zero e 10 */
    pontuacaorodaroda = rand() % 10;
    printf("%d ", pontuacaorodaroda);
  }
  
  switch(pontuacaorodaroda){
  	
      case 0:
      	return (pontuacaorodaroda = 0);
  	  break;	
  		
	  case 1:
	  	return (pontuacaorodaroda = 1000);
	  break;
	  
	  case 2:
	  	return (pontuacaorodaroda = 2000);
	  break;
	  
	  case 3:
	  	return (pontuacaorodaroda = 3000);
	  break;
	  
	  case 4:
	  	return (pontuacaorodaroda = 4000);
	  break;
	  
	  case 5:
	  	return (pontuacaorodaroda = 5000);
	  break;
	  
	  case 6:
	  	return (pontuacaorodaroda = 6000);
	  break;
	  
	  case 7:
	  	return (pontuacaorodaroda = 7000);
	  break;
	
	  case 8:
	  	return (pontuacaorodaroda = 8000);	 
	  break;
	  	
  	  case 9:
	  	return (pontuacaorodaroda = 9000);	
	  break;
	  
	  case 10:
	  	return (pontuacaorodaroda = 0);
	  break;
  	
  }
}

void funcaopalavradarodaroda(char palavradarodaroda[ ],char letras[ ], int *numpalavradarodaroda) // Função para sortear uma palavra aleatoria
{
	int i;
  
  srand(time(NULL));
  for (i = 0; i < 1; i++)
  {
    /* gerando valores aleatórios entre zero e 3 */
    *numpalavradarodaroda = rand() % 3;
  }
  
  switch(*numpalavradarodaroda){
  	
	  case 0:
	  strcpy (palavradarodaroda, "A__RT_M__TO");//APARTAMENTO
	  letras[0] = 'P';
	  letras[1] = 'A';
	  letras[2] = 'A';
	  letras[3] = 'E';
	  letras[4] = 'N';
	  break;
	  
	  case 1:
	  strcpy(palavradarodaroda,"_IR__S_L");//GIRASSOL
	  letras[0] = 'G';
	  letras[1] = 'A';
	  letras[2] = 'S';
	  letras[3] = 'O';
	  break;
	  
	  case 2:
	  strcpy(palavradarodaroda,"B___NA");//BANANA
	  letras[0] = 'A';
	  letras[1] = 'N';
	  letras[2] = 'A';
	  break;

  }	
}

void logicajogorodaroda(int pontuacaorodaroda,char palavradarodaroda[ ],char letras[ ],int numpalavradarodaroda) //Função aonde é feita a logica dos jogadores do jogo roda roda
{
	int jogador1=1, fimrodarodapalavra=0, pontuacaojogador1=0 ,pontuacaojogador2=0;
	int passavez=0;
	char repostaletrajogador[60];
	
	switch(numpalavradarodaroda){
	
	case 0:
		do
		{
			if(pontuacaorodaroda==0){
			printf("\n\nJOGADOR %d VOCÊ RECEBEU O PASSA A VEZ NA ROLETA\n\n",jogador1);
			if(jogador1 == 2){
			jogador1--;
			passavez = passavez + 3;
			}else{
			passavez++;	
			}
			passaavez();
			}
			else{
			printf("\n\nJOGADOR %d SE VOCÊ ACERTAR A LETRA NESTA RODADA VOCÊ RECEBERA R$ %d.00 reais.\n\n\n\n",(jogador1),pontuacaorodaroda);
			}
			printf("PALAVRA SORTEADA: %s",palavradarodaroda);
	
	
			if(jogador1==1 && passavez==0)
			{
			printf("\n\nJOGADOR 1: ");
			scanf("%s",&repostaletrajogador);
			printf("\n\n");

				if(repostaletrajogador[0] == 'P' || repostaletrajogador[0] == 'p'){
				palavradarodaroda[1] = letras[0];
				fimrodarodapalavra++;
				pontuacaojogador1 = (pontuacaojogador1 + pontuacaorodaroda);
				}
				else{
					if(repostaletrajogador[0] == 'A' || repostaletrajogador[0] == 'a'){
					palavradarodaroda[2] = letras[1];
					palavradarodaroda[5] = letras[2];
					fimrodarodapalavra++;
					pontuacaojogador1 = (pontuacaojogador1 + pontuacaorodaroda);
					}
					else{
						if(repostaletrajogador[0] == 'E' || repostaletrajogador[0] == 'e'){
						palavradarodaroda[7] = letras[3];
						fimrodarodapalavra++;
						pontuacaojogador1 = (pontuacaojogador1 + pontuacaorodaroda);
						}
						else{
							if(repostaletrajogador[0] == 'N' || repostaletrajogador[0] == 'n'){
							palavradarodaroda[8] = letras[4];
							fimrodarodapalavra++;
							pontuacaojogador1 = (pontuacaojogador1 + pontuacaorodaroda);
							}
							}
						}
					}
		jogador1++;
		passavez++;	
		}
		else{
			if(jogador1==1 && passavez == 1){
				jogador1++;
				passavez++;
			}
			}
			if(jogador1==2 && passavez==0){	
			printf("\n\nJOGADOR 2: ");
			scanf("%s",&repostaletrajogador);
			printf("\n\n");

			if(repostaletrajogador[0] == 'P' || repostaletrajogador[0] == 'p'){
			palavradarodaroda[1] = letras[0];
			fimrodarodapalavra++;
			pontuacaojogador2 = (pontuacaojogador2 + pontuacaorodaroda);	
			}
			else{
				if(repostaletrajogador[0] == 'A' || repostaletrajogador[0] == 'a'){
				palavradarodaroda[2] = letras[1];
				palavradarodaroda[5] = letras[2];
				fimrodarodapalavra++;
				pontuacaojogador2 = (pontuacaojogador2 + pontuacaorodaroda);	
				}
				else{
					if(repostaletrajogador[0] == 'E' || repostaletrajogador[0] == 'e'){
					palavradarodaroda[7] = letras[3];
					fimrodarodapalavra++;
					pontuacaojogador2 = (pontuacaojogador2 + pontuacaorodaroda);
					}
					else{
						if(repostaletrajogador[0] == 'N' || repostaletrajogador[0] == 'n'){
						palavradarodaroda[8] = letras[4];
						fimrodarodapalavra++;
						pontuacaojogador2 = (pontuacaojogador2 + pontuacaorodaroda);
						}
						}
					}
				}
		jogador1--;	
		}
		passavez=0;
		system("cls");
		pontuacaorodaroda = roletarodaroda();
		}while(fimrodarodapalavra<4);
		system("cls");
		break;	
			
	case 1:
		do
		{
			if(pontuacaorodaroda==0){
			printf("\n\nJOGADOR %d VOCÊ RECEBEU O PASSA A VEZ NA ROLETA\n\n",jogador1);
			if(jogador1 == 2){
			jogador1--;
			passavez = passavez + 3;
			}else{
			passavez++;
			}
			passaavez();
			}
			else{
				printf("\n\nJOGADOR %d SE VOCÊ ACERTAR A LETRA NESTA RODADA VOCÊ RECEBERA R$ %d.00 reais.\n\n\n\n",(jogador1),pontuacaorodaroda);
				}	
			printf("PALAVRA SORTEADA: %s",palavradarodaroda);
		
		
			if(jogador1==1 && passavez==0){
			printf("\n\nJOGADOR 1: ");
			scanf("%s",&repostaletrajogador);
			printf("\n\n");
	
			if(repostaletrajogador[0] == 'G' || repostaletrajogador[0] == 'g'){
			palavradarodaroda[0] = letras[0];
			fimrodarodapalavra++;
			pontuacaojogador1 = (pontuacaojogador1 + pontuacaorodaroda);	
			}
			else{
				if(repostaletrajogador[0] == 'A' || repostaletrajogador[0] == 'a'){
				palavradarodaroda[3] = letras[1];
				fimrodarodapalavra++;
				pontuacaojogador1 = (pontuacaojogador1 + pontuacaorodaroda);	
				}
				else{
					if(repostaletrajogador[0] == 'S' || repostaletrajogador[0] == 's'){
					palavradarodaroda[4] = letras[2];
					fimrodarodapalavra++;
					pontuacaojogador1 = (pontuacaojogador1 + pontuacaorodaroda);	
					}
					else{
						if(repostaletrajogador[0] == 'O' || repostaletrajogador[0] == 'o'){
							palavradarodaroda[6] = letras[3];
							fimrodarodapalavra++;
							pontuacaojogador1 = (pontuacaojogador1 + pontuacaorodaroda);	
							}
						}
					}
				}
		jogador1++;
		passavez++;			
		}
		else{
			if(jogador1==1 && passavez == 1){
			jogador1++;
			passavez++;
			}
			}
		if(jogador1==2 && passavez==0)
		{	
		printf("\n\nJOGADOR 2: ");
		scanf("%s",&repostaletrajogador);
		printf("\n\n");

		if(repostaletrajogador[0] == 'G' || repostaletrajogador[0] == 'g'){
		palavradarodaroda[0] = letras[0];
		fimrodarodapalavra++;
		pontuacaojogador2 = (pontuacaojogador2 + pontuacaorodaroda);	
		}
		else{
			if(repostaletrajogador[0] == 'A' || repostaletrajogador[0] == 'a'){
			palavradarodaroda[3] = letras[1];
			fimrodarodapalavra++;
			pontuacaojogador2 = (pontuacaojogador2 + pontuacaorodaroda);
			}
			else{
				if(repostaletrajogador[0] == 'S' || repostaletrajogador[0] == 's'){
				palavradarodaroda[4] = letras[2];
				fimrodarodapalavra++;
				pontuacaojogador2 = (pontuacaojogador2 + pontuacaorodaroda);
				}
				else{
					if(repostaletrajogador[0] == 'O' || repostaletrajogador[0] == 'o'){
						palavradarodaroda[6] = letras[3];
						fimrodarodapalavra++;
						pontuacaojogador2 = (pontuacaojogador2 + pontuacaorodaroda);
					}
				}
			}
		}
		jogador1--;	
		}		
		passavez=0;
		system("cls");
		pontuacaorodaroda = roletarodaroda();
		}while(fimrodarodapalavra<4);
		system("cls");
		break;
		
	case 2:
		do
		{
		if(pontuacaorodaroda==0){
		printf("\n\nJOGADOR %d VOCÊ RECEBEU O PASSA A VEZ NA ROLETA\n\n",jogador1);
		if(jogador1 == 2){
		jogador1--;
		passavez = passavez + 3;
		}else{
		passavez++;
		}
		passaavez();
		}
		else{
		printf("\n\nJOGADOR %d SE VOCÊ ACERTAR A LETRA NESTA RODADA VOCÊ RECEBERA R$ %d.00 reais.\n\n\n\n",(jogador1),pontuacaorodaroda);
		}
		printf("\nPALAVRA SORTEADA: %s",palavradarodaroda);
	
	
		if(jogador1==1 && passavez==0)
		{
		printf("\n\nJOGADOR 1: ");
		scanf("%s",&repostaletrajogador);
		printf("\n\n");

		if(repostaletrajogador[0] == 'A' || repostaletrajogador[0] == 'a'){
		palavradarodaroda[1] = letras[0];
		palavradarodaroda[3] = letras[2];
		fimrodarodapalavra++;
		pontuacaojogador1 = (pontuacaojogador1 + pontuacaorodaroda);		
		}
		else{
			if(repostaletrajogador[0] == 'N' || repostaletrajogador[0] == 'n'){
			palavradarodaroda[2] = letras[1];
			fimrodarodapalavra++;
			pontuacaojogador1 = (pontuacaojogador1 + pontuacaorodaroda);	
			}		
		}
		jogador1++;	
		passavez++;	
		}
		else{
			if(jogador1==1 && passavez == 1){
			jogador1++;
			passavez++;
			}
			}
		if(jogador1==2 && passavez==0)
		{	
		printf("\n\nJOGADOR 2: ");
		scanf("%s",&repostaletrajogador);
		printf("\n\n");

		if(repostaletrajogador[0] == 'A' || repostaletrajogador[0] == 'a'){
		palavradarodaroda[1] = letras[0];
		palavradarodaroda[3] = letras[2];
		fimrodarodapalavra++;
		pontuacaojogador2 = (pontuacaojogador2 + pontuacaorodaroda);		
		}
		else{
			if(repostaletrajogador[0] == 'N' || repostaletrajogador[0] == 'n'){
			palavradarodaroda[2] = letras[1];
			fimrodarodapalavra++;
			pontuacaojogador2 = (pontuacaojogador2 + pontuacaorodaroda);
			}
			}
		jogador1--;
		}
		passavez=0;
		system("cls");
		pontuacaorodaroda = roletarodaroda();
		}while(fimrodarodapalavra<2);
		system("cls");
		break;
	}
	printf("PALAVRA : %s",palavradarodaroda);
	printf("\nJOGADOR 1 GANHOU %d.00 REAIS\n",pontuacaojogador1);
	printf("JOGADOR 2 GANHOU %d.00 REAIS",pontuacaojogador2);		
}

int AdicionaPontos(int pontos[], int *velocidade)//chama esta função todo movimento do usuario para verificar se o usuario chegou ao ponto
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        if (pontos[i] == 0)
        {
            pontos[i] = 1;
        }
        if (pontos[i] == 2)
        {
            pontos[i] = 3;
        }
        if (pontos[i] == 3)
        {
            *velocidade = *velocidade - 100;
            pontos[i] = 5;
            pontos[i + 1] = 1;
        }
    }
    if (pontos[4] == 5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int verificacolisao(int contr_y, int contr_x) // esta função e chamada toda vez que o usuario fazer um movimento para verificar se ele encostou na parede.
{
    if (contr_y >= 4)
    {
        return 1;
    }
    else if (contr_y <= -5)
    {
        return 1;
    }
    else if (contr_x >= 9)
    {
        return 1;
    }
    else if (contr_x <= -10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void MovimenParedeDireitaEmX(int posx, int *controle_x)
{
    switch (posx)
    { //entra nesse switch case para verificar em que casa a bolinha esta e dependendo da casa tenho uma distancia diferente que devo printar a parede
        // utiliza a posx que Ã© a localizacao no eixo x da bolinha/jogador
    case -9:
        printf("                 %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case -8:
        printf("                %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case -7:
        printf("               %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case -6:
        printf("              %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case -5:
        printf("             %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case -4:
        printf("            %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case -3:
        printf("           %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case -2:
        printf("          %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case -1:
        printf("         %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case 1:
        printf("       %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case 2:
        printf("      %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case 3:
        printf("     %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case 4:
        printf("    %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case 5:
        printf("   %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case 6:
        printf("  %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case 7:
        printf(" %c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;

    case 8:
        printf("%c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        break;
    }
}

void MovimenParedeDireitaEmX_Pontos(int posx, int *controle_x, int pontos[], int p)
{
    switch (posx)
    { //entra nesse switch case para verificar em que casa a bolinha esta e dependendo da casa tenho uma distancia diferente que devo printar a parede e o ponto
        // utiliza a posx que Ã© a localizacao no eixo x da bolinha/jogador
    case -9:
        printf("                %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case -8:
        printf("               %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case -7:
        printf("              %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case -6:
        printf("             %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case -5:
        printf("            %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case -4:
        printf("           %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case -3:
        printf("          %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case -2:
        printf("         %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case -1:
        printf("        %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case 1:
        printf("      %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case 2:
        printf("     %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case 3:
        printf("    %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case 4:
        printf("   %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case 5:
        printf("  %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case 6:
        printf(" %c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case 7:
        printf("%c%c", 254, 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 0;
        break;

    case 8:
        printf("%c", 35);
        printf("\n");
        *controle_x = *controle_x - 1;
        pontos[p] = 2;
        break;
    }
}

void ControleEixoXJogador(int posx, int *controle_x)
{
    switch (posx)
    { //switch utilizado para printar o local aonde a bolinha/jogador se moveu, dependendo aonde a bolinha esta ou se movimentou ele printa com o distancimento correto

    case -9:
        printf("%c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -8:
        printf(" %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -7:
        printf("  %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -6:
        printf("   %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -5:
        printf("    %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -4:
        printf("     %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -3:
        printf("      %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -2:
        printf("       %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -1:
        printf("        %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 1:
        printf("          %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 2:
        printf("           %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 3:
        printf("            %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 4:
        printf("             %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 5:
        printf("              %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 6:
        printf("               %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 7:
        printf("                %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 8:
        printf("                 %c", 111);
        *controle_x = *controle_x + 1;
        break;
    }
}

void ControleEixoXJogadorPontosEsquerda(int posx, int *controle_x, int pontos[])
{
    switch (posx)
    { //switch utilizado para printar o local aonde a bolinha/jogador se moveu, dependendo aonde a bolinha esta ou se movimentou ele printa com o distancimento correto e verificando se esta em cima do ponto

    case -9:
        printf("", 111);
        *controle_x = *controle_x + 1;
        if (pontos[3] == 1 || pontos[3] == 0)
        {
            pontos[3] = 2;
        }
        else if (pontos[4] == 1 || pontos[4] == 0)
        {
            pontos[4] = 2;
        }
        break;

    case -8:
        printf("%c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -7:
        printf(" %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -6:
        printf("  %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -5:
        printf("   %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -4:
        printf("    %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -3:
        printf("     %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -2:
        printf("      %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case -1:
        printf("       %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 1:
        printf("         %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 2:
        printf("          %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 3:
        printf("           %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 4:
        printf("            %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 5:
        printf("             %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 6:
        printf("              %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 7:
        printf("               %c", 111);
        *controle_x = *controle_x + 1;
        break;

    case 8:
        printf("                %c", 111);
        *controle_x = *controle_x + 1;
        break;
    }
}
void ControleEixoYJogador(int posx, int *controle_y)
{
    switch (posx)
    { //switch utilizado para printar o local aonde a bolinha/jogador se moveu, dependendo aonde a bolinha esta ou se movimentou ele printa com o distancimento correto neste caso do eixo y eu ainda utilizo a variavel do eixo x (posx) por que o movimento da bolinha se ela foi mais para cima ou mais para baixo ja foi feito no primerio if (  if(j==(10+posx) && i==(5+posy))  ) aqui eu so utilizo o o posx para printar ele um acima mas na posicao x em que ele se encontrava por ultimo

    case -4:
        printf("     %c", 111);
        *controle_y = *controle_y + 1;
        break;

    case -3:
        printf("      %c", 111);
        *controle_y = *controle_y + 1;
        break;

    case -2:
        printf("       %c", 111);
        *controle_y = *controle_y + 1;
        break;

    case -1:
        printf("        %c", 111);
        *controle_y = *controle_y + 1;
        break;

    case 0:
        printf("         %c", 111);
        *controle_y = *controle_y + 1;
        break;

    case 1:
        printf("          %c", 111);
        *controle_y = *controle_y + 1;
        break;

    case 2:
        printf("           %c", 111);
        *controle_y = *controle_y + 1;
        break;

    case 3:
        printf("            %c", 111);
        *controle_y = *controle_y + 1;
        break;
    }
}

void instrucaomovimentacaojogador(void)
{
    system("cls");
    printf("COMANDOS DO JOGO");
    printf("\n\nTECLA 'W' - MOVIMENTA PARA CIMA\n");
    printf("TECLA 'S' - MOVIMENTA PARA BAIXO\n");
    printf("TECLA 'A' - MOVIMENTA PARA ESQUERDA\n");
    printf("TECLA 'D' - MOVIMENTA PARA DIREITA\n");
    printf("\n");
}

void imprimemap(int matrizmap[10][10], int posy, int posx, int pontos[])
{
    int i, j, controle_x = 0, controle_y = 0;
    int linhas = 20, colunas = 20;

    printf("\n");

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            //Linhas Superiores
            if (j < 20 && i == 0)
            { //if para printar toda parte superior atravez do controle pelo i=0 o J ira incrementando e ira printando (tudo no comeÃ§o do script)
                printf("%c", 35);
                if (j == 19)
                {
                    printf("\n");
                }
                //Linhas Laterais da Esquerda
            }
            else if ((j == 0 && i < 10))
            { // if para printar as linhas esquerdas esse if entrara toda vez que o meu segundo for completar assim sabendo que a parede esquerda ja foi colocada, assim podendo colocar a direita de baixo (este if entra apos o if da parede esquerda entrar)
                if (j == 0 && i == 2 && pontos[3] == 1)
                {	//if para testar se os pontos 3 esta disponviel para pegar
                    printf("%c%c", 35, 254);
                    pontos[3] = 0;
                    if ((posx != -9) && (posy != -3))
                    {
                        j = j + 1;
                    }
                }
                else if (j == 0 && i == 6 && pontos[4] == 1)
                {	//if para testar se os pontos 4 esta disponviel para pegar
                    printf("%c%c", 35, 254);
                    pontos[4] = 0;
                    if ((posx != -9) && (posy != 1))
                    {
                        j = j + 1;
                    }
                }
                else
                {
                    printf("%c", 35);
                }
                //Linhas Laterais da Direita
            }
            else if (j == 19 && i < 9)
            { // if para printar as linhas direitas este if vai acontecendo quando tenho o j==19 no caso a ultima repeticao do segundo for vai entrar depois do if da direita
                if (pontos[0] == 0 || pontos[0] == 2 || pontos[1] == 0 || pontos[1] == 2 || (pontos[1] == 1 && i != 7) || pontos[2] == 0 || pontos[2] == 2 || (pontos[2] == 1 && i != 4) || pontos[2] == 5) 
                {												//if para testar se o ponto 0 1 e 2 já foram pegados 
                    if ((pontos[3] == 0 && i == 2) || (pontos[4] == 0 && i == 6))
                    {
                        if ((controle_x == 0) && (controle_y == 0))
                        {                                      //entra no if quando a bolinha/jogador nÃ£o esta nesta posicao
                            printf("                 %c", 35); // espaÃ§amento sem a bolinha/jogador
                            printf("\n");
                        }
                        else if (controle_y == 1)
                        {                            //entra neste if quando tenho uma movimentacao da bolinha/jogador no eixo y
                            printf("       %c", 35); //distancia da bolinha/jogador ate o local aonde a parede deve estar
                            printf("\n");
                            controle_y--; //variavel para controle do eixo y esta variavel Ã© incrementada no if do jogador. a variavel funciona da seguinte forma sabendo aonde a bolinha esta eu incremento a variavel para assim eu entrar nesse if e fazer o espacamento correto da parede
                        }
                        else if (controle_x == 1)
                        { // entra nesse if quando tenho uma movimentacao no eixo x
                            MovimenParedeDireitaEmX(posx, &controle_x);
                        }
                    }
                    else
                    {
                        if ((controle_x == 0) && (controle_y == 0))
                        {                                       //entra no if quando a bolinha/jogador nÃ£o esta nesta posicao
                            printf("                  %c", 35); // espaÃ§amento sem a bolinha/jogador
                            printf("\n");
                        }
                        else if (controle_y == 1)
                        {                             //entra neste if quando tenho uma movimentacao da bolinha/jogador no eixo y
                            printf("        %c", 35); //distancia da bolinha/jogador ate o local aonde a parede deve estar
                            printf("\n");
                            controle_y--; //variavel para controle do eixo y esta variavel Ã© incrementada no if do jogador. a variavel funciona da seguinte forma sabendo aonde a bolinha esta eu incremento a variavel para assim eu entrar nesse if e fazer o espacamento correto da parede
                        }
                        else if (controle_x == 1)
                        { // entra nesse if quando tenho uma movimentacao no eixo x
                            MovimenParedeDireitaEmX(posx, &controle_x);
                        }
                    }
                }
                else if (pontos[0] == 1)
                {
                    if ((controle_x == 0) && (controle_y == 0))
                    {                                             //entra no if quando a bolinha/jogador nÃ£o esta nesta posicao
                        printf("                 %c%c", 254, 35); // espaÃ§amento sem a bolinha/jogador e o ponto
                        printf("\n");
                        pontos[0] = 0;
                    }
                    else if (controle_y == 1)
                    {                                   //entra neste if quando tenho uma movimentacao da bolinha/jogador no eixo y
                        printf("       %c%c", 254, 35); //distancia da bolinha/jogador e do ponto ate o local aonde a parede deve estar
                        printf("\n");
                        controle_y--; //variavel para controle do eixo y esta variavel Ã© incrementada no if do jogador. a variavel funciona da seguinte forma sabendo aonde a bolinha esta eu incremento a variavel para assim eu entrar nesse if e fazer o espacamento correto da parede
                        pontos[0] = 0;
                    }
                    else if (controle_x == 1)
                    {                                                                 // entra nesse if quando tenho uma movimentacao no eixo x
                        MovimenParedeDireitaEmX_Pontos(posx, &controle_x, pontos, 0); // imprime a posicao da parede com a bolinha
                    }
                }
                else if (pontos[1] == 1 && i == 7)
                {
                    if ((controle_x == 0) && (controle_y == 0))
                    {                                             //entra no if quando a bolinha/jogador nÃ£o esta nesta posicao
                        printf("                 %c%c", 254, 35); // espaÃ§amento sem a bolinha/jogador e o ponto
                        printf("\n");
                        pontos[1] = 0;
                    }
                    else if (controle_y == 1)
                    {                                   //entra neste if quando tenho uma movimentacao da bolinha/jogador no eixo y
                        printf("       %c%c", 254, 35); //distancia da bolinha/jogador e do ponto ate o local aonde a parede deve estar
                        printf("\n");
                        controle_y--; //variavel para controle do eixo y esta variavel Ã© incrementada no if do jogador. a variavel funciona da seguinte forma sabendo aonde a bolinha esta eu incremento a variavel para assim eu entrar nesse if e fazer o espacamento correto da parede
                        pontos[1] = 0;
                    }
                    else if (controle_x == 1)
                    { // entra nesse if quando tenho uma movimentacao no eixo x
                        MovimenParedeDireitaEmX_Pontos(posx, &controle_x, pontos, 1);
                    }
                }
                else if (pontos[2] == 1 && i == 4)
                {
                    if ((controle_x == 0) && (controle_y == 0))
                    {                                             //entra no if quando a bolinha/jogador nÃ£o esta nesta posicao
                        printf("                 %c%c", 254, 35); // espaÃ§amento sem a bolinha/jogador e o ponto
                        printf("\n");
                        pontos[2] = 0;
                    }
                    else if (controle_y == 1)
                    {                                   //entra neste if quando tenho uma movimentacao da bolinha/jogador no eixo y
                        printf("       %c%c", 254, 35); //distancia da bolinha/jogador e do ponto ate o local aonde a parede deve estar
                        printf("\n");
                        controle_y--; //variavel para controle do eixo y esta variavel Ã© incrementada no if do jogador. a variavel funciona da seguinte forma sabendo aonde a bolinha esta eu incremento a variavel para assim eu entrar nesse if e fazer o espacamento correto da parede
                        pontos[2] = 0;
                    }
                    else if (controle_x == 1)
                    { // entra nesse if quando tenho uma movimentacao no eixo x
                        MovimenParedeDireitaEmX_Pontos(posx, &controle_x, pontos, 2);
                    }
                }

                //Jogador
            }
            else if (j == (10 + posx) && i == (5 + posy))
            { //if com controle das posicoes posx e posy que sao incrementadas no main apos eu saber qual tecla o usuario digitou
                if ((pontos[3] == 0 && i == 2) || (pontos[4] == 0 && i == 6))
                {
                    if ((posx == 0) && (posy == 0))
                    { //if da posicao inicial da bolinha/jogador
                        printf("          %c", 111);
                        controle_y++;
                        //Controle Eixo X
                    }
                    else if (posx != 0)
                    { // if para testa se ocorreu um movimento de posicao da bolinha no eixo x
                        ControleEixoXJogadorPontosEsquerda(posx, &controle_x, pontos);
                        //Controle Eixo Y
                    }
                    else if (posy != 0)
                    { // if para testa se ocorreu um movimento de posicao da bolinha no eixo y
                        ControleEixoYJogador(posx, &controle_y);
                    }
                }
                else
                {
                    if ((posx == 0) && (posy == 0))
                    { //if da posicao inicial da bolinha/jogador
                        printf("         %c", 111);
                        controle_y++;
                        //Controle Eixo X
                    }
                    else if (posx != 0)
                    { // if para testa se ocorreu um movimento de posicao da bolinha no eixo x
                        ControleEixoXJogador(posx, &controle_x);
                        //Controle Eixo Y
                    }
                    else if (posy != 0)
                    { // if para testa se ocorreu um movimento de posicao da bolinha no eixo y
                        ControleEixoYJogador(posx, &controle_y);
                    }
                }
                //Linhas Inferiores
            }
            else if (i == 9 && j <= 19)
            { // imprime toda parte inferior no final da chama da funcao
                printf("%c", 35);
                if (j == 19)
                {
                    printf("\n");
                }
            }
        }
    }
}

void JogoRunBall(FILE *ARQ,JOGADORES jog,int idaderunball,char nomerunball[ ]){
	char ESQ = 27;
    char tecla = 0;
    int posi = 0, pontos[9] = {0, 6, 6, 6, 6};
    int contr_y = 0, contr_x = 0, ResultadoColisao = 0, ResultadoTodosOsPontos = 0, Velocidade = 500;
    int matrizmap[10][10];
	
	do{
    instrucaomovimentacaojogador();
    printf("PRESSIONE A TECLA 'A' PARA COMECAR");
    tecla = getch();
    if((tecla != 65) && (tecla != 97)){
    	printf("\n\nTECLA INCORRETA.\n");
    	system("pause");
	}
	}while((tecla != 65) && (tecla != 97));
	
    if ((tecla == 65) || (tecla == 97))
    {
        instrucaomovimentacaojogador();
        imprimemap(matrizmap, contr_y, contr_x, pontos);
        printf("Faca seu primeiro movimento");
        tecla = getch();

        do
        {
            Sleep(Velocidade);
            if (kbhit()) //verifica se o usuario digitou alguma tecla
            {
                tecla = getch();
                system("cls");
                instrucaomovimentacaojogador();
                if (tecla == 119)
                {
                    contr_y--;
                    imprimemap(matrizmap, contr_y, contr_x, pontos);
                }
                else if (tecla == 115)
                {
                    contr_y++;
                    imprimemap(matrizmap, contr_y, contr_x, pontos);
                }
                else if (tecla == 97)
                {
                    contr_x--;
                    imprimemap(matrizmap, contr_y, contr_x, pontos);
                }
                else if (tecla == 100)
                {
                    contr_x++;
                    imprimemap(matrizmap, contr_y, contr_x, pontos);
                }
            }
            else //caso ele não tenha digitado a ultima tecla que ele digitou sera utilizada para contiuar o programa
            {
                system("cls");
                instrucaomovimentacaojogador();
                if (tecla == 119)
                {
                    contr_y--;
                    imprimemap(matrizmap, contr_y, contr_x, pontos);
                }
                else if (tecla == 115)
                {
                    contr_y++;
                    imprimemap(matrizmap, contr_y, contr_x, pontos);
                }
                else if (tecla == 97)
                {
                    contr_x--;
                    imprimemap(matrizmap, contr_y, contr_x, pontos);
                }
                else if (tecla == 100)
                {
                    contr_x++;
                    imprimemap(matrizmap, contr_y, contr_x, pontos);
                }
            }

            ResultadoColisao = verificacolisao(contr_y, contr_x);
            ResultadoTodosOsPontos = AdicionaPontos(pontos, &Velocidade); //pontos eh um vetor passagem por referencia
        } while (tecla != ESQ && ResultadoColisao == 0 && ResultadoTodosOsPontos == 0);

        if (ResultadoColisao == 1)
        {
            printf("VOCE PERDEU\n");
			ARQ=fopen("relatoriorunball.bin","ab");
			strcpy(jog.nome, nomerunball);
			jog.idade = idaderunball;
			jog.pontos = 0;
			fwrite(&jog,sizeof(JOGADORES),1,ARQ); //imprime no relatorio o nome idade e o pontos=0
			fclose(ARQ);
			system("pause");
			system("cls"); 
        }
        else if (ResultadoTodosOsPontos == 1)
        {  
        	printf("VOCE GANHOU\n");
			ARQ=fopen("relatoriorunball.bin","ab");
			strcpy(jog.nome, nomerunball);
			jog.idade = idaderunball;
			jog.pontos = 500;
			fwrite(&jog,sizeof(JOGADORES),1,ARQ); //imprime no relatorio o nome idade e o pontos=500
			fclose(ARQ);
			system("pause");
			system("cls"); 
        }
    }
}
int cadastrojogadorrunball(FILE *ARQ,JOGADORES jog,int *idade,char nome[ ]){
	int teste=0;
	int comparastring;
	char nometeste[20];
	ARQ=fopen("relatoriorunball.bin","rb");
	system("cls"); 
	printf("Digite o seu nome: ");
	fflush(stdin);
	gets(nome);
	
	fread(&jog,sizeof(JOGADORES),1,ARQ);
	while (!feof(ARQ))
	{
		comparastring = strncmp(nome,jog.nome,sizeof(nome));
		if(comparastring==0){
			printf("\n\nNome ja cadastrado.\n\nVoltando para o menu...\n\n");
			system("pause");
			fclose(ARQ);
			system("cls");
			//opcaojogorunball();
			return(1);
		}
	  fread(&jog,sizeof(JOGADORES),1,ARQ);
	}
		
	printf("Digite sua idade: ");
	scanf("%d",&*idade);
	fclose(ARQ);
	return(0);
}

void relatoriojogadoresrunball(FILE *ARQ,JOGADORES jog){
	system("cls");
	printf("\n==============Relatorio dos Jogadores==============\n");
	ARQ=fopen("relatoriorunball.bin","rb");
	if (ARQ == NULL){  
		printf ("\nNenhum jogador registrado ate entao.\n");
		system("pause");
  	}else{
  		printf("%20s  | %3s  |  %s","NOME","IDADE","PONTOS");
  		printf("\n____________________________________________________\n");	
  		fread(&jog,sizeof(JOGADORES),1,ARQ);
  		while (!feof(ARQ))
		{
		  printf("%20s  | %3d  |  %d\n",jog.nome,jog.idade,jog.pontos);
		  fread(&jog,sizeof(JOGADORES),1,ARQ);
		}
		printf("\n____________________________________________________\n");
 		printf("\n\n\n");
 		system("pause");
 		fclose(ARQ); 
	}
}

void criaarquivobinario(FILE *ARQ,JOGADORES jog){
	ARQ =fopen("relatoriorunball.bin","ab");
	fclose(ARQ);
}
void opcaojogorunball(void){
	int num,idaderunball,JogadorCadastrado=0;
	char nomerunball[20];
	FILE *ARQ;
	JOGADORES jog;
	setlocale( LC_ALL, "C" );
	do{
		printf("1- Iniciar o Jogo.\n");
		printf("2- Intrucao do Jogo\n");
		printf("3- Placar dos Jogadores (RELATORIO)\n");
		printf("4- Sair");
		fflush(stdin);
		num = getche();
		
		switch(num){
			case 49:
				criaarquivobinario(ARQ,jog);
				JogadorCadastrado = cadastrojogadorrunball(ARQ,jog,&idaderunball,nomerunball);
				if(JogadorCadastrado==1){
					opcaojogorunball();
				}else{
					JogoRunBall(ARQ,jog,idaderunball,nomerunball);	
				}
			break;
			
			case 50:
				system("cls");
				setlocale(LC_ALL,"");
				intrucaojogorunball();
				esperateclaparavoltar();
				system("cls");
				opcaojogorunball();
			break;
	
			case 51:
				relatoriojogadoresrunball(ARQ,jog);
			break;
			
			case 52:
				printf("\n\nSaindo do Jogo...");
			break;	
		}
		system("cls");
	}while((num != 49) && (num != 50) && (num != 51) && (num != 52));	
}
