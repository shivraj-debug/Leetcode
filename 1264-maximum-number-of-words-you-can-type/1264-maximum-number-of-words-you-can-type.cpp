class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        stringstream ss(text);
        string word;
        int cnt=0;

        while(ss>>word){
            string str=word;
            bool pre=true;
            for(auto& it:str){
                if(brokenLetters.find(it)!=string::npos){
                    pre=false;
                    break;
                }
            }
            if(pre) cnt++;
        }

        return cnt;
    }
};