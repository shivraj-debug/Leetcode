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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> temp;

        for(int i=0;i<lists.size();i++){
            ListNode* node=lists[i];

            while(node!=nullptr){
                temp.push_back(node->val);
                node=node->next;

            }
        }

        if(temp.empty()) return nullptr;

        sort(temp.begin(),temp.end());

        ListNode* root=new ListNode(temp[0]);
        ListNode* newroot=root;

        for(int i=1;i<temp.size();i++){
            ListNode* var=new ListNode(temp[i]);
            newroot->next=var;
            newroot=newroot->next;

        }

        return root;
    }
};