class Solution {
public:

    bool isPairsPossible(const vector<int>& nums,int p,int maxDiff){
        int cnt=0;

        for(int i=1;i<nums.size();){
            if(nums[i]-nums[i-1]<=maxDiff){
                cnt++;
                i+=2;
            }else{
                i+=1;
            }
        }
        return cnt>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());

        int start=0;
        int end=nums.back()-nums.front();

        int ans=end;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(isPairsPossible(nums,p,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
    }
};