class Solution {
public:

    class trienode{
        public:
        string folder;
        bool remove=false;
        map<string,trienode*> child;

        trienode(string folder){
            this->folder=folder;
        }
    };

    void buildTrie(trienode* root,vector<string>& path){
         for(auto& p:path){
            if(!root->child.count(p)){
                root->child[p]=new trienode(p);
            }
            root=root->child[p];
         }
    }

    string markRepeating(trienode* root,unordered_map<string,trienode*>& visited){
        string subfolder;
        for(auto& [childfolder,childnode]:root->child){
            subfolder+=markRepeating(childnode,visited);
        }

        if(subfolder.size()){
            if(visited[subfolder]){
                visited[subfolder]->remove=true;
                root->remove=true;
            }else{
                visited[subfolder]=root;
            }
        }

        return "["+root->folder+subfolder+"]";
    }

    void savepath(trienode* root,vector<vector<string>>& res,vector<string>& curr_path){
        if(root->remove){
            return;
        }

        curr_path.push_back(root->folder);
        res.push_back(curr_path);

        for(auto& [subfolder,childnode]:root->child){
            savepath(childnode,res,curr_path);
        }

        curr_path.pop_back();
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        trienode* root=new trienode("/");

        // build a trie;
        for(auto& path:paths){
            buildTrie(root,path);
        }

        // mark remove if duplicate
        unordered_map<string,trienode*> visited;
        markRepeating(root,visited);

        // build ans

        vector<vector<string>> res;
        vector<string> curr_path;

        for(auto& [subfolder,childnode]:root->child){
            savepath(childnode,res,curr_path);
        }

        return res;
    }
};