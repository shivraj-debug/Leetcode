class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans="";
        unordered_map<int,int> mp;

        if(numerator==0) return "0";

        if(1ll*numerator*denominator<0){
            ans+='-';
        }

        long long den=labs(denominator);
        long long num=labs(numerator);
       
        long long digit=num;
        digit=digit/den;
        long long rem=num%den;
        
        ans+=to_string(digit);
        if(rem==0){
            return ans;
        }

        ans+=".";

        while(rem!=0){
            if(mp.find(rem)!=mp.end()){
                ans.insert(mp[rem],"(");
                ans+=")";
                break;
            }

            mp[rem]=ans.length();
            rem*=10;
            int div=rem/den;
            ans+=to_string(div);
            rem=rem%den;

        }

        return ans;

    }
};