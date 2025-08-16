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
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* dummy=new ListNode(0);

       dummy->next=head;

       ListNode* before=dummy;
       ListNode* after=head;
       ListNode* curr = nullptr;
       ListNode* prev = nullptr;
       ListNode* next = nullptr;

       while(true){
            ListNode* temp=after;

            for(int i=0;i<k;i++){
                if(!temp) return dummy->next;
                temp=temp->next;
            }

            curr=after;
            prev=before;

            for(int i=0;i<k;i++){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }

            after->next=curr;
            before->next=prev;
            before=after;
            after=curr;
            
       }

    }
};