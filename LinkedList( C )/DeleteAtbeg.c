#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node *head, *temp, *newnode;

void deleteAtFirst(node**head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }else {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}


void displayNodes(node **head){
    printf("Printing All nodes: ");
    temp = *head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteAllNodes(node **head){
    while(*head!=NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void dataset(){
    head = NULL;
    int add = 1;

    while(add){
        newnode = (node*)malloc(sizeof(node));
        if(newnode == NULL){
            printf("No memory is allocated\n");
            return;
        }
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL){
            head = temp = newnode;
        }else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Press ( 1/0 ): ");
        scanf("%d", &add);
    }
    displayNodes(&head);
    deleteAtFirst(&head);
    displayNodes(&head);
    deleteAllNodes(&head);
}

int main(){
    dataset();
    return 0;
}



