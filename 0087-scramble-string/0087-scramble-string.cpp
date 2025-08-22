class Solution {
public:
    unordered_map<string,int> mp;
    bool isScramble(string s1, string s2) {
        mp.clear();
        return solve(s1,s2);
    }

    bool solve(string s1,string s2){
        if(s1==s2) return true;

        if(s1.length()!=s2.length()) return false;

        string st=s1+"#"+s2;

        if(mp.find(st)!=mp.end()) return mp[st];

        bool result=false;
        int n=s1.size();

        for(int i=1;i<n;i++){
            bool swap=solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(i,n-i),s2.substr(0,n-i));

            bool not_swap=solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-i));

            if(swap==true || not_swap==true){
                result=true;
                break;
            }
        }

        return mp[st]=result;
    }
};