class Solution {
public:
    bool search(vector<int>& arr, int target) {
         int start = 0;
        int n = arr.size();
        int end = n-1;

        while(start <= end){

            int mid = start+(end-start)/2;

            if(arr[mid] == target){
                return true;
            }

            // for handle duplicates
            if(arr[start]==arr[mid] && arr[end]==arr[mid]){
                start++;
                end--;
            }

            else if(arr[start] <= arr[mid]){  //left side sorted
                if(arr[start] <= target && arr[mid] >= target){
                    end = mid -1;
                }
                else{
                    start = mid + 1;
                }
            }

            else if(arr[end] >= arr[mid]){
                if(arr[mid] <= target && arr[end] >= target){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }

        }
        return false;
    }
};