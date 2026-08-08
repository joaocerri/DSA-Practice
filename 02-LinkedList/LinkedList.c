#include <stdio.h>
#include <stdlib.h>

typedef struct List{
    int Value;
    struct List *next;
}List;

List* insertEnd(List *start, int value){
    List* aux = (List*) malloc(sizeof(List));

    aux -> Value = value;
    aux -> next = NULL;

    if (start == NULL) {
        return aux;
    }

    List* current = start;
    while(current -> next != NULL){
        current = current -> next;
    }
    current -> next = aux;

    return start;
}

List* insertFirst(List *start, int value){
    List* list = (List*) malloc(sizeof(List));

    list -> Value = value;
    list -> next = start;

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
        current = current -> next;
        counter++;
    }
}

List* delete(List *start, int value){
    List *current = start;
    List *aux = NULL;

    while(current != NULL && current -> Value != value){
        aux = current;
        current = current -> next;
    }

    if(current == NULL) return start;

    if(aux == NULL) start = current -> next;
    else aux -> next = current -> next;

    free(current);
    return start;

}

List* deleteFirst(List *start)
{
    if(start == NULL){return NULL;}

    List *next = start -> next;

    free(start);

    return next;
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

    printf("\n\nAfter delete 20:");
    printList(list);

    list = deleteFirst(list);
    list = delete(list, 60);

    printf("\n\nAfter delete first element %d:", list -> Value);
    printList(list);
    
    printf("\n\nAfter delete 60:");
    printList(list);

    list = delete(list, 100);

    printf("\n\nAfter delete 100:");
    printList(list);


    return 0;
}
