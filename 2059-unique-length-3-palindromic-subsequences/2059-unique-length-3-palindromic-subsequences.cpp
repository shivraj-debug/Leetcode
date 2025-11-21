class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt=0;
        unordered_map<char,pair<int,int>> mp;

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]].first=i;
            }
            mp[s[i]].second=i;
        }

        for(auto& [ch,pos]:mp){
            int l=pos.first;
            int r=pos.second;

            if(r-l<=1) continue;

            unordered_set<char> st;
            for(int i=l+1;i<r;i++){
                st.insert(s[i]);
            }

            cnt+=st.size();
        }

        return cnt;
    }
};