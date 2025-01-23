#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node * next;
}node;

node *head, *temp, *newnode;
void DeletingFirstNode(node **head){
        if(*head == NULL){
            cout << "List is empty" << endl;
            return;
        } else {
            temp = *head;
            *head = (*head)->next;
            delete temp;
        }
}

void DisplayNodes(node **head){
    temp = *head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp ->next;
        }
            cout << "\n";
}
void DeletingNodes(node **head){
    while(*head!=NULL){
        temp = *head;
        *head = (*head)->next;
        delete temp;
    }

}
void NodeSets(){
    head = NULL;
    int add = 1;
    while(add){
        newnode = new node;
            if(newnode == NULL){
                cout << "No memory is allocated" <<endl;
                return;
            }
                cout << "Enter Data to the node: ";
                cin  >> newnode->data;
                newnode->next = NULL;

                    if(head==NULL){
                        head = temp = newnode;
                    } else {
                        temp->next = newnode;
                        temp = newnode;
                    }

                cout << "Press (1 or 0): ";
                cin  >> add;
    }
    DisplayNodes(&head);
    DeletingFirstNode(&head);
    DisplayNodes(&head);
    DeletingNodes(&head);

}

int main(){
    NodeSets();

    return 0;
}
