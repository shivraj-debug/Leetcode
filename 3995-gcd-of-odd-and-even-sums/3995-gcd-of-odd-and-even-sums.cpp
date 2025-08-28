class Solution {
public:
    int gcdOfOddEvenSums(int n) {
         int odd_sum=0;
         int start=1;

         for(int i=0;i<n;i++){
            odd_sum+=start;
            start+=2;
         }

         int even_sum=0;
         start=2;
         for(int i=0;i<n;i++){
            even_sum+=start;
            start+=2;
         }

         cout<<even_sum<<" "<<odd_sum;

        return __gcd(odd_sum,even_sum);

    }
};