class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp;
        
        for(auto& it:s){
            mp[it]++;
        }

        int vowel_max=0;
        int const_max=0;

        for(auto& it:mp){
            char c=it.first;
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                vowel_max=max(vowel_max,it.second);
            }else{
                const_max=max(const_max,it.second);
            }
        }

        return vowel_max + const_max;
    }
};