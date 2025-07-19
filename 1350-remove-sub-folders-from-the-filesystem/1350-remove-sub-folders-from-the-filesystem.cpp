class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st;

        for(int i=0;i<folder.size();i++){
            st.insert(folder[i]);
        }

        vector<string> ans;

        for(string& it:folder){
            string s=it;
            bool x=false;

               while(!it.empty()){
                 size_t position=it.find_last_of('/');

                   it=it.substr(0,position);

                   if(st.find(it)!=st.end()){
                        x=true;
                        break;
                    }
                }
              if(!x) ans.push_back(s);

        }
       return ans;
    }
};