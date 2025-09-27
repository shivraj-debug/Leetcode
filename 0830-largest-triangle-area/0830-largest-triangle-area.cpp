class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double ans=INT_MIN;

        for(int i=0;i<n-2;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n-1;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                for(int k=j+1;k<n;k++){
                    int x3=points[k][0];
                    int y3=points[k][1];

                    double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                    double b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
                    double c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

                    double s=(a+b+c)/2;

                    double area=sqrt(s*(s-a)*(s-b)*(s-c));

                    ans=max(ans,area);

                }
            }
        }

        return ans;
    }
};