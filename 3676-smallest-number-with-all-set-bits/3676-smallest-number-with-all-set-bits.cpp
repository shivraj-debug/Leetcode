class Solution {
public:
    int smallestNumber(int n) {
        int ans=0;

        for(int i=n;i<=INT_MAX;i++){
            bool pre=true;
            int num=i;
            while(num>0){
                int t=num&1;
                if(t==0){
                    pre=false;
                    break;
                }
                num=num>>1;              
            }

            if(pre==true) return i;
        }

        return -1;
    }
};