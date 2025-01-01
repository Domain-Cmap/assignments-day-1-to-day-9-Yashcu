#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* removeElements(Node* head, int val) {
    while (head != NULL && head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == val) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return head;
}

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int n, val;
    cout << "Enter number of nodes in the linked list: ";
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter the value to remove: ";
    cin >> val;

    cout << "Original list: ";
    printList(head);

    head = removeElements(head, val);

    cout << "List after removing " << val << ": ";
    printList(head);

    return 0;
}
