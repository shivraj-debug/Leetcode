/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        Node* prev=NULL;
        Node* newHead=NULL;

        if(!head) return head;

        unordered_map<Node*,Node*> mp;

        while(curr){
            Node* temp=new Node(curr->val);

            mp[curr]=temp;

            // for first node
            if(!newHead){
                newHead=temp;
                prev=temp;
            }else{
                prev->next=temp;
                prev=prev->next;
            }

            curr=curr->next;
        }

        curr=head;

        // for random

        prev=newHead;

        while(curr){
            if(!curr->random){
                prev->random=NULL;
            }else{
                Node* random=mp[curr->random];
                prev->random=random;
            }

            curr=curr->next;
            prev=prev->next;
        }

        return newHead;
    }
};