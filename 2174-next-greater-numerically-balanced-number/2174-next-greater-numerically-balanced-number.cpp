class Solution {
public:
    int nextBeautifulNumber(int n) {
         for(int i=n+1;i<=1224444;i++){
            if(beautiful(i)){
                return i;
            }
         }

         return -1;
    }

    bool beautiful(int i){
        vector<int> freq(10,0);

        while(i>0){
            int rem=i%10;
            freq[rem]++;
            i=i/10;
        }

        for(int i=0;i<10;i++){
            if(freq[i]>0 && freq[i]!=i){
                return false;
            }
        }

        return true;
    }
};