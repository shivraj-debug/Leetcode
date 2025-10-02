class Solution {
public:

    vector<vector<int>> bridges;
    int timer=1;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

       vector<vector<int>> adj(n);

       for(auto& it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

       }

       vector<bool> vis(n,false);
       vector<int> t(n,0);
       vector<int> mint(n,0);

       dfs(0,-1,vis,adj,t,mint);

        return bridges;
       
    }

    void dfs(int node,int parent,vector<bool>& vis, vector<vector<int>>& adj, vector<int>& t,vector<int>& mint){
        vis[node]=true;
        t[node]=mint[node]=timer++;

        for(auto& it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,t,mint);
                // mint[node]=min(mint[node],mint[it]);
                mint[node] = min(mint[node], mint[it]); 

                if(mint[it]>t[node]){
                    bridges.push_back({it,node});
                }
            }else{
                // mint[node]=min(mint[node],mint[it]);
                mint[node] = min(mint[node], t[it]); 
            }
        }
    }
};