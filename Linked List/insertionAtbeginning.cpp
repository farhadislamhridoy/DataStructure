#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node* next;
} node;

void numberset() {
    node* head = NULL, *newnode, *temp;
    int choice = 1;

    while (choice) {
        newnode = new node;
        if (newnode == NULL) {
            cout << "No memory is allocated!!!" << endl;
            return;
        }
        cout << "Enter number: ";
        cin >> newnode->data;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "Press 1 to add another number or 0 to cancel: ";
        cin >> choice;
    }

    // Insertion at the beginning
    newnode = new node;
    cout << "Enter the number you want to add at the beginning: ";
    cin >> newnode->data;
    newnode->next = head;
    head = newnode;

    cout << "Entered numbers: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Freeing the allocated memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    numberset();
    return 0;
}
