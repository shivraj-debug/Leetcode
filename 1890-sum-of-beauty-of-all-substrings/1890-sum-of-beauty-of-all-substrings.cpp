class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < s.size(); j++) {
                mp[s[j]]++;

                int maxi = INT_MIN, mini = INT_MAX;
                for (auto &p : mp) {
                    maxi = max(maxi, p.second);
                    mini = min(mini, p.second);
                }

                ans += (maxi - mini);
            }
        }

        return ans;
    }
};
