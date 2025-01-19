#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node * next;
}node;
void addingAtBegin(node **head){
    node * temp, *newnode;

    newnode = new node;
    if(newnode == NULL){
        cout << "No memory allocated to add at begging" << endl;
        return;
    }
    cout << "Enter the data to add at beginning: ";
    cin >> newnode->data;
    newnode->next = *head;
    *head = newnode;

}

void addingAtEnd(node **head){
    node *newnode, *temp;

    newnode = new node;
    if(newnode == NULL){
        cout << "No memory allocated to add at End" << endl;
        return;
    }
    cout << "Enter the data to add at the end: ";
    cin >> newnode->data;
    newnode->next = NULL;
    temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;

}

void dataset(){
    node *head = NULL, *temp, *newnode;
    int choice = 1;

    while(choice){
        newnode = new node;
        if(newnode == NULL){
            cout << "No memory allocated" << endl;
            return;
        }
        cout << "Enter the data: ";
        cin >> newnode->data;
        newnode->next = NULL;

        if(head == NULL){
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "Press(1/0): ";
        cin >> choice;
    }
    addingAtBegin(&head);
    addingAtEnd(&head);

    temp = head;
    while(temp != NULL){
        cout <<temp->data << " ";
        temp = temp->next;
    }
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }

}

int main(){
    dataset();

    return 0;
}
