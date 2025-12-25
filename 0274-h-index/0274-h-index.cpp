class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0;
        int n=citations.size();
        int high=n;

        // if(low>=n) return n;
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(check(mid,citations)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }

        }

        return ans;
    }

    bool check(int mid,vector<int>& citations){
        int cnt=0;

        for(int i=0;i<citations.size();i++){
            if(citations[i]>=mid) cnt++;
        }

        if(cnt>=mid) return true;

        return false;
    }
};
