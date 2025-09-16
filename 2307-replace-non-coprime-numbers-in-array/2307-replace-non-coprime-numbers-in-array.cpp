class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        st.push(nums[0]);

        for(int i=1;i<nums.size();i++){
            int y=nums[i];
            while(!st.empty()){
                int top=st.top();

                int gcd=__gcd(top,y);
                if(gcd>1){
                    st.pop();
                    y=(top/gcd)*y;
                }else{
                    break;
                }
            }
            st.push(y);
        }

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};