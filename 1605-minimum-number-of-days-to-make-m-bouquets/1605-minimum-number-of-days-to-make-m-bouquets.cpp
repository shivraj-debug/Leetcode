class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(long long)k*m) return -1;

        int start=*min_element(bloomDay.begin(),bloomDay.end());
        int end=*max_element(bloomDay.begin(),bloomDay.end());

        int ans=-1;

        while(end>=start){
            int mid=start+(end-start)/2;

            if(canmake(mid,m,k,bloomDay)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
    }

    bool canmake(int mid,int m,int k,vector<int>& bloomDay){
        int bouquets = 0;
        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // reset streak if bloomDay[i] > mid
            }
        }

        return bouquets >= m;
    }
};