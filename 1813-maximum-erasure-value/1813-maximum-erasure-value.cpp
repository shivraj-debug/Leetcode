class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       
        int maxcnt=0;

        unordered_map<int,int> mp;

        int l=0;
        int r=0;
        int cnt=0;

        while(r<nums.size()){

            while(mp.find(nums[r])!=mp.end()){
                 mp.erase(nums[l]);
                 cnt-=nums[l];
                 l++;
            }

            mp[nums[r]]++;
            cnt+=nums[r];
            maxcnt=max(cnt,maxcnt);
            r++;

        }

        return maxcnt;
    }
};