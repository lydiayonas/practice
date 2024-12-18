#include <iostream>
using namespace std;

// Structure Definition for Doubly Linked List Node
struct node {
    int data;
    node* next;
    node* previous;
};

node* start = NULL;

// Function Prototypes
void insert_beg();
void insert_end();
void insert_middle();
void delete_beg();
void delete_end();
void delete_middle();
void display();

int main() {
    int choice;
    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Middle\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Middle\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insert_beg(); break;
            case 2: insert_end(); break;
            case 3: insert_middle(); break;
            case 4: delete_beg(); break;
            case 5: delete_end(); break;
            case 6: delete_middle(); break;
            case 7: display(); break;
            case 8: cout << "Exiting the program.\n"; return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

// Insert at Beginning
void insert_beg() {
    node* p = new node();
    cout << "Enter data for the new node: ";
    cin >> p->data;
    p->next = p->previous = NULL;

    if (start == NULL) {
        start = p;
    } else {
        p->next = start;
        start->previous = p;
        start = p;
    }
    cout << "Node inserted successfully at the beginning.\n";
}

// Insert at End
void insert_end() {
    node* p = new node();
    cout << "Enter data for the new node: ";
    cin >> p->data;
    p->next = p->previous = NULL;

    if (start == NULL) {
        start = p;
    } else {
        node* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
        p->previous = temp;
    }
    cout << "Node inserted successfully at the end.\n";
}

// Insert at Middle
void insert_middle() {
    int pos;
    cout << "Enter the position to insert the new node: ";
    cin >> pos;

    if (pos == 1) {
        insert_beg();
        return;
    }

    node* p = new node();
    cout << "Enter data for the new node: ";
    cin >> p->data;
    p->next = p->previous = NULL;

    node* temp = start;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of bounds. Inserting at the end.\n";
        insert_end();
    } else {
        p->next = temp->next;
        p->previous = temp;
        temp->next->previous = p;
        temp->next = p;
        cout << "Node inserted successfully at position " << pos << ".\n";
    }
}

// Delete at Beginning
void delete_beg() {
    if (start == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    node* temp = start;
    start = start->next;

    if (start != NULL) {
        start->previous = NULL;
    }

    delete temp;
    cout << "Node deleted successfully at the beginning.\n";
}

// Delete at End
void delete_end() {
    if (start == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    node* temp = start;

    if (start->next == NULL) {
        start = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->previous->next = NULL;
    }

    delete temp;
    cout << "Node deleted successfully at the end.\n";
}

// Delete at Middle
void delete_middle() {
    int pos;
    cout << "Enter the position to delete the node: ";
    cin >> pos;

    if (start == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    if (pos == 1) {
        delete_beg();
        return;
    }

    node* temp = start;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range.\n";
        return;
    }

    if (temp->next != NULL) {
        temp->next->previous = temp->previous;
    }
    if (temp->previous != NULL) {
        temp->previous->next = temp->next;
    }

    delete temp;
    cout << "Node deleted successfully at position " << pos << ".\n";
}

// Display List
void display() {
    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }

    node* temp = start;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
