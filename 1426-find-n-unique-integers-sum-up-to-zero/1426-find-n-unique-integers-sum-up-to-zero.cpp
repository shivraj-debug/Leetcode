class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2!=0){
            ans.push_back(0);
        }
        int ele=1;
        for(int i=0;i<n/2;i++){
            ans.push_back(ele);
            ans.push_back(-ele);
            ele++;
        }

        return ans;
    }
};