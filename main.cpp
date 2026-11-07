#include <cassert>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;
    curr->next = newNode;
}

void display(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

void insertFront(Node*& head, int value) {
    head = new Node{value, head};
}

bool search(Node* head, int value) {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == value)
            return true;
        curr = curr->next;
    }
    return false;
}

int countNodes(Node* head) {
    int count = 0;
    Node* curr = head;
    while (curr != nullptr) {
        ++count;
        curr = curr->next;
    }
    return count;
}

void deleteValue(Node*& head, int value) {
    if (head == nullptr)
        return;

    if (head->data == value) {
        Node* removed = head;
        head = head->next;
        delete removed;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr && curr->next->data != value)
        curr = curr->next;

    if (curr->next != nullptr) {
        Node* removed = curr->next;
        curr->next = removed->next;
        delete removed;
    }
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Original list: ";
    display(head);

    insertFront(head, 5);
    assert(head->data == 5);
    assert(countNodes(head) == 5);
    assert(search(head, 30));
    assert(!search(head, 99));

    deleteValue(head, 5);
    assert(head->data == 10);
    deleteValue(head, 30);
    assert(!search(head, 30));
    deleteValue(head, 40);
    assert(countNodes(head) == 2);
    deleteValue(head, 99);
    assert(countNodes(head) == 2);

    deleteValue(head, 10);
    deleteValue(head, 20);
    assert(head == nullptr);
    assert(countNodes(head) == 0);
    assert(!search(head, 10));

    cout << "All tests passed." << endl;
    return 0;
}