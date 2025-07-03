class Solution {
public:
    char kthCharacter(int k) {
        string s="a";

        while(s.size()<k){
            string st="";
            for(char& it:s){
                char ch=it;
                ch++;
                st+=ch;
            }
            s+=st;
        }

        return s[k-1];
    }
};