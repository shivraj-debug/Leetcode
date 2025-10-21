class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int end=*max_element(arr.begin(),arr.end());

        for(int i=1;i<end;i++){
            bool pre=false;
            for(int j=0;j<arr.size();j++){
                if(arr[j]==i){
                    pre=true;
                    break;
                }
            }
            if(!pre) k--;

            if(k==0){
                return i;
            }
        }

        return end+k;
    }
};