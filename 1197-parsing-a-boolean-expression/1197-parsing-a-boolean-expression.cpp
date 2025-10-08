class Solution {
public:
    bool parseBoolExpr(string e) {
        stack<char> st;

        for (int i = 0; i < e.size(); i++) {
            char c = e[i];
            if (c == ',' || c == ' ') continue;

            if (c == ')') {
                vector<char> vals;
                while (!st.empty() && st.top() != '(') {
                    vals.push_back(st.top());
                    st.pop();
                }
                st.pop(); // remove '('

                char op = st.top();
                st.pop();

                char result = eval(op, vals);
                st.push(result);

            } else {
                st.push(c);
            }
        }

        return st.top() == 't';
    }

    char eval(char op, vector<char>& vals) {
        if (op == '!') {
            // only one value inside for '!'
            return vals[0] == 't' ? 'f' : 't';
        } else if (op == '&') {
            for (char v : vals) {
                if (v == 'f') return 'f';
            }
            return 't';
        } else if (op == '|') {
            for (char v : vals) {
                if (v == 't') return 't';
            }
            return 'f';
        }
        return 'f';
    }
};
