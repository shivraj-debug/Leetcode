class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        
        vector<int> gap(n+1);

        for(int i=1;i<n;i++){
            gap[i]=startTime[i]-endTime[i-1];
        }
        gap[0]=startTime[0];
        gap[n]=eventTime-endTime[n-1];

        int i=0,j=k;
        int time=0,maxTime=0;

        for(int k=0;k<=n && k<=j;k++){
            time+=gap[k];
        }
        maxTime=max(maxTime,time);

        while(j<n){
            time-=gap[i++];
            time+=gap[++j];
            maxTime=max(maxTime,time);
        }

        return maxTime;
    }
};