class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int cnt=0;

        for(int i=0;i<31;i++){
            if(n & 1<<i){
                cnt++;
            }

            if(cnt>1) return false;
        }

        return cnt==1;
    }
};