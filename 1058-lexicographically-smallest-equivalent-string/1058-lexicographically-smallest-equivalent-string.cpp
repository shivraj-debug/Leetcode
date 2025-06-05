class Solution {
public:
    vector<int> par;

    int find(int x){
        if(par[x]==-1) return x;
        return par[x]=find(par[x]);
    }

    void Union(int X,int Y){
       int  x=find(X);
       int y=find(Y);

        if(x!=y){
            par[max(x,y)]=min(x,y);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
      par.resize(26,-1);

        for(int i=0;i<s1.size();i++){
            Union(s1[i]-'a',s2[i]-'a');
        }

        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=find(baseStr[i]-'a')+'a';
        }

        return baseStr;
    }
};