#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char soma = '+';
const char subtração = '-';
const char multiplicação = '*';
const char divisão = '/';

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

int dividir(double decimal){
    int number = 1;
    int size = (int) decimal;
    while(size){
        number *= 10;
        size /= 10; 
    }
    return number;
}

void armazenar(No** new,double number){
    if(*new == NULL){
        (*new) = createNo();
        (*new)->numero = number;
        return;
    }
    No* aux = *new;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = createNo();
    aux->next->numero = number;
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
                number = integer + (decimal/dividir(decimal));
                armazenar(&new,number);
                break;
            }
            
            if(expressão[i] == '.'){
                sumDecimal = 1;
                i++;
            }

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

