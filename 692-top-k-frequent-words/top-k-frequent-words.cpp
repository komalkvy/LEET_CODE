class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto ele:words){
            mp[ele]++;
        }
        int mx = 0;
        vector<string>ans;
        vector<pair<int,string>>v;
        for(auto ele:mp){
            v.push_back({ele.second,ele.first});
        }
        sort(v.begin(),v.end(),[&](auto a,auto b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        });
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};