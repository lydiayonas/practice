#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* start = NULL;

void insert_beg(int new_data) {
    node* new_node = new node;
    new_node->data = new_data;
    new_node->next = start;
    start = new_node;
    cout << "New node inserted at the beginning with data: " << new_data << endl;
}

void insert_end(int new_data) {
    node* new_node = new node;
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (start == NULL) { // If the list is empty
        start = new_node;
    } else {
        node* temp = start;
        while (temp->next != NULL) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = new_node; // Link the new node at the end
    }
    cout << "New node inserted at the end with data: " << new_data << endl;
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
    cout << "Enter a number to insert at the beginning: ";
    cin >> x;
    insert_beg(x);
    insert_beg(1);
    insert_beg(2);

    cout << "Enter a number to insert at the end: ";
    cin >> x;
    insert_end(x);
    insert_end(10);

    cout << "Linked list: ";
    display();
    
    return 0;
}







/*
#include <iostream>
using namespace std;

struct Node {
    int data;   
    Node* next; 
};

Node* start = NULL;

void insert_end(int new_data) {
  
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL; 
    if (start == NULL) {
        start = new_node;
        cout << "Inserted at the beginning (list was empty): " << new_data << endl;
        return;
    }

    
    Node* temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    temp->next = new_node;
    cout << "Inserted at the end: " << new_data << endl;
}

void display() {
    Node* temp = start; 
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next; 
    }
    cout << endl;
}

int main(){
int x;
    cout<<"enter the no";
    cin>>x;
    insert_end(x); 
    insert_end(20); 
    insert_end(30); 

    display(); 
    return 0;
}*/