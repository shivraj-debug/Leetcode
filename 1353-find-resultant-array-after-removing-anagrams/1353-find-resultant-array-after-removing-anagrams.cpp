class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        
        ans.push_back(words[0]);

        for(int i=1;i<words.size();i++){
            string s=ans.back();
            sort(s.begin(),s.end());

            string news_sorted=words[i];
            sort(news_sorted.begin(),news_sorted.end());
            string news=words[i];


            if(s==news_sorted){
                continue;
            }else{
                ans.push_back(news);
            }
        }

        return ans;
    }
};