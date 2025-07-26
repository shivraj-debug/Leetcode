class Solution {
public:

    bool isMatch(char c1,char c2){
        if(c1=='(' && c2==')') return true;
        else if (c1=='[' && c2==']') return true;
        else if (c1=='{' && c2=='}') return true;

        return false;
    }

    bool isValid(string s) {
        int top=-1; // indicating stack is empty

        for(int i=0;i<s.size();i++){
            if(top==-1 || !isMatch(s[top],s[i])){
                top++;
                s[top]=s[i];
            }else{
                top--;
            }
        }

        return top==-1;

    }
};