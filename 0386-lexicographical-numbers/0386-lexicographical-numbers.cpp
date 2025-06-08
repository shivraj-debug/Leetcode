class Solution {
public:
    vector<int> res;

    void dfs(int n, int x) {
        if (x > n) return;
        res.push_back(x);
        dfs(n, x * 10);
        if (x % 10 != 9) {
            dfs(n, x + 1);
        }
    }

    vector<int> lexicalOrder(int n) {
        dfs(n, 1);
        return res;
    }
};