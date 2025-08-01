class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        int idx = 0;

        while (idx < numRows) {
            vector<int> temp(idx + 1, 1); // Initialize row with 1s

            for (int i = 1; i < idx; i++) {
                temp[i] = res[idx - 1][i - 1] + res[idx - 1][i];
            }

            res.push_back(temp);
            idx++; // Increment to avoid infinite loop
        }

        return res;
    }
};
