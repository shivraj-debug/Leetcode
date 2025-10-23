class Node{
    public:
    Node* child[26];
    bool isWord;

    Node(){
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
        isWord=false;
    }
};

class Trie {
public:
    
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(char& ch:word){
            int num=ch-'a';
            if(!temp->child[num]) temp->child[num]=new Node();
            temp=temp->child[num];
        }
        temp->isWord=true;
    }
    
    bool search(string word) {
        Node* temp=root;

        for(char& ch:word){
            int i=ch-'a';
            if(!temp->child[i]) return false;
            temp=temp->child[i];
        }

        if(!temp->isWord) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
         Node* temp=root;

        for(char& ch:prefix){
            int i=ch-'a';
            if(!temp->child[i]) return false;
            temp=temp->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */