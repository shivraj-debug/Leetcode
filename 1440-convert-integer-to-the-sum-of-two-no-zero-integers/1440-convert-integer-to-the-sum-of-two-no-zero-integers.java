class Solution {
    public boolean isValid(int a, int b){
        while(a > 0){
            if(a%10 == 0) return false;
            a /= 10;
        }
        while(b > 0){
            if(b%10 == 0) return false;
            b /= 10;
        }
        return true;
    }
    public int[] getNoZeroIntegers(int n) {
        for(int i=1 ; i<n ; i++){
            if(isValid(i, n-i)){
                return new int[]{i, n-i};
            }
        }
        return new int[]{};
    }
}