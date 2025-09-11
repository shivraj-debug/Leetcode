class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int> mp;

        string vowel="AEIOUaeiou";

        for(int i=0;i<s.size();i++){
            if(vowel.find(s[i])!=string::npos){
                mp[s[i]]++; 
            }
        }

        int idx=0;

        for(int i=0;i<s.size();i++){
            if(vowel.find(s[i])!=string::npos){
                while(idx<vowel.size() && mp[vowel[idx]]==0){
                    idx++;
                }
                s[i]=vowel[idx];
                mp[vowel[idx]]--;
            }
        }
        return s;
    }
};