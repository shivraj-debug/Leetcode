class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;   // bottles you initially drink
        int empty = numBottles; // now you have these many empty bottles

        while (empty >= numExchange) {
            // exchange empty bottles for a new full one
            empty -= numExchange;
            ans++;               // drink the new bottle
            empty++;             // that bottle also becomes empty
            numExchange++;       // exchange requirement increases
        }

        return ans;
    }
};
