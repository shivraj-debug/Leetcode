class Solution {
public:
    int totalMoney(int n) {
        int weekly=0;
        int ans=0;
        int curr=weekly;

        for(int i=1;i<=n;i++){
            if(i%7==1){
                weekly++;
                curr=weekly;
            }
            ans+=curr;
            curr++;
        }

        return ans;
    }
};