class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int>pre;
        pre.push_back((int)(s[0]-'0'));
        for(int i=1;i<n;i++){
            if(s[i]=='1') pre.push_back(1+pre.back());
            else pre.push_back(pre.back());
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int ones=pre[j];
                if(i!=0) ones-=pre[i-1];
                int zeroes=j-i+1-ones; //j-i+1 is length of sliding window

                //no need to count the difference where it is obvious that it can't be dominant ones substring nevertheless ones or zeroes come
                if(zeroes*zeroes>ones) j+=(zeroes*zeroes-ones-1);  

                if(zeroes*zeroes<=ones) ans++;

                if(zeroes*zeroes<ones){
                    int diff=sqrt(ones)-zeroes;
                    if(j+diff>=n) ans+=n-j-1;
                    else ans+=diff;
                    j+=diff;//no need to count the difference where it is obvious that it will m be dominant ones substring nevertheless ones or zeroes come
                }                
            }
        }
        return ans;
    }
};