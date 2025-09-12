class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int res = 0;

        // try every possible h from 1 to n
        for (int h = 1; h <= n; h++) {
            int cnt = 0;

            // count how many papers have citations >= h
            for (int j = 0; j < n; j++) {
                if (citations[j] >= h) {
                    cnt++;
                }
            }

            if (cnt >= h) {
                res = max(res, h);
            }
        }

        return res;
    }
};
