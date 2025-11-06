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
        vector<int> help;
        ListNode* temp=head;

        while(temp!=NULL){
            help.push_back(temp->val);
            temp=temp->next;
        }

        temp=head;
        int i=0;

        sort(help.begin(),help.end());

        while(temp!=NULL){
            temp->val=help[i];
            temp=temp->next;
            i++;
        }

        return head;
    }
};