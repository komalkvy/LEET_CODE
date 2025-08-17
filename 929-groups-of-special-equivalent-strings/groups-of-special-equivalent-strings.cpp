class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_map<string,int>mp;
        for (int i=0;i<words.size();i++){
            string x="",y="";
            for (int j=0;j<words[i].size();j+=2){x+=words[i][j];}
            sort(x.begin(),x.end());
            for (int j=1;j<words[i].size();j+=2){y+=words[i][j];}
            sort(y.begin(),y.end());
            words[i]=x+y;
            mp[words[i]]++;
        }
        return mp.size();
    }
};