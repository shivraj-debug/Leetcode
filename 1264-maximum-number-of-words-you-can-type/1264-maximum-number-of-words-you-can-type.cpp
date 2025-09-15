class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int> mp;

        for(auto& it:brokenLetters){
            mp[it]++;
        }

        stringstream ss(text);
        string word;
        int cnt=0;

        while(ss>>word){
            string str=word;
            bool pre=true;
            for(auto& it:str){
                if(mp.find(it)!=mp.end()){
                    pre=false;
                    break;
                }
            }
            if(pre) cnt++;
        }

        return cnt;
    }
};