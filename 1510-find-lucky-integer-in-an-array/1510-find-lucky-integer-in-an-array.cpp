class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(int& it:arr){
            mp[it]++;
        }

        int maxi=0;

        for(auto& [num,freq]:mp){
            if(num==freq && maxi<num){
                maxi=num;
            }
        }

        return maxi==0?-1:maxi;
    }
};