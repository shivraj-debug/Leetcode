class Solution {
public:
    int mod = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;

        // Decompose n into powers of 2
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) powers.push_back(1 << i);
        }

        // Prefix product array
        vector<long long> presum(powers.size());
        presum[0] = powers[0] % mod;
        for (int i = 1; i < powers.size(); i++) {
            presum[i] = (presum[i - 1] * powers[i]) % mod;
        }

        vector<int> ans(queries.size());
        int idx = 0;

        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];

            if (left == 0) {
                ans[idx] = presum[right];
            } else {
                long long inv = modPow(presum[left - 1], mod - 2); // modular inverse
                ans[idx] = (presum[right] * inv) % mod;
            }
            idx++;
        }
        return ans;
    }
};
