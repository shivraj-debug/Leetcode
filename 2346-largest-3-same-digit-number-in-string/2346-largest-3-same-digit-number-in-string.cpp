class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        for(int i=0;i<num.size();i++){
            bool pre=true;
            for(int j=i;j<i+3;j++){
                if(num[i]!=num[j]) {
                    pre=false;
                    break;
                }
            }

            if(pre && i+2<num.size()){
                if(ans.empty() || ans[0]<num[i]){
                    ans.erase();
                    ans=num.substr(i,3);
                }
            }
        }
        return ans;
    }
};