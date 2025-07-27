// class Solution {
// public:
//     void countsubs(int ind,string s,vector<string>& words,string subs,set<string>&ans){
//         int n=s.size();
//         if(ind==n){
//             for(auto it:words){
//                 if(it==subs)
//                 {
//                     ans.insert(subs);
//                     return;
//                 }   
//             }
//         }
//         subs.push_back(s[ind]);
//         countsubs(ind+1,s,words,subs,ans);
//         subs.pop_back();
//         countsubs(ind+1,s,words,subs,ans);
//     }
//     int numMatchingSubseq(string s, vector<string>& words) {
//         string subs="";
//         set<string>ans;
//         countsubs(0,s,words,subs,ans);
//         for(auto it:ans){
//             cout<<it<<" "<<endl;
//         }
//         return ans.size();
//     }
// };
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;
        unordered_map<string,int>mpp;
        for(int j=0;j<words.size();j++){
            int ind=0;
            if(mpp.find(words[j])!=mpp.end()){
                count+=mpp[words[j]];
                continue;
            }
            for(int i=0;i<s.size();i++) {
                if(words[j][ind]==s[i]){
                    ind++;
                }
                if(ind==words[j].size()) {
                    mpp[words[j]]=1;
                    count++;
                    break;
                }
            }
            if(ind!=words[j].size()) {
                mpp[words[j]]=0;
            }
        }
        return count;
    }
};