class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t size=haystack.find(needle);
        if(size==string::npos){
            return -1;
        }

        return size;
    }
};