class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> st;
        unordered_map<char,char> ts;

        for(int i=0;i<s.size();i++){
            if(st.find(s[i])!=st.end()){
                if(st[s[i]]!=t[i]) return false;
            }else{
                if(ts.find(t[i])!=ts.end()){
                    if(ts[t[i]]!=s[i]) return false;
                }else{
                    st[s[i]]=t[i];
                    ts[t[i]]=s[i];
                }
            }
        }

        return true;
        
    }
};