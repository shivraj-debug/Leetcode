class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxele=*max_element(nums.begin(),nums.end())+k;

        vector<int> freq(maxele+1,0);

        for(auto& num:nums){
            freq[num]++;
        }

        for(int i=1;i<=maxele;i++){
            freq[i]+=freq[i-1];
        }

        int result=1;

        for(int num=0;num<=maxele;num++){

            if(freq[num]==0) continue;
            int left = max(1, num - k);            
            int right = min(maxele, num + k); 

            int total_freq=freq[right]-freq[left-1];
            int curr_ele_freq=freq[num]-freq[num-1];
            int total_op_req=total_freq-curr_ele_freq;

            int op=min(numOperations,total_op_req)+curr_ele_freq;

            result=max(op,result);
        }

        return result;
    }
};