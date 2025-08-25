class Solution {
public:

    unordered_map<string,int> mp;
    int maxProfit(int k, vector<int>& prices) {
        mp.clear();
        return rec(k,0,prices,true);
    }

    int rec(int k,int i,vector<int>& prices,bool buy){
        if(i>=prices.size() || k<=0){
            return 0;
        }

        string st=to_string(k)+'#'+to_string(i)+'#'+to_string(buy);

        if(mp.find(st)!=mp.end()) return mp[st];

        int a,b;
        
        if(buy){
            a=rec(k,i+1,prices,buy);
            b=rec(k,i+1,prices,!buy)-prices[i];
        }else{
            a=rec(k,i+1,prices,buy);
            b=rec(k-1,i+1,prices,!buy)+prices[i];
        }

        return mp[st] = max(a,b);
    }
};