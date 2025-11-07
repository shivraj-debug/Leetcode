class Solution {
public:
    string removeOuterParentheses(string s) {
        // stack<char> st;
        int n=0;
        string res="";
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                // st.push('(');
                n++;
                temp+='(';
            }else if(s[i]==')'){
                  temp+=')';
                //   st.pop();
                n--;
                  if(n==0){
                    int n=temp.size();
                    res+=temp.substr(1,n-2);
                    temp="";
                  }
            }
        }

        return res;
    }
};