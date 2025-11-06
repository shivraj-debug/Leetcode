class Solution {
public:
    class DSU{
    public:
        vector<int> parent;

        DSU(int c){
            parent.resize(c+1,-1);
            for(int i=1;i<=c;i++){
            parent[i]=i;
            }
        }

        int find(int x){
            if(parent[x]!=x){
                parent[x]=find(parent[x]);
                
            }
            return parent[x];
        }

        void unite(int x,int y){
            parent[find(x)]=find(y);
        }
    };

    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        for(auto& it:connections){
            dsu.unite(it[0],it[1]);
        }

        unordered_map<int,set<int>> onlineComp;

        for(int i=1;i<=c;i++){
            int root=dsu.find(i);
            onlineComp[root].insert(i);
        }

        vector<bool> online(c+1,true);

        vector<int> result;

        for(auto& it:queries){
            int type=it[0];
            int x=it[1];
            int root=dsu.find(x);

            if(type==1){
                if(online[x]){
                    result.push_back(x);
                }else{
                    if(onlineComp[root].empty()){
                        result.push_back(-1);
                    }else{
                        result.push_back(*onlineComp[root].begin());
                    }
                }
            }
            else if(type==2){
                if(online[x]){
                    online[x]=false;
                    onlineComp[root].erase(x);
                }
                
            }
        }

        return result;
    }
};