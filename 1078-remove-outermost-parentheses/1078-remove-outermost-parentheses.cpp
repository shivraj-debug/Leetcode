class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string res="";
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                temp+='(';
            }else if(s[i]==')'){
                  temp+=')';
                  st.pop();
                  if(st.empty()){
                    int n=temp.size();
                    res+=temp.substr(1,n-2);
                    temp="";
                  }
            }
        }

        return res;
    }
};