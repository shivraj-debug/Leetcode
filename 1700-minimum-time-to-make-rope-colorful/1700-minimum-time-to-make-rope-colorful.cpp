class Solution {
public:
    int minCost(string c, vector<int>& t) {
        int time=0;
        int prev=0;
        int curr;

        for(int i=0;i<c.size();i++){
            curr=t[i];

            if(i>0 && c[i]!=c[i-1]){
             prev=0;
            }

            time+=min(curr,prev);
            prev=max(prev,curr);


        }

        return time;
    }
};