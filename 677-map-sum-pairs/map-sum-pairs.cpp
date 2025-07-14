class MapSum {
public:
    vector<map<string,int>> V;
    MapSum() { V = vector<map<string,int>>(26,map<string,int>()); }
    
    void insert(string key, int val) { V[key[0] - 'a'][key] = val; }
    
    int sum(string prefix) {
        int s = 0;
        for (auto &m:V[prefix[0]-'a'])
            if (prefix == m.first.substr(0,prefix.size())) s += m.second;
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */