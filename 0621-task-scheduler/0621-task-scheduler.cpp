class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for(auto it:tasks){
            freq[it-'A']++;
        }

        priority_queue<int> pq;

        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push(freq[i]);
        }

        int time=0;

        while(!pq.empty()){
            vector<int> nums;

            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int top=pq.top();
                    pq.pop();
                    top--;
                    nums.push_back(top);
                }
            }

            for(int i=0;i<nums.size();i++){
                if(nums[i]>0){
                    pq.push(nums[i]);
                }
            }

            if(!pq.empty()) time+=n+1;
            else time+=nums.size();
        }
        return time;
    }
};