class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> lr(n,1);

        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                lr[i]=lr[i-1]+1;
            }
        }

        vector<int> rl(n,1);

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                rl[i]=rl[i+1]+1;
            }
        }

        int candy=0;
        for(int i=0;i<lr.size();i++){
            candy+=max(rl[i],lr[i]);
        }

        return candy;
    }
};