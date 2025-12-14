class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> ans;
        int mod=1e9+7;

        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                
                ans.push_back(i);
    
            }
        }

        int first=1;
        int second=2;
        long long res=1;

        while(second<ans.size()){
            res=((ans[second]-ans[first])*res)%mod;
            first+=2;
            second+=2;

        }

        if(ans.size()<2 || ans.size()%2!=0) return 0;

        return (int)res;
    }
};