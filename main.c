#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char soma = '+';
const char subtração = '-';
const char multiplicação = '*';
const char divisão = '/';
const char elevado = '^';

typedef struct no{
    double numero;
    struct no* next;
}No;

No* createNo(){
    No* new =(No*) malloc(sizeof(No));
    new->next=NULL;
    return new;
}

double add(double number,char converter){
    number *=10;
    number += converter - '0';
    return number;
}

int expoente(double number, double expo, int quantitity){
    if(quantitity){
        int number = 1;
        int size = (int) expo;
        while(size){
            number *= 10;
            size /= 10; 
        }
        return number;
      }else{
        int soma = 1;
        for(int i = 0;i<expo;i++){
            soma *= number;
        }
        return soma;
    }
}

void empilhar(No** new,double number){
    //printf("entrou %.2f",number);
    No* aux = createNo();
    aux->next = *new;    
    aux->numero = number;
    *new = aux;
}

double desimpilhar(No** new){
    if(*new == NULL){
        return 0;
    }

    No* aux = (*new)->next;
    double numero = (*new)->numero;
    free(*new);
    *new = aux;
    //printf("saiu %.2f",numero);
    return numero;
}

void operação(No ** new, char operação){
    double segundo = desimpilhar(new);
    double primeiro = desimpilhar(new);

    if(operação == soma) empilhar(new,primeiro + segundo);
    if(operação == subtração) empilhar(new,primeiro - segundo);
    if(operação == multiplicação) empilhar(new,primeiro * segundo);
    if(operação == divisão) empilhar(new,primeiro / segundo);
    if(operação == elevado) empilhar(new, expoente(primeiro,segundo,0));
}

void o(No* no){
    No* aux = no;
    while(aux != NULL){
        printf("%.2f - ",aux->numero);
        aux = aux->next;
    }
}

void notação(char* expressão){
    No * new = NULL;
    for(unsigned int i=0;i<strlen(expressão);i++){
        int aux = 1;
        double decimal = 0;
        double integer = 0;
        double number = 0;
        int sumDecimal = 0;

        while(aux){
            if(expressão[i] == ' ' || expressão[i] == '\0'){
                aux = 0;
                number = integer + (decimal/expoente(10,decimal,1));
                empilhar(&new,number);
                break;
            }

            
            if(expressão[i] == '.'){
                sumDecimal = 1;
                i++;
            }

            if(expressão[i] == 42 || expressão[i] == 43 || expressão[i] == 45 ||expressão[i] == 47 || expressão[i] == 94 ){

                operação(&new,expressão[i]);
                i++;

                break;
            } else if(expressão[i] < 48 || expressão[i] > 57) printf("%c não é reconhecido",expressão[i]);

            if(sumDecimal){
                decimal = add(decimal,expressão[i]);

            }else{
                integer = add(integer,expressão[i]);
            }
            i++;

        }
    }
    o(new);
    printf("a");

}

int main(){

    char * aux = (char*) malloc(10000* sizeof(char));

    scanf("%[^\n]%*c",aux);

    char * expressão = (char *) malloc(strlen(aux) * sizeof(char));

    strcpy(expressão,aux);

    free(aux);

    notação(expressão);
    free(expressão);
    return 0;
}
