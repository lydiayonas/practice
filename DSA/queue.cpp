#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    if (front == nullptr && rear == nullptr) {
        return true;
    } else {
        return false;
    }
}

void enqueue(int value) {
    Node* newNodePtr = new Node();
    newNodePtr->data = value;
    newNodePtr->next = nullptr;

    if (front == nullptr) {
        front = newNodePtr;
        rear = newNodePtr;
    } else {
        rear->next = newNodePtr;
        rear = newNodePtr;
    }
    cout << "Enqueued: " << value << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    if (front == rear) {
        delete front;
        front = nullptr;
        rear = nullptr;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    cout << "Dequeued one element." << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;
    cout << "Queue elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    dequeue();
    display();

    dequeue();
    display();

    dequeue();

    return 0;
}
