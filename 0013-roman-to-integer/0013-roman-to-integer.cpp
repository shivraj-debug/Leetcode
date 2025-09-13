class Solution {
public:
    int romanToInt(string s) {

        unordered_map<string,int> mp;

        mp["I"]=1;
        mp["II"]=2;
        mp["III"]=3;
        mp["IV"]=4;
        mp["V"]=5;
        mp["IX"]=9;
        mp["X"]=10;
        mp["XL"]=40;
        mp["L"]=50;
        mp["XC"]=90;
        mp["C"]=100;
        mp["CD"]=400;
        mp["D"]=500;
        mp["CM"]=900;
        mp["M"]=1000;
        
        int res=0;
        for(int i=0;i<s.size();i++){
            string temp="";
            temp+=s[i];
            while(i<s.size() && mp.find(temp)!=mp.end()){
                i++;
                temp+=s[i];
            }

            temp.pop_back();

            i--;

            cout<<mp[temp]<<" ";

            res+=mp[temp];

        }

        return res;
    }
};