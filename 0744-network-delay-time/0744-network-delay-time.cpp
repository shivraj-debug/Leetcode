class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       
       vector<vector<pair<int,int>>> g(n+1);

       for(auto& time:times){
            g[time[0]].push_back({time[1],time[2]});
       }

       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

       pq.push({0,k});

       vector<int> dist(n+1,INT_MAX);

       dist[k]=0;

        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;

            pq.pop();

            for(auto& [nei,w]:g[node]){
                if(dist[nei]>w+wt){
                    dist[nei]=w+wt;
                    pq.push({wt+w,nei});
                }
            }
        }
        int ans=0;

        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }

            ans=max(ans,dist[i]);
        }

        return ans;

       
    }
};