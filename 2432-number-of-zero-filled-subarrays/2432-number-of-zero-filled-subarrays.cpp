class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt=0;

        int n=nums.size();

        int first=0;
        int end=0;

        while(end<n){
            while(end<n && nums[end]!=0){
                end++;
                first=end;
            }
            
            if(end>=n) break; 

            cnt+=end-first+1;
            end++;
        }

        return cnt;
    }
};