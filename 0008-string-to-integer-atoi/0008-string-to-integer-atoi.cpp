class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // 1️⃣ Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2️⃣ Handle sign
        bool isPositive = true;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') isPositive = false;
            i++;
        }

        // 3️⃣ Skip leading zeros
        while (i < n && s[i] == '0') i++;

        // 4️⃣ Collect numeric digits
        string num = "";
        while (i < n && isdigit(s[i])) {
            num += s[i];
            i++;
        }

        // If no digits found
        if (num.empty()) return 0;

        // 5️⃣ Handle overflow (if digits > 10, guaranteed overflow)
        if (num.size() > 10) 
            return isPositive ? INT_MAX : INT_MIN;

        // 6️⃣ Convert string to long long for safe comparison
        long long val = 0;
        for (char c : num) {
            val = val * 10 + (c - '0');
            if (isPositive && val > INT_MAX) return INT_MAX;
            if (!isPositive && -val < INT_MIN) return INT_MIN;
        }

        // 7️⃣ Apply sign
        return isPositive ? (int)val : (int)(-val);
    }
};
