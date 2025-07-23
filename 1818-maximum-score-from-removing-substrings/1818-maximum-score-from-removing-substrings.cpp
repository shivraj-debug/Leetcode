class Solution {
public:
    int maximumGain(string s, int x, int y) {
        bool f;
        if(x>y) f=1;
        else f=0;

        vector<char> v1,v2;
        int cnt=0;

        for(auto& a:s){
            if(!v1.empty()){
                if(f){
                    if(v1.back()=='a' && a=='b'){
                         cnt+=x;
                         v1.pop_back();
                    }else{
                        v1.push_back(a);
                    }
                }else{
                    if(v1.back()=='b' && a=='a'){
                        cnt+=y;
                        v1.pop_back();
                    }else{
                        v1.push_back(a);
                    }
                }
            }else{
                v1.push_back(a);
            }
        }
        for(auto& a:v1){
            if(!v2.empty()){
                if(!f){
                    if(v2.back()=='a' && a=='b'){
                         cnt+=x;
                         v2.pop_back();
                    }else{
                        v2.push_back(a);
                    }
                }else{
                    if(v2.back()=='b' && a=='a'){
                        cnt+=y;
                        v2.pop_back();
                    }else{
                        v2.push_back(a);
                    }
                }
            }else{
                v2.push_back(a);
            }
        }

        return cnt;
    }
};