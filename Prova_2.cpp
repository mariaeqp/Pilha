/* Desenvolvido por @mariaeqp - ESTRUTURA DE DADOS I

Você resolveu implementar um jogo de baralho virtual para jogar com seus amigos. 
Neste caso, cada carta possui a informação do seu naipe (Ouros, Espadas, Copas e Paus) 
armazenada em um vetor de caracteres e um inteiro para representar o número de cada carta de 1(Ás) até 10. 
O jogo consiste em descartar cartas indesejadas em dois possíveis decks (duas pilhas), 
logo deve-se adicionar cartas no topo de um destes decks (empilhar) 
e também retirar as cartas de seu interesse do topo de um dos decks (desempilhar).
Assim, um bom jogador deve saber quantas cartas estão empilhadas sobre as cartas de seu interesse em um determinado deck. 
Com base nestas informações, desenvolva o código abaixo para viabilizar a implementação do jogo.
a. Struct que representa as cartas e struct representa o deck.
b. Função empilhar que recebe a carta e o número do deck que o jogador deseja adicionar a carta. void empilhar(struct *carta, struct* deck)
c. Função desempilhar que recebe o número do deck do qual o jogador deseja retirar a carta e retorna a carta do topo. 
struct *carta desempilhar(struct* deck)
d. Implementar uma função de busca por carta, que deve retornar a quantidade de cartas acima dela no deck. int busca(struct *carta, struct* deck)
Deck 1*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carta{
	int num;
	char naipe[10];
	struct carta *prox;
} Carta;

typedef struct{
	Carta *topo;
	int tamanho;
} Deck;

void empilhar(Carta *carta, Deck *pilha){
	carta->prox = pilha->topo;
	pilha->topo = carta;
	pilha->tamanho++;
}

Carta * desempilhar(Deck *pilha){

	if(pilha->topo == NULL){

		printf("Pilha vazia..\n");
		
		return NULL;
	}

	Carta *retirada = pilha->topo;
	pilha->topo = pilha->topo->prox;
	retirada->prox = NULL;
	pilha->tamanho--;
	
	return (retirada);
}

int busca(Carta *carta, Deck* deck){
	int qtd = 1;
	
	Carta *aux = deck->topo;
	
	while(aux != NULL){
		
		if((aux->num == carta->num) && (strcmp(aux->naipe, carta->naipe) == 0)){
		
			printf("Carta na posicao: %d \n",qtd);
			return qtd;
		}
		
		qtd++;
		aux = aux->prox;
	}
	
	printf("Carta nao encontrada..\n");
	return 0;
}

Carta *criarCarta(){

	Carta *nova = (Carta*) malloc(sizeof(Carta));
	nova->prox = NULL;
	
	printf("Digite o naipe: ");
	scanf(" %[^\n]", nova->naipe);
	
	printf("Digite o valor: ");
	scanf("%d", &nova->num);
	
	return nova;
}

Deck *criarDeck(){
	
	Deck *deck = (Deck*) malloc(sizeof(Deck));
	deck->topo = NULL;
	deck->tamanho = 0;
	
	return deck;
}

int main(int argc, char **argv){
	
	Deck *deck1 = criarDeck();
	Deck *deck2 = criarDeck();
	
	int opt = 0;
	
	do{
		Carta * aux = NULL;
		int aux1 = 0;
		printf("\n\t.................................\t\n");
		printf("\t\t\tMENU\t\t\t\n");
		printf("\t1-Adicionar carta deck1\t\t\t\n");
		printf("\t2-Adicionar carta deck2\t\t\t\n");
		printf("\t3-Retirar carta deck1\t\t\t\n");
		printf("\t4-Retirar carta deck2\t\t\t\n");
		printf("\t5-Buscar carta deck1\t\t\t\n");
		printf("\t6-Buscar carta deck2\t\t\t\n");
		printf("\t0-Sair\t\t\t\t\t\n");
		printf("\t.................................\n");
		
		printf("Digite uma opcao: ");
		scanf("%d", &opt);
		
		printf("\n");
		
		switch (opt){
		
		case 1:
			empilhar(criarCarta(), deck1);
			break;
		case 2:
			empilhar(criarCarta(), deck2);
			break;
		case 3:
			 aux = desempilhar(deck1);
			break;
		case 4:
			 aux = desempilhar(deck2);
			break;
		case 5:
			 aux1 = busca(criarCarta(), deck1);
			break;
		case 6:
			 aux1 = busca(criarCarta(), deck2);
			break;
		case 0:
			break;
		default:
			printf("Opcao invalida\n");
			break;
		}
		printf("\nAperte enter para continuar\n");
		getchar();
	}
	while (opt != 0);

	return 0;
}
