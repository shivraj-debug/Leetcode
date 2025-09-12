class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0,totalcost=0;

        for(int i=0;i<gas.size();i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
        }

        if(totalcost>totalgas) return -1;

        int current_gas=0;
        int idx=0;

        for(int i=0;i<gas.size();i++){
            current_gas+=gas[i]-cost[i];

            if(current_gas<0){
                current_gas=0;
                idx=i+1;

            }
        }

        return idx;
    }
};