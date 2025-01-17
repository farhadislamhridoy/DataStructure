#include <iostream>
using namespace std;
typedef struct node{
    int data;
    struct node * next;
}node;
void numberset(){
    node *head = NULL, *temp, *newnode;
    int choice = 1;

    while(choice){
        newnode = new node;
        if(newnode == NULL){
            cout << "No Space Is Allocated In The Memory" <<endl;
            return;
        }
        cout << "Enter Number: ";
        cin >> newnode ->data;
        newnode -> next = NULL;
        if(head == NULL){
            head = temp = newnode;
        } else {
            temp -> next = newnode;
            temp = newnode;
        }
        cout << "Press 1 for adding more digit OR Press 0: ";
        cin >> choice;
    }

    newnode = new node;
    cout << "Enter the number to add in the end: ";
    cin >> newnode -> data;
    newnode -> next = NULL;
    temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;
    temp = head;
    while (temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    while(head != NULL){
        temp = head;
        head = head ->next;
        delete temp;
    }

}
int main(){
    numberset();

    return 0;
}
