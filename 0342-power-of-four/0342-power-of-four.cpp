class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n<=0 || n==2 || n==3) return false;

        if(n==1) return true;

        while(n>0){
            if(n==1) return true;
            if(n%4!=0){
                return false;
            }
            n=n/4;
        }

        return true;
    }
};