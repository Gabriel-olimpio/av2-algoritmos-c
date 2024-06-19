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

        for(i=((P->topo)-2);i>=0;i--){ //valor inicial de i é a ultima posição da pilha e daí decrementa

                printf("\t %d \n",P->vetor[i]);

        }

}


int transferirElementos(Pilha *p1, Pilha *p2){

        // verifica se a pilha esta vazia ou cheia
        if(p1->topo >= TAMANHO_PILHA){
                printf("+1");
        } else if (p1->topo == 0) {
                printf("-1");
        } else {
                printf("pilha nem cheia nem vazia, tamanho: %d \n", p1->topo);
        }

        // copia elementos da pilha 1 para a pilha 2
        for(int i = 0; i<=p1->topo; i++){
                p2->vetor[i] = p1->vetor[i];
                p2->topo++;
        }
        imprimePilha(p2);
        return 0;
}

int main() {

        //DECLARA UMA PILHA

        Pilha P1;
        Pilha P2;

        // o topo da pilha deve começar em zero
        P1.topo=0; 
        P2.topo=0; 

        empilha(10, &P1);
        empilha(98, &P1);
        empilha(132, &P1);
        empilha(46, &P1);
        empilha(55, &P1);
        empilha(555, &P1);
        empilha(777, &P1);

        transferirElementos(&P1, &P2);
        

}