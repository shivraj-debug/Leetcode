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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* even=head;
        ListNode* odd=head->next;
        ListNode* temp=odd;

        while(temp!=NULL && temp->next!=NULL){
            even->next=temp->next;
            even=even->next;

            temp->next=even->next;
            temp=temp->next;
        }

        even->next=odd;

        return head;

    }
};