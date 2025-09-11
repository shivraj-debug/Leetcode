class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        string res(s.begin(),s.end());

        string vowel="aeiouAEIOU";

        for(int i=0;i<s.size();i++){
            if(find(vowel.begin(),vowel.end(),s[i])!=vowel.end()){
                v.push_back(s[i]); 
                res[i]='1';
            }
        }

        int i=0;

        sort(v.begin(),v.end());

        for(auto& it:v){
            while(i<s.size() && res[i]!='1'){
                i++;
            }
            res[i]=it;
            i++;
        }

        return res;
    }
};