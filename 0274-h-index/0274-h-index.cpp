class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int res = 0;

        sort(citations.begin(), citations.end()); // ascending

        for (int i = 0; i < n; i++) {
            int h = n - i;  // number of papers with at least citations[i]
            if (citations[i] >= h) {
                res = h;
                break; // since sorted ascending, this is the max possible h
            }
        }

        return res;
    }
};
