class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string st="";
            for(int i=1;i<s.size();i++){
                int num=((s[i]-'0')+(s[i-1]-'0'))%10;
                st+=to_string(num);
            }

            s=st;
        }

        if(s[0]==s[1]) return 1;

        return 0;
    }
};