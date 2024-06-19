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

int topo_p1_maior_que_p2(Pilha *p1, Pilha *p2){
        int cont;
        for(int i = 0; i<=p1->topo-1; i++){
                if(p1->vetor[p1->topo] > p2->vetor[i-1]){
                        cont++;
                } else {
                        printf(" O elemento %d da pilha 2 eh maior q o topo da pilha 1 \n", p2->vetor[i-1]);
                        break;
                }
                if(cont == p2->topo){
                        printf("Topo da pilha 1 eh maior que todos os elementos da pilha 2 \n");
                }
        }   
        printf("Topo da pilha 1: %d \n", p1->vetor[p1->topo-1]);
        return 0;
}


int main() {

        //DECLARA UMA PILHA

        Pilha P1;
        Pilha P2;

        P1.topo=0; // o topo da pilha deve começar em zero
        P2.topo=0;

        empilha(10, &P1);
        empilha(98, &P1);
        empilha(132, &P1);
        empilha(46, &P1);
        empilha(55, &P1);
        empilha(555, &P1);
        empilha(777, &P1);

        empilha(111, &P2);
        empilha(26, &P2);
        empilha(177, &P2);
        empilha(34, &P2);
        empilha(65, &P2);
        empilha(77, &P2);

        topo_p1_maior_que_p2(&P1, &P2);




}