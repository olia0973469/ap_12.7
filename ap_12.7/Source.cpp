#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    double value;
    Node* next;
};

Node* addNode(Node* head, double value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void printList(Node* head) {
    cout << "List:" << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void rearrangeList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* lastInteger = nullptr;

    while (current != nullptr && current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (current->value == static_cast<int>(current->value)) {
            lastInteger = current;
            prev->next = nullptr;
            lastInteger->next = head;
            head = lastInteger;
        }
    }
}

int main() {
    Node* head = nullptr;

    int n1;
    cout << "Enter the size of sequence 1: ";
    cin >> n1;
    cout << "Enter sequence 1: ";
    for (int i = 0; i < n1; ++i) {
        double num;
        cin >> num;
        head = addNode(head, num);
    }

    int n2;
    cout << "Enter the size of sequence 2: ";
    cin >> n2;
    cout << "Enter sequence 2: ";
    for (int i = 0; i < n2; ++i) {
        double num;
        cin >> num;
        head = addNode(head, num);
    }

    cout << "Original list:" << endl;
    printList(head);

    rearrangeList(head);

    cout << "List after rearranging:" << endl;
    printList(head);

    return 0;
}
