class Solution {
public:

    int findKthNumber(int n, int k) {
        long long curr=1;
        k--;

        while(k>0){
            long long steps=findsteps(n,curr,curr+1);

            if(steps>k){
                curr=curr*10;
                k--;
            }else{
                curr+=1;
                k-=steps;
            }

        }
        return curr;
    }
     long long findsteps(int n,long long curr,long long next){
            long long steps=0;

            while(curr<=n){
                steps+=min((n+1)*1LL,next)-curr;
                curr*=10;
                next*=10;
            }

            return steps;
        }
};
