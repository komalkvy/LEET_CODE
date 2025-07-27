class Solution {
public:
    bool isPalindrome(string part){
        string rev=part;
        reverse(part.begin(),part.end());
        if(rev==part){
            return true;
        }
        return false;
    }
    void printPalindrome(string s,vector<string>&res,vector<vector<string>>&ans){
        if(s.size()==0){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(isPalindrome(part)){
                res.push_back(part);
                printPalindrome(s.substr(i+1),res,ans);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        printPalindrome(s,res,ans);
        return ans;
    }
};