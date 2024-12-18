
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
    cout << "New node inserted with data: " << new_data << endl;
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
    cout << "Enter a number: ";
    cin >> x;
    insert_beg(x);
    insert_beg(1);
    insert_beg(2);

    display();
    return 0;
}