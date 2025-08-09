class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int cnt = 0;
        int i = 0;

        while (i < n) {
            int maxi = weight[i];
            int j = i;

            bool balanced = false;

            while (j < n) {
                maxi = max(maxi, weight[j]);

                // If last element so far is strictly less than max, we can end shipment
                if (weight[j] < maxi) {
                    balanced = true;
                    cnt++;
                    j++;  // start next shipment after this parcel
                    break;
                }
                j++;
            }

            if (!balanced) break; // can't make any more shipments
            i = j; // move to start of next shipment
        }

        return cnt;
    }
};
