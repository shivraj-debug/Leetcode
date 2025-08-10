class Solution {
public:
    bool reorderedPowerOf2(int n) {
       string target=arrange(n);

       for(int i=0;i<31;i++){
          if(arrange(1<<i)==target) return true;
       }

       return false;
    }

    string arrange(int n){
        string s=to_string(n);

        sort(s.begin(),s.end());

        return s;
    }

};