class Solution {
public:
    unordered_map<string, int> memo;

    string removeConsecutive(string board) {
        int i = 0;
        while (i < board.size()) {
            int j = i;
            while (j < board.size() && board[i] == board[j]) j++;
            if (j - i >= 3) {
                board = board.substr(0, i) + board.substr(j);
                i = 0; // restart after removal
            } else {
                i++;
            }
        }
        return board;
    }

    int dfs(string board, unordered_map<char, int>& hand) {
        board = removeConsecutive(board);
        if (board.empty()) return 0;

        string key = board + "#" + serialize(hand);
        if (memo.count(key)) return memo[key];

        int res = INT_MAX;

        for (int i = 0; i < board.size(); ++i) {
            for (auto& [c, count] : hand) {
                if (count == 0) continue;

                // Only insert if it helps: either same char or diff in between same chars
                if (c == board[i] || (i > 0 && board[i - 1] == board[i] && board[i] != c)) {
                    hand[c]--;
                    string newBoard = board.substr(0, i) + c + board.substr(i);
                    int steps = dfs(newBoard, hand);
                    if (steps != -1) {
                        res = min(res, steps + 1);
                    }
                    hand[c]++;
                }
            }
        }

        return memo[key] = (res == INT_MAX ? -1 : res);
    }

    string serialize(unordered_map<char, int>& hand) {
        string result;
        for (char c : {'R', 'Y', 'B', 'G', 'W'}) {
            result += c + to_string(hand[c]);
        }
        return result;
    }

    int findMinStep(string board, string hand) {
        unordered_map<char, int> handMap;
        for (char c : hand) handMap[c]++;
        return dfs(board, handMap);
    }
};
