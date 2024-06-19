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

void imprimePilha(Pilha *P1){

        int i;

        printf("\nSegue Impressao da Pilha: \n");

        for(i=((P1->topo)-1);i>=0;i--){ //valor inicial de i é a ultima posição da pilha e daí decrementa

                printf("\t %d \n",P1->vetor[i]);

        }

}

void media(Pilha *p1){
        int sum=0, div=0, med;
        for(int i = 0; i<=p1->topo-1; i++){
                sum = sum + p1->vetor[i];
                div++;
        }
        med = sum/div;
        printf("A media da pilha eh: %d \n", med);
}


int main() {

        //DECLARA UMA PILHA

        Pilha P1;

        P1.topo=0; // o topo da pilha deve começar em zero

        empilha(10, &P1);
        empilha(8, &P1);
        empilha(9, &P1);
      
        media(&P1);


}