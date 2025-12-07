class Solution {
public:
    int countOdds(int low, int high) {
        int cnt=(high-low+1)/2;

        if(low%2!=0 && high%2!=0){
            return cnt+1;
        }

        return cnt;
    }
};