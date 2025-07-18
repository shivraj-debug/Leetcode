class Solution {
public:
    long long minimumDifference(vector<int>& nums) {

        int n=nums.size();
        int k=n/3;
        vector<long long> left(n),right(n);

        priority_queue<int> leftmaxheap;
        priority_queue<int,vector<int>,greater<int>> rightminheap;

        long long leftsum=0;
        for(int i=0;i<k;i++){
            leftsum+=nums[i];
            leftmaxheap.push(nums[i]);
        }
        left[k-1]=leftsum;

        // minimize leftsum;

        for(int i=k;i<n-k;i++){
            if(!leftmaxheap.empty() && nums[i]<leftmaxheap.top()){
                leftsum+=nums[i]-leftmaxheap.top();
                leftmaxheap.pop();
                leftmaxheap.push(nums[i]);
            }

            left[i]=leftsum;
        }

        // for right;

        long long rightsum=0;

        for(int i=n-1;i>n-k-1;i--){
            rightsum+=nums[i];
            rightminheap.push(nums[i]);
        }

        right[n-k]=rightsum;

        // maximie the rightsum;

        for(int i=n-k-1;i>=k;i--){
           if(!rightminheap.empty() && nums[i]>rightminheap.top()){
            rightsum+=nums[i]-rightminheap.top();
            rightminheap.pop();
            rightminheap.push(nums[i]);
            
           }
           right[i]=rightsum;
        }

        long long mindiff=LLONG_MAX;

        for(int i=k-1;i<n-k;i++){
            mindiff=min(mindiff,left[i]-right[i+1]);
        }

        return mindiff;
    }
};