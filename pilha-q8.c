#include <stdio.h>

#include <stdlib.h>

#define TAMANHO_PILHA 20

typedef struct{

        int vetor[TAMANHO_PILHA]; //tamanho da pilha

        int topo;

}Pilha;


//prototipo da função empilha

void empilha(int valor,Pilha *P1){

        //pilha->topo significa: ponteiro "pilha" apontando para CONTEÚDO de um item de uma struct

        if(P1->topo < TAMANHO_PILHA){ //verificando se a pilha não está cheia

        //daí pode empilhar

        P1->vetor[P1->topo]=valor;

        P1->topo++;

        printf("O valor %d foi adicionado \n",valor);

        }else{

                printf("Nao ha mais espaco na pilha, \n");

        }

}

void desempilha(Pilha *P1){

        if(P1->topo > 0){

                P1->topo--; //desempilha

                printf("Elemento retirado: %d. \n",P1->vetor[P1->topo]);

        }else{

                printf("A pilha está vazia. \n"); //pilha vazia

        }

}

void imprimePilha(Pilha *P){

        int i;

        printf("\nSegue Impressao da Pilha: \n");

        for(i=((P->topo)-1);i>=0;i--){ //valor inicial de i é a ultima posição da pilha e daí decrementa

                printf("\t %d \n",P->vetor[i]);

        }

}

void inverte_pilha(Pilha *p1, Pilha *p2){

        // p2 é a pilha auxiliar que vai conter a pilha 1 invertida
        // o loop começa no topo e adiciona o elemento do topo à pilha nova (p2)
        for(int i = p1->topo - 1; i>= 0; i--){
                p2->vetor[p2->topo] = p1->vetor[i];
                p2->topo++;

                // tambem pode ser feito chamando a funcao: empilha(p1->vetor[i], p2);
        }

        // utilizando função existente pra imprimir a pilha invertida
        imprimePilha(p2);
}

int main() {

        //DECLARA UMA PILHA

        Pilha P1;
        Pilha P2;

        // o topo da pilha deve começar em zero
        P1.topo=0; 
        P2.topo=0;

        empilha(10, &P1);
        empilha(8, &P1);
        empilha(9, &P1);

        inverte_pilha(&P1, &P2); 

}