class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxarea=0;
        double maxdia=0;


        for(auto& it:dimensions){
            int l=it[0];
            int b=it[1];
            double dia=sqrt(l*l+b*b);
            int area=l*b;

            if(maxdia<dia){
                maxdia=dia;
                maxarea=area;
            }else if(maxdia==dia){
                maxarea=max(area,maxarea);
            }
        }

        return maxarea;
    }
};