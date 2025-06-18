class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;

        sort(nums.begin(),nums.end());

        for(int i=2;i<nums.size();i+=3){
            vector<int> temp;
            if((nums[i]-nums[i-2])<=k){
                 vector<int> temp(nums.begin() + i - 2, nums.begin() + i + 1);
                res.push_back(temp);
            }else{
                return {};
            }

        }
        
        return res;
    }
};