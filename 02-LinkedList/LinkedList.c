#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    int Value;
    struct List *prox;
}List;

List* insertEnd(List *start, int value){
    List* aux = (List*) malloc(sizeof(List));

    aux -> Value = value;
    aux -> prox = NULL;

    if (start == NULL) {
        return aux;
    }

    List* current = start;
    while(current -> prox != NULL){
        current = current -> prox;
    }
    current -> prox = aux;

    return start;
}

List* insertFirst(List *start, int value){
    List* list = (List*) malloc(sizeof(List));

    list -> Value = value;
    list -> prox = start;

    return list;
}

void printList(List *start){
    List* current = start;
    int counter = 1;

    if (current == NULL) {
        printf("\nThe list is empty.");
        return;
    }

    while(current != NULL){
        printf("\nValue in this position %d: %d", counter, current -> Value);
        current = current -> prox;
        counter++;
    }
}

List* delete(List *start, int value){
    List *current = start;
    List *aux = NULL;

    while(current != NULL && current -> Value != value){
        aux = current;
        current = current -> prox;
    }

    if(current == NULL) return start;

    if(aux == NULL) start = current -> prox;
    else aux -> prox = current -> prox;

    free(current);
    return start
    
}

int main() {
    List *list = NULL;

    list = insertFirst(list, 20);
    list = insertFirst(list, 30);
    list = insertEnd(list, 60);
    list = insertEnd(list, 100);
    list = insertFirst(list, 99);
    
    printf("First List:");
    printList(list); 

    list = delete(list, 20);
    
    printf("\nAfter delete 20:");
    printList(list); 

    return 0;
}