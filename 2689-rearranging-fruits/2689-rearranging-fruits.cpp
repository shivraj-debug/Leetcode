class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        unordered_map<int,int> mp;

        for(auto& it:basket1){
            mp1[it]++;
            mp[it]++;
        }

        for(auto& it:basket2){
            mp2[it]++;
            mp[it]++;
        }

        for(auto it:mp){
            if((it.second)%2!=0){
                return -1;
            }
        }

        vector<int> st;


        for(auto& it:mp1){
            if(mp2.find(it.first)!=mp2.end()){
                int diff=abs(it.second-mp2[it.first])/2;
                for(int i=0;i<diff;i++){
                    st.push_back(it.first);
                }
                mp1[it.first]=0;
                mp2[it.first]=0;
            }
        }

        for(auto& it:mp1){
             for(int i=0;i<it.second/2;i++){
                    st.push_back(it.first);
                }
        }


        for(auto& it:mp2){
             for(int i=0;i<it.second/2;i++){
                    st.push_back(it.first);
                }
        }

        sort(st.begin(),st.end());

        int minVal=min(*min_element(basket1.begin(),basket1.end()),*min_element(basket2.begin(),basket2.end()));
        
        int n=st.size();

        long long res=0;

        for(int i=0;i<n/2;i++){
            res+=min(st[i],2*minVal);
        }

        return res;

    }
};