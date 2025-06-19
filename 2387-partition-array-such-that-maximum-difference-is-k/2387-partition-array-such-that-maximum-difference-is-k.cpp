class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        vector<pair<int,int>> temp;

        for(int i=0;i<nums.size();i++){
            temp.push_back({nums[i],i});
        }

        sort(temp.begin(),temp.end());
        int cnt=0;

        int i=0,j=0;

        while(j<temp.size()){
            int mini=temp[i].first;

            // vector<pair<int,int>> temp2;

            while(j<temp.size() && (temp[j].first-temp[i].first)<=k){
                j++;
            }
            i=j;
            cnt++;
        }

        return cnt;
    }
};