/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
       return solve(head);
    }

    ListNode* solve(ListNode* head){
        if(head->next==NULL) return head;

        ListNode* temp=solve(head->next);

        head->next->next=head;
        head->next=nullptr;

        return temp;

    }
};