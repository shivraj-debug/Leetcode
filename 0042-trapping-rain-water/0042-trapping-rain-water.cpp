class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left_max=height[0];
        int right_max=height[n-1];

        int l=0;
        int r=n-1;
        int res=0;

        while(l<r){
            if(left_max<right_max){
                l++;
                left_max=max(left_max,height[l]);
                res+=left_max-height[l];
            }else{
                r--;
                right_max=max(right_max,height[r]);
                res+=right_max-height[r];
            }
        }

        return res;
    }
};