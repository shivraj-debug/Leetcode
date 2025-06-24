class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ans;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                int j=i-1;
                ans.insert(i);
                while( j>=0 && abs(j-i)<=k){
                    ans.insert(j);
                    j--;
                }
                j=i+1;
                while(j<nums.size() && abs(j-i)<=k){
                    ans.insert(j);
                    j++;
                }
            }
        }

        return vector<int>(ans.begin(),ans.end());
    }
};