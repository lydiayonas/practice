#include <iostream>
using namespace std;

// Structure Definition for Doubly Linked List Node
struct node {
    int data;
    node* next;
    node* previous; // Pointer to the previous node
};

node* start = NULL; // Pointer to the first node of the list

// Function Prototypes
void insert_beg();
void insert_end();
void insert_middle();
void delete_beg();
void delete_end();
void delete_middle();

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
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insert_beg(); break;
            case 2: insert_end(); break;
            case 3: insert_middle(); break;
            case 4: delete_beg(); break;
            case 5: delete_end(); break;
            case 6: delete_middle(); break;
            case 7: cout << "Exiting the program.\n"; return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

void insert_beg() {
    node* p = new node;
    cout << "Enter data for the new node: ";
    cin >> p->data;

    p->next = start;     // New node's next points to current start
    p->previous = NULL;  // Previous pointer of new node is NULL

    if (start != NULL) {
        start->previous = p; // Old start's previous points to new node
    }

    start = p; // Update start to the new node
    cout << "Node inserted successfully at the beginning.\n";
}

void insert_end() {
    node* p = new node;
    cout << "Enter data for the new node: ";
    cin >> p->data;

    p->next = NULL;
    p->previous = NULL;

    if (start == NULL) {
        start = p; // List was empty, new node becomes start
    } else {
        node* temp = start;

        // Traverse to the end of the list
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = p;   // Update last node's next to new node
        p->previous = temp; // Update new node's previous to last node
    }
    cout << "Node inserted successfully at the end.\n";
}

void insert_middle() {
    int position;
    cout << "Enter the position to insert the new node: ";
    cin >> position;

    node* p = new node;
    cout << "Enter data for the new node: ";
    cin >> p->data;

    if (start == NULL && position == 1) {
        // Inserting as the first node
        p->next = NULL;
        p->previous = NULL;
        start = p;
        cout << "Node inserted successfully as the first node.\n";
    } else {
        node* temp = start;
        int count = 1;

        // Traverse to the position before insertion
        while (temp != NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Position out of range.\n";
        } else {
            p->next = temp->next;
            p->previous = temp;

            if (temp->next != NULL) {
                temp->next->previous = p;
            }
            temp->next = p;
            cout << "Node inserted successfully at position " << position << ".\n";
        }
    }
}

void delete_beg() {
    if (start == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    node* temp = start; // Store the current start node
    start = start->next; // Update start to the next node

    if (start != NULL) {
        start->previous = NULL; // Set the new start's previous to NULL
    }

    delete temp; // Free memory
    cout << "Node deleted successfully at the beginning.\n";
}

void delete_end() {
    if (start == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    node* temp = start;

    // If only one node exists
    if (start->next == NULL) {
        start = NULL;
        delete temp;
    } else {
        // Traverse to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->previous->next = NULL; // Detach the last node
        delete temp; // Free memory
    }

    cout << "Node deleted successfully at the end.\n";
}

void delete_middle() {
    int position;
    cout << "Enter the position to delete the node: ";
    cin >> position;

    if (start == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    node* temp = start;
    int count = 1;

    // Traverse to the node to be deleted
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of range.\n";
    } else {
        if (temp->previous != NULL) {
            temp->previous->next = temp->next; // Link previous node to next
        } else {
            start = temp->next; // Deleting the first node
        }

        if (temp->next != NULL) {
            temp->next->previous = temp->previous; // Link next node to previous
        }

        delete temp; // Free memory
        cout << "Node deleted successfully at position " << position << ".\n";
    }
}
