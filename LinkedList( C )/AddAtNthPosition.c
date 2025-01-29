#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *head = NULL, *temp, *newnode;

void nThAdd(node **head){
    int i = 1 , pos, count = 0;
    printf("Enter position: ");
    scanf("%d", &pos);

    temp = *head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }

    if(pos < 1 || pos > count + 1){
        printf("Invalid position\n");
        return;
    }
    newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("No memory is allocated\n");
        return;
    }
    printf("Enter data to add: ");
    scanf("%d", &newnode->data);

    if(pos == 1){
        newnode->next = *head;
        *head = newnode;
    }else{
        temp = *head;
        while(i<pos-1 && temp!=NULL){
            temp = temp->next;
            i++;
        }
        newnode ->next = temp->next;
        temp->next = newnode;
    }


}


void printData(node **head){
    temp = *head;
    printf("Linked List: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteData(node **head){
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void dataset(){
    head = NULL;
    int choice = 1;

    while (choice) {
        newnode = (node*)malloc(sizeof(node));
        if (newnode == NULL) {
            printf("No memory allocated\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp->next = newnode;
        }
        temp = newnode;

        printf("Enter 1 to continue, 0 to stop: ");
        scanf("%d", &choice);
    }

    printData(&head);
    nThAdd(&head);
    printData(&head);
    deleteData(&head);
}

int main() {
    dataset();
    return 0;
}

