class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2) return n;

        int result=0;

        for(int i=0;i<n;i++){
            int duplicate=1;
            int currmax=0;
            int vertical=0;

            unordered_map<double,int> slope;

            for(int j=i+1;j<n;j++){
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];

                if(dx==0 && dy==0) duplicate++;
                else if(dx==0){
                    vertical++;
                    currmax=max(currmax,vertical);
                }else{
                    double curr_slope=(double)dy/dx;
                    slope[curr_slope]++;
                    currmax=max(currmax,slope[curr_slope]);
                }

            }

            result=max(result,currmax+duplicate);
        }

        return result;

    }
};