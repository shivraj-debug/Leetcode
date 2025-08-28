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

        return find_gcd(even_sum,odd_sum);

    }

    int find_gcd(int a,int b){
        if(a==0) return b;
        if(b==0) return a;

        if(a==b ) return a;

        if(a>b) return find_gcd(a-b,b);

        return find_gcd(a,b-a);
    }

};