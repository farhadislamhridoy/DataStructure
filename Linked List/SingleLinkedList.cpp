#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void dataset(){
    Node *head, *newnode, *temp;
    int choice = 1;
    head = NULL;

    while(choice){
        newnode = (Node*)malloc(sizeof(Node));
        if(newnode == NULL){
            cout << "No Space Allocated" << endl;
            return;
        }

        cout << "Enter Data: ";
        cin >> newnode->data;
        newnode->next = NULL;

        if(head == NULL){
            head = temp = newnode;
        }else{
            temp->next = newnode;
            temp = newnode;
        }
        cout << "Do you want to add another node? then Press 1 else 0: ";
        cin >> choice;
    }
    cout << "Entered Numbers: ";
    temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }


}

int main(){
    dataset();

    return 0;
}

