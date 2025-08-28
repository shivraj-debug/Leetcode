class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Sorting diagonals starting from the first column (j=0)
        for (int i = 0; i < n; i++) {
            vector<int> helper;
            int row = i, col = 0;

            // Collect diagonal elements
            while (row < n && col < n) {
                helper.push_back(grid[row][col]);
                row++;
                col++;
            }

            // Sort in descending order
            if (helper.size() > 1) {
                sort(helper.rbegin(), helper.rend());
            }

            // Put back sorted elements
            row = i, col = 0;
            int ind = 0;
            while (row < n && col < n) {
                grid[row][col] = helper[ind++];
                row++;
                col++;
            }
        }

        // Sorting diagonals starting from the first row (i=0)
        for (int j = 1; j < n; j++) {
            vector<int> helper;
            int row = 0, col = j;

            // Collect diagonal elements
            while (row < n && col < n) {
                helper.push_back(grid[row][col]);
                row++;
                col++;
            }

            // Sort in ascending order
            if (helper.size() > 1) {
                sort(helper.begin(), helper.end());
            }

            // Put back sorted elements
            row = 0, col = j;
            int ind = 0;
            while (row < n && col < n) {
                grid[row][col] = helper[ind++];
                row++;
                col++;
            }
        }

        return grid;
    }
};
