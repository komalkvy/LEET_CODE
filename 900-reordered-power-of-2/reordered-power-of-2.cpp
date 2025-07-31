class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string>v;
        string p=to_string(n);
        sort(p.begin(),p.end());
        for(int i=0;i<31;i++){
            long long x=(1LL<<i);
            string s=to_string(x);
            sort(s.begin(),s.end());
            v.push_back(s);
        }
        for(auto it:v){
            if(it==p){
                return true;
            }
        }
        return false;
    }
};