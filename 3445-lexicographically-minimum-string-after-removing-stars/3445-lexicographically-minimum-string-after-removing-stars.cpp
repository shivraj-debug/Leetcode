class Solution {
public:
    string clearStars(string s) {
        string stack;
    multiset<char> ordered;

    for (char ch : s) {
        if (ch == '*') {
            if (!stack.empty()) {
                // Remove smallest from ordered
                char minChar = *ordered.begin();
                ordered.erase(ordered.begin());

                // Remove from stack (last matching occurrence)
                for (int i = stack.size() - 1; i >= 0; --i) {
                    if (stack[i] == minChar) {
                        stack.erase(stack.begin() + i);
                        break;
                    }
                }
            }
        } else {
            stack.push_back(ch);
            ordered.insert(ch);
        }
    }

    return stack;
    }
};