#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} node;

void kThPosition(node **head) {
    int counts = 0, i = 1, pos;
    node *temp, *newnode;
    temp = *head;

    while (temp != NULL) {
        counts++;
        temp = temp->next;
    }

    cout << "Enter the position: ";
    cin >> pos;
    if (pos < 1 || pos > counts) {
        cout << "Invalid Position" << endl;
        return;
    } else {
        temp = *head;
        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Invalid Position" << endl;
        } else {
            newnode = new node;
            cout << "Enter the Data: ";
            cin >> newnode->data;
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void printingNodes(node **head) {
    node *temp;
    temp = *head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; // Added a new line for better output formatting
}

void deletingNodes(node **head) {
    node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}

void dataset() {
    node *head = NULL, *temp, *newnode;
    int choice = 1;

    while (choice) {
        newnode = new node;
        if (newnode == NULL) {
            cout << "No memory allocated" << endl;
            return;
        }
        cout << "Enter the data: ";
        cin >> newnode->data;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "Press ( 1/0 ): ";
        cin >> choice;
    }

    kThPosition(&head);
    printingNodes(&head);
    deletingNodes(&head);
}

int main() {
    dataset();
    return 0;
}
