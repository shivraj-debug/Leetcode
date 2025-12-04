class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int cnt = 0;

        for (char c : directions) {

            if (st.empty()) {
                st.push(c);
                continue;
            }

            if (c == 'R') {
                // R always moves forward → just push
                st.push('R');
            } 
            else if (c == 'S') {
                // Any R before S will collide with S
                while (!st.empty() && st.top() == 'R') {
                    cnt++;
                    st.pop();
                }
                st.push('S');
            } 
            else { // c == 'L'
                if (st.top() == 'R') {
                    // First R-L gives 2 collisions
                    st.pop();
                    cnt += 2;

                    // More R's behind? They all hit S → +1 each
                    while (!st.empty() && st.top() == 'R') {
                        cnt++;
                        st.pop();
                    }
                    st.push('S');
                } 
                else if (st.top() == 'S') {
                    // L hits S → +1
                    cnt++;
                } 
                else {
                    // L after L → no collision
                    st.push('L');
                }
            }
        }

        return cnt;
    }
};
