class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void join(int x,int y){
            int parent_x=find(x);
            int parent_y=find(y);

            if(parent_x==parent_y) return;

            if(rank[parent_x]>rank[parent_y]){
                parent[parent_y]=parent_x;
            }else if(rank[parent_x]<rank[parent_y]){
                parent[parent_x]=parent_y;
            }else{
                parent[parent_x]=parent_y;
                rank[parent_y]++;
            }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
            rank.resize(n,0);
            parent.resize(n);

            for(int i=0;i<n;i++){
                parent[i]=i;
            }

            int cnt=connections.size();

            for(auto& it:connections){
                int x=it[0];
                int y=it[1];

                join(x,y);
            }

            int parent_itself=0;
            for(int i=0;i<n;i++){
                if(parent[i]==i){
                    parent_itself++;
                }
            }

            cout<<cnt<<" ";
            cout<<parent_itself;

            if(n-1>cnt){
                return -1;
            }

            return parent_itself-1;
    }
};