class RandomizedSet {
public:

    unordered_map<int,int> mp;
    vector<int> v;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool pre=false;
        if(mp.find(val)==mp.end()){
            pre=true;
             v.push_back(val);
            mp[val]=v.size()-1;

        }

        return pre;
    }
    
    bool remove(int val) {
        bool pre=false;
        if(mp.find(val)!=mp.end()){
            pre=true;
            int idx=mp[val];
            int last=v.back();

            v[idx]=last;
            mp[last]=idx;

            mp.erase(val);
            v.pop_back();

        }

        return pre;
    }
    
    int getRandom() {
        int idx=rand()%v.size();

        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */