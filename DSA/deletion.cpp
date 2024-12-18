#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* start = NULL;

void insert_end(int new_data) {
    node* new_node = new node;
    new_node->data = new_data;
    new_node->next = NULL;

    if (start == NULL) {
        start = new_node;
    } else {
        node* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_beg() {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    node* temp = start;
    start = start->next;
    cout << "Deleted node with data: " << temp->data << endl;
    delete temp;
}

void delete_end() {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    if (start->next == NULL) {
        cout << "Deleted node with data: " << start->data << endl;
        delete start;
        start = NULL;
        return;
    }
    node* temp = start;
    while (temp->next && temp->next->next != NULL) {
        temp = temp->next;
    }
    cout << "Deleted node with data: " << temp->next->data << endl;
    delete temp->next;
    temp->next = NULL;
}

void delete_at_position(int pos) {
    if (start == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    if (pos == 0) {
        delete_beg();
        return;
    }
    node* temp = start;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Position is out of range!" << endl;
        return;
    }
    node* to_delete = temp->next;
    temp->next = temp->next->next;
    cout << "Deleted node with data: " << to_delete->data << endl;
    delete to_delete;
}

void display() {
    node* temp = start;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int x;
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);
    cout << "Linked list: ";
    display();

    delete_beg();
    cout << "After deleting from the beginning: ";
    display();

    delete_end();
    cout << "After deleting from the end: ";
    display();

    delete_at_position(1);
    cout << "After deleting node at position 1: ";
    display();

    return 0;
}
