class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        // Step 1: Maximize the number
        char maxTarget = ' ';
        for (char c : s) {
            if (c != '9') {
                maxTarget = c;
                break;
            }
        }

        string maxi = s;
        if (maxTarget != ' ') {
            for (char& c : maxi) {
                if (c == maxTarget) {
                    c = '9';
                }
            }
        }

        // Step 2: Minimize the number
        char minTarget = s[0];
        string mini = s;
        for (char& c : mini) {
            if (c == minTarget) {
                c = '0';
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};
