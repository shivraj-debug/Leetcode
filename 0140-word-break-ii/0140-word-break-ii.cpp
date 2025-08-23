class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto &w : wordDict) dict.insert(w);
        return solve(s, 0);
    }

    vector<string> solve(string &s, int i) {
        if (memo.count(i)) return memo[i];

        vector<string> res;
        if (i == s.size()) {
            res.push_back(""); // base: empty sentence
            return res;
        }

        string word;
        for (int j = i; j < s.size(); j++) {
            word.push_back(s[j]);
            if (dict.count(word)) {
                vector<string> sub = solve(s, j + 1);
                for (auto &seg : sub) {
                    if (seg.empty()) res.push_back(word);
                    else res.push_back(word + " " + seg);
                }
            }
        }

        return memo[i] = res;
    }
};
