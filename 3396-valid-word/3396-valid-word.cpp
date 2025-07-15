class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;

        string list="aeiouAEIOU";
        int vowel=0;
        int consonant=0;

        for(char& ch:word){
            if(isalpha(ch)){
                if(list.find(ch)!=string::npos){
                    vowel++;
                }else{
                    consonant++;
                }
            }else{
                if(!isdigit(ch)){
                    return false;
                }
            }
        }

        if(vowel<1 || consonant<1){
            return false;
        }
        return true;

    }
};