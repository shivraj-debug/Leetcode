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

       using NodePair = pair<int, ListNode*>;
       
       priority_queue<NodePair,vector<NodePair>,greater<NodePair>> mini;

       for(auto list:lists){
         if(list) mini.push({list->val,list});
       }

       ListNode* dummy=new ListNode(0);
       ListNode* tail=dummy;

       while(!mini.empty()){
           auto node=mini.top();
           mini.pop();

           tail->next=node.second;
           tail=tail->next;

           if(node.second->next) mini.push({node.second->next->val,node.second->next});
       }

      return dummy->next;
    }
};