class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        queue<string> q;
        string smallest=s;

        vis.insert(s);
        q.push(s);

        while(!q.empty()){
            string curr=q.front();
            q.pop();

            if(curr<smallest){
                smallest=curr;
            }

            string temp=curr;
            for(int i=1;i<temp.size();i+=2){
                temp[i]=(temp[i]-'0'+a)%10+'0';
            }

            if(vis.find(temp)==vis.end()) {
                q.push(temp);
                vis.insert(temp);
            }

            string res=rotate(curr,b);

            if(vis.find(res)==vis.end()) {
                q.push(res);
                vis.insert(res);
            }

        }

        return smallest;
    }

    string rotate(string& curr,int b){
        reverse(curr.begin(),curr.end());
        reverse(curr.begin(),curr.begin()+b);
        reverse(curr.begin()+b,curr.end());

        return curr;
    }
};