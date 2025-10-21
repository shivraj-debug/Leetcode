class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());

        int ans=right;


        while(right>=left){
            int mid=left+(right-left)/2;

            if(canfinish(mid,piles,h)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }

        return ans;
    }

    bool canfinish(int mid,vector<int>& piles,int h){
        long long total_time=0;

        for(int i=0;i<piles.size();i++){
            total_time += (piles[i] + mid - 1) / mid;      
        }

        if(total_time<=h){
            return true;
        }

        return false;
    }
};