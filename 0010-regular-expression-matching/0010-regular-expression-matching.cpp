class Solution {
public:
    int n,m;
    bool isMatch(string s, string p) {
         m=s.size();
         n=p.size();
        return rec(s,p,0,0);
    }

    bool rec(const string& s,const string& p,int i,int j){
        if (j == n) return i == m;

        bool match=(i<m && (s[i]==p[j] || p[j]=='.'));

        if(j + 1 < n && p[j + 1] == '*'){
            return rec(s,p,i,j+2) || (match && rec(s,p,i+1,j));
        }else{
            return match && rec(s,p,i+1,j+1);
        }

        return false;
    }
};