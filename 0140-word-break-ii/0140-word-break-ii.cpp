class Solution {
public:
    unordered_map<string,int> mp;
    vector<string> ans;
    vector<string> path;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto& it:wordDict){
            mp[it]++;
        }

         solve(s,0,wordDict);

         return ans;
    }

     void solve(string& s,int i,vector<string>& wordDict){
        if(i==s.size()) {
            string sentence;
            for (int k = 0; k < path.size(); k++) {
                if (k > 0) sentence += " ";
                sentence += path[k];
            }
            ans.push_back(sentence);
            return;
        }

        string st="";
        for(int j=i;j<s.size();j++){
            st+=s[j];
            if(mp.find(st)!=mp.end()){
                path.push_back(st);
                solve(s,j+1,wordDict);
                path.pop_back();
            }
        }
    }
};