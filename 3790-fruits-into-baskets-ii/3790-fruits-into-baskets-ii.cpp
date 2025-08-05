class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced=0;

        for(int i=0;i<fruits.size();i++){
            bool present=0;
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=fruits[i]){
                    baskets[j]=-1;
                    present=1;
                    break;
                }
            }

            if(present==0) unplaced++;
        }

        return unplaced;
    }
};