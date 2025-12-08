class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++){
            mp[i*i]++;
        }

        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                int sum=i*i+j*j;
                if(mp.count(sum)) cnt+=2;
            }
        }

        return cnt;
    }
};