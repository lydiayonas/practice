#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

bool isEmpty() {
    return top == nullptr;
}

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "Pushed: " << value << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot pop." << endl;
    } else {
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Popped one element." << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    Node* temp = top;
    cout << "Stack elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    pop();
    display();

    pop();
    display();

    pop();

    return 0;
}
