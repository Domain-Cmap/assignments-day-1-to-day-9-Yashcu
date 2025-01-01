#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *SortedMerge(Node *head1, Node *head2)
{
    vector<int> arr;
    while (head1 != nullptr)
    {
        arr.push_back(head1->data);
        head1 = head1->next;
    }
    while (head2 != nullptr)
    {
        arr.push_back(head2->data);
        head2 = head2->next;
    }
    sort(arr.begin(), arr.end());
    Node *dummy = new Node(-1);
    Node *curr = dummy;

    for (int i = 0; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    return dummy->next;
}

void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    Node* curr = SortedMerge(head1,head2);

    printList(curr);
    return 0;
}