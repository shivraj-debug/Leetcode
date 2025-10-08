class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs(spells.size(), 0);
        int n = potions.size();

        sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); i++) {
            int idx = binary(spells[i], potions, success);
            pairs[i] = n - idx; // number of potions from idx to end
        }

        return pairs;
    }

    int binary(int val, vector<int>& potions, long long success) {
        int first = 0;
        int last = potions.size() - 1;
        int ans = potions.size(); // if no potion works, return n

        while (first <= last) {
            int mid = first + (last - first) / 2;
            long long prod = (long long)potions[mid] * val;

            if (prod >= success) {
                ans = mid;        // potential answer, but search left for smaller index
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }

        return ans;
    }
};
