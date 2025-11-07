class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        vector<string> helper;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                temp+='(';
            }else if(s[i]==')'){
                  temp+=')';
                  st.pop();
                  if(st.empty()){
                    helper.push_back(temp);
                    temp="";
                  }
            }
        }

        string res="";
        for(string& it:helper){
            int n=it.size();
            res+=it.substr(1,n-2);
        }

        return res;
    }
};