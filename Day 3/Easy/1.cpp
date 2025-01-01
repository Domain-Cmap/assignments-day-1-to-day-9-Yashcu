class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        while(list1!=nullptr){
            arr.push_back(list1->val);
            list1 = list1->next;
        }

        while(list2!=nullptr){
            arr.push_back(list2->val);
            list2 = list2->next;
        }

        sort(arr.begin(),arr.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        for(int i=0;i<arr.size();i++){
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }

        return dummy->next;
    }
};