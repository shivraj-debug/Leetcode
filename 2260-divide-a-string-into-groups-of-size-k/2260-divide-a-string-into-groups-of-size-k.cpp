class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int size = s.size();
        int rem = size % k;

        // Only add padding if needed
        if (rem != 0) {
            s.append(k - rem, fill);
        }

        vector<string> res;

        for (int i = 0; i < s.size(); i += k) {
            res.push_back(s.substr(i, k));
        }

        return res;
    }
};
