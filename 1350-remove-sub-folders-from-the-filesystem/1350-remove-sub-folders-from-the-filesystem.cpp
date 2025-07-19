class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string,int> mp;

        for(int i=0;i<folder.size();i++){
            mp[folder[i]]++;
        }

        vector<string> ans;

        for(auto f:folder){
            string st=f;

            bool yes=true;

           while(!f.empty()){
             size_t position=f.find_last_of('/');

              f=f.substr(0,position);

            if(mp.find(f)!=mp.end()){
                yes=false;
                break;
            }
           }

            if(yes) ans.push_back(st); 
        }

        return ans;
    }
};