class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int i=0;
        while(true){
            long long val=(long long)num1-(long long)i*num2;
            if(val<0) return -1;
    
            if(__builtin_popcountll(val)<=i && i<=val) return i;
            i++;
        }

        return -1;
    }
};