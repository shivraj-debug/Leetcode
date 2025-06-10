class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;

        for(char& ch:s){
            mp[ch]++;
        }

        int odd_maxi=INT_MIN;
        int even_mini=INT_MAX;

        for(auto& [ch,num]:mp){
            if(num%2!=0){
                odd_maxi=max(odd_maxi,num);
            }else{
                even_mini=min(even_mini,num);
            }
        }

        return odd_maxi-even_mini;
    }
};