class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int max_count=0;
        int maxi=*max_element(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            int cnt=0;
            while(i<nums.size() && nums[i]!=maxi){
                i++;
            }

            while(i<nums.size() && nums[i]==maxi){
                cnt++;
                i++;
            }

            max_count=max(max_count,cnt);
        }

        return max_count;
    }
};