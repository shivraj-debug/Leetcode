class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int cnt=0;

        int i=0,j=0;

        while(j<nums.size()){
            int mini=nums[i];

            while(j<nums.size() && (nums[j]-nums[i])<=k){
                j++;
            }
            i=j;
            cnt++;
        }

        return cnt;
    }
};