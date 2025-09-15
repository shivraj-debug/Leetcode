class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int n=nums.size();
       int first=0;
       int end=n-1;
       int idx=-1;

       while(first<=end){
            int mid=(first+end)/2;

            if(target<nums[mid]){
                end=mid-1;
            }else if(target>nums[mid]){
                first=mid+1;
            }else{
                idx=mid;
                break;
            }
       }

       if(idx==-1) return {-1,-1};
       int i=idx-1;
       first=idx;

       while(i>=0 && nums[i]==target){
        i--;
        first--;
       }

       i=idx+1;
       int last=idx;
       while(i<n && nums[i]==target){
            i++;
            last++;
       }

       return {first,last};
    }
};