class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int deletions = 0;

        // sorted[i] means strs[i] < strs[i+1] is already fixed
        vector<bool> sorted(rows - 1, false);

        for (int c = 0; c < cols; c++) {
            bool needDelete = false;

            // check if this column breaks order
            for (int r = 0; r < rows - 1; r++) {
                if (!sorted[r] && strs[r][c] > strs[r + 1][c]) {
                    needDelete = true;
                    break;
                }
            }

            // if bad column, delete it
            if (needDelete) {
                deletions++;
                continue;
            }

            // otherwise, update sorted status
            for (int r = 0; r < rows - 1; r++) {
                if (!sorted[r] && strs[r][c] < strs[r + 1][c]) {
                    sorted[r] = true;
                }
            }
        }

        return deletions;
    }
};
