class Solution {
public:
    string getPermutation(int n, int k) {
       if(n==1) return "1";

        vector<int> f;
        int fact=1;
        f.push_back(fact);
        
        for(int i=1;i<=n;i++){
            fact*=i;
            f.push_back(fact);
        }

        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }

        string res="";

        rec(n,k,v,f,res);

        return res;
    }

    void rec(int n,int k,vector<int>& v,vector<int> f,string& res){
        if(n==1){
            res+=to_string(v.back());
            return;
        }

        int index=(k/f[n-1]);
        if(k%f[n-1]==0){
             index--;
        }

        res+=to_string(v[index]);

        v.erase(v.begin()+index);

        k-=f[n-1]*index;

        rec(n-1,k,v,f,res);
    }
};