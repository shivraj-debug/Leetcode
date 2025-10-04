class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxarea=0;
        int area=0;

        while(i<j){
            area=(j-i)*min(height[i],height[j]);

            if(height[i]>=height[j]){
                j--;
            }else{
                i++;
            }

            maxarea=max(maxarea,area);
        }

        return maxarea;
    }
};