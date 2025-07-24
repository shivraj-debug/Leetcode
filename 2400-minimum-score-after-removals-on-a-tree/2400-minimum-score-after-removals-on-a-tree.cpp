#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <climits>

class Solution {
public:
    int minimumScore(std::vector<int>& nums, std::vector<std::vector<int>>& edges) {
        int n = nums.size();
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        std::vector<int> subtree_xor(n, 0);
        std::vector<int> in_time(n, 0);
        std::vector<int> out_time(n, 0);
        int timer = 0;

        // A recursive lambda to perform DFS.
        // It captures all local variables by reference ([&]).
        std::function<void(int, int)> dfs = 
            [&](int u, int p) {
            in_time[u] = timer++;
            
            int current_xor = nums[u];
            for (int v : adj[u]) {
                if (v != p) {
                    dfs(v, u);
                    current_xor ^= subtree_xor[v];
                }
            }
            
            subtree_xor[u] = current_xor;
            out_time[u] = timer++;
        };

        // Start DFS from root 0.
        dfs(0, -1);

        int total_xor = subtree_xor[0];
        int min_score = INT_MAX;

        // Iterate through all pairs of nodes (i, j) to represent two cuts.
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Check for ancestor-descendant relationships.
                bool is_i_ancestor_of_j = in_time[i] <= in_time[j] && out_time[i] >= out_time[j];
                bool is_j_ancestor_of_i = in_time[j] <= in_time[i] && out_time[j] >= out_time[i];

                int x1, x2, x3;
                if (is_i_ancestor_of_j) {
                    // Case: j's subtree is inside i's subtree.
                    x1 = subtree_xor[j];
                    x2 = subtree_xor[i] ^ subtree_xor[j];
                    x3 = total_xor ^ subtree_xor[i];
                } else if (is_j_ancestor_of_i) {
                    // Case: i's subtree is inside j's subtree.
                    x1 = subtree_xor[i];
                    x2 = subtree_xor[j] ^ subtree_xor[i];
                    x3 = total_xor ^ subtree_xor[j];
                } else {
                    // Case: Disjoint subtrees.
                    x1 = subtree_xor[i];
                    x2 = subtree_xor[j];
                    x3 = total_xor ^ subtree_xor[i] ^ subtree_xor[j];
                }

                // Calculate and update the minimum score.
                int score = std::max({x1, x2, x3}) - std::min({x1, x2, x3});
                min_score = std::min(min_score, score);
            }
        }

        return min_score;
    }
};