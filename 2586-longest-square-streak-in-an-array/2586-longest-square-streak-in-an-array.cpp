class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int ans=0;
        
        int maxi=*max_element(nums.begin(),nums.end());

        while(!pq.empty()){
            int ele=pq.top();
              pq.pop();
            int cntsqr=0;

            for(long long i=ele;i<=maxi;i*=i){
                cout<<i<<" ";
                if(mp.find(i)!=mp.end()){
                    cntsqr++;
                }else{
                    break;
                }
            }

            ans=max(cntsqr,ans);
        }

        if(ans==1) return -1;

        return ans;
    }
};