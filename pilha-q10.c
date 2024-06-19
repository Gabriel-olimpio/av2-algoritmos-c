#include <stdio.h>

#include <stdlib.h>

#define TAMANHO_PILHA 20

typedef struct{

        int vetor[TAMANHO_PILHA]; //tamanho da pilha

        int topo;

}Pilha;


//prototipo da função empilha

void empilha(int valor,Pilha *P){

        //pilha->topo significa: ponteiro "pilha" apontando para CONTEÚDO de um item de uma struct

        if(P->topo < TAMANHO_PILHA){ //verificando se a pilha não está cheia

        //daí pode empilhar

        P->vetor[P->topo]=valor;

        P->topo++;

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

                printf(" %02d \n",P->vetor[i]);

        }

}


void intercala_pilhas(Pilha *p1, Pilha *p2, Pilha *p3){
        int iter_1 = 0, iter_2 = 0;

        while (iter_1 <= p1->topo-1 || iter_2 <= p2->topo-1) {
                if (iter_1 <= p1->topo) {
                        empilha(p1->vetor[iter_1], p3);
                        iter_1++;
                }
                if (iter_2 <= p2->topo) {
                        empilha(p2->vetor[iter_2], p3);
                        iter_2++;
                }
                
        }
}


int main() {

        //DECLARA UMA PILHA

        Pilha P1;
        Pilha P2;
        Pilha P3;

        // o topo da pilha deve começar em zero
        P1.topo=0; 
        P2.topo=0; 
        P3.topo=0; 


        empilha(10, &P1);
        empilha(20, &P1);
        empilha(30, &P1);
        empilha(40, &P1);
        empilha(68, &P1);

        
        empilha(50, &P2);
        empilha(70, &P2);
        empilha(80, &P2);
        empilha(90, &P2);
        empilha(95, &P2);
        empilha(99, &P2);

        intercala_pilhas(&P1, &P2, &P3);

        // Nao consegui resolver a impressao dos lixos de memoria
        // ele imprime o lixo de memoria assim que a pilha nao possui um valor atribuido a posição
        imprimePilha(&P3);


}