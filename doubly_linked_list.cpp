#include <cassert>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
}

void displayForward(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void displayBackward(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;

    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

void deleteValue(Node*& head, int value) {
    Node* curr = head;
    while (curr != nullptr && curr->data != value)
        curr = curr->next;

    if (curr == nullptr)
        return;

    if (curr->prev != nullptr)
        curr->prev->next = curr->next;
    else
        head = curr->next;

    if (curr->next != nullptr)
        curr->next->prev = curr->prev;

    delete curr;
}

int main() {
    Node* head = nullptr;
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Forward: ";
    displayForward(head);
    cout << "Backward: ";
    displayBackward(head);

    deleteValue(head, 10);
    assert(head->data == 20);
    assert(head->prev == nullptr);

    deleteValue(head, 30);
    assert(head->next->data == 40);
    assert(head->next->prev == head);

    deleteValue(head, 40);
    assert(head->next == nullptr);
    assert(head->data == 20);

    deleteValue(head, 99);
    assert(head->data == 20);

    deleteValue(head, 20);
    assert(head == nullptr);
    deleteValue(head, 20);

    cout << "All tests passed." << endl;
    return 0;
}