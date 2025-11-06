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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* middle=findMiddle(head);

        ListNode* right=middle->next;
        middle->next=nullptr;

       ListNode* leftSort= sortList(head);
       ListNode* rightSort= sortList(right);

        return mergeSort(leftSort,rightSort);
    }


    ListNode* mergeSort(ListNode* head,ListNode* right){
        ListNode* newHead=new ListNode(-1);
        ListNode* temp=newHead;

        while(head && right){
            if(head->val>=right->val){
                temp->next=right;
                right=right->next;
            }else{
                temp->next=head;
                head=head->next;
            }
            temp=temp->next;
        }


        if(head){
            temp->next=head;
        }
        else if(right){
            temp->next=right;
        }

        return newHead->next;
    }

    ListNode* findMiddle(ListNode* head){

        if(!head || !head->next) return head;

        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
};