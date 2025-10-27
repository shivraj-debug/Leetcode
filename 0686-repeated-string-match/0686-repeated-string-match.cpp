class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = 1;
        string st = a;

        while (st.size() < b.size()) {
            st += a;
            n++;
        }

        if (st.find(b) != string::npos) return n;

        // maybe b spans across boundary → one more repetition
        st += a;
        n++;

        if (st.find(b) != string::npos) return n;

        return -1;
    }
};
