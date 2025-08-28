class Solution {
public:
    int calculate(string s) {
        int n = s.size();

        int number = 0, res = 0, sign = 1;
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') continue;

            if(s[i] == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                number = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                res += number * sign;  // complete current number
                number = 0;

                int prevSign = st.top(); st.pop();
                int prevRes = st.top(); st.pop();

                res = prevRes + prevSign * res;
            }
            else if(s[i] == '-') {
                res += (number*sign);
                sign = -1;
                number = 0;
            }
            else if(s[i] == '+') {
                res += (number*sign);
                sign = 1;
                number = 0;
            }
            else {
                string temp = "";
                while(((int)(s[i]-'0')>=0) && ((int)(s[i]-'0')<= 9)) {
                    temp.push_back(s[i]);
                    i++;
                }
                i--;
                int num = stoi(temp);
                number = num;
            }
        } res += (number*sign);
        return res;
    }
};