class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr(n, 0);
        string ans = "";
        for(int i = 1; i <= n; i++) {
            arr[i-1] = i;
        }

        for(int i = 1; i < k; i++) {
            next_permutation(arr.begin(), arr.end());
        }

        for(int i = 0; i < arr.size(); i++) {

            ans.push_back(arr[i]+'0');
        }

        return ans; 
    }
};