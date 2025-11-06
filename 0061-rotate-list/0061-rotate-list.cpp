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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int cnt=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            cnt++;
        }

        int totalreverse=k%cnt;
        if(totalreverse==0) return head;

        int run=cnt-totalreverse-1;
        temp=head;

        while(run>0){
            temp=temp->next;
            run--;
        }

        ListNode* right=temp->next;
        temp->next=nullptr;
        ListNode* newHead=right;

        while(right && right->next){
            right=right->next;
        }
        right->next=head;

        return newHead;

    }
};