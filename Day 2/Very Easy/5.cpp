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

class Solution
{
public:
    bool hasCycle(Node *head)
    {
        if (!head || !head->next)
        {
            return false;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};

Node* createListwithCycle(vector<int> values,int pos){
    if(values.empty()){
        return NULL;
    }
    Node* head = new Node(values[0]);
    Node* current = head;
    Node* Cyclepoint = nullptr;
    for(int i = 1;i<values.size();i++){
        current->next = new Node(values[i]);
        current = current->next;
        if(i==pos){
            Cyclepoint = current;
        }
    }

    if(pos>=0){
        current->next = Cyclepoint;
    }
    return head;
}

int main()
{
    Solution solve;
    vector<int> values = {1,2,3,4,5};
    int pos = 1;
    Node* head = createListwithCycle(values,1);

    if(solve.hasCycle(head)){
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }
    
    return 0;
}