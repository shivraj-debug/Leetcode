class Solution {
public:


    unordered_map < long long , long long  > dp; 

    long long solve(string & s , long long  mask , long long  taken , long long  index ,
    long long  k){

        if(index >= s.size()) return 1; 

        long long curr_state = (index<<27) | (mask<<1) | (taken); 
        if(dp.find(curr_state) != dp.end()) return dp[curr_state];  

        long long  ele = (1 << (s[index]-'a')); 
        long long  new_mask = mask | (ele); 
        long long  cnt = __builtin_popcount(new_mask); 
        long long ans = 0; 
        long long maxi = 0; 

        if(cnt > k){

            ans = 1 + solve(s  , ele , taken , index+1 , k); 
            maxi = max(maxi , ans); 

        }
        else{

            ans = solve(s , new_mask , taken , index+1 , k); 
            maxi = max(maxi , ans); 

        }

        // if taken is allowed we can place anything here 

        if(taken == 1) return dp[curr_state] = maxi; 

        for(int c = 0 ; c < 26 ; c++){

                new_mask = mask | (1<<c); 
                cnt = __builtin_popcount(new_mask); 

                if(cnt > k){

                    ans = 1 + solve(s  , (1<<c) , 1 , index+1 , k); 
                    maxi = max(maxi , ans); 

                }
                else{

                    ans = solve(s , new_mask , 1 , index+1 , k); 
                    maxi = max(maxi , ans); 

                }
        }

        return dp[curr_state] = maxi; 

    }
    int maxPartitionsAfterOperations(string s, int k) {
        return solve(s , 0 , 0 , 0 , k);         
    }
};