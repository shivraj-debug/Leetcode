class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;

        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]--;

        vector<int> excess;

        // Check if it's possible to make the baskets equal
        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) return -1; // Cannot be made equal
            for (int i = 0; i < abs(count) / 2; ++i)
                excess.push_back(fruit);
        }

        if (excess.empty()) return 0;

        // Find the minimum fruit cost across both baskets
        int minVal = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));

        sort(excess.begin(), excess.end());

        long long cost = 0;
        int swaps = excess.size() / 2;

        // For each swap, we pick the cheaper of:
        // - the fruit itself
        // - 2 * minVal (replace both fruits with the smallest value)
        for (int i = 0; i < swaps; ++i) {
            cost += min(excess[i], 2 * minVal);
        }

        return cost;
    }
};
