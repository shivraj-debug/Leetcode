class Solution {
public:
    string minWindow(string s, string t) {
           if(t.length() > s.length()) return "";
        unordered_map <char, int> map;
        for(int i = 0; i < t.length(); i++ ){
            ++map[t[i]];
        }

        int left = 0, right = 0, head = INT_MAX, len = INT_MAX, count = map.size();

        while(right < s.length()){
            char rightChar = s[right];
            if(map.find(rightChar) != map.end()){
                if(--map[rightChar] == 0) count --;
            }

            while(count == 0){  // here we already find the window that contains the targeted substring
                // do 
               if(right - left < len){
                    head = left;
                    len = right - left+1;
                }

                // increment
                char leftChar = s[left];
                if (map.find(leftChar)!= map.end()){
                    if(++map[leftChar] > 0){
                        count++;
                    }
                }       
                left ++;
            }
            right++;
        }

        if(len == INT_MAX) return "";
        return s.substr(head, len); 
    }
};