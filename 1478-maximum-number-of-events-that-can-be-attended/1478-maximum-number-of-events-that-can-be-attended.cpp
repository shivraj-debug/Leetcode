class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());

        priority_queue<int,vector<int>,greater<int>> pq;
        
        int last_day=1;

        for(int i=0;i<events.size();i++){
            last_day=max(last_day,events[i][1]);

        }

        int i=0,n=events.size(),res=0;

        for(int day=1;day<=last_day;day++){
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }

            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }

            if(!pq.empty()){
                res++;
                pq.pop();
            }


        }
        return res;
    }
};