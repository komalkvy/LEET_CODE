class Solution {
public:
    int n;
    vector<string> getAll(string s){
        int len = s.length();
        vector<string> ans;
        if(s[0] == '0' && len > 1){
            
        }else{
        ans.push_back(s);
        }
        if(len == 1){
            return ans;
        } 
        for(int i = 1; i <= len - 1 ; i++){
            string x1 = s.substr(0,i);
            string x2 = s.substr(i);
            if((x1[0] == '0' && x1.length() > 1) || x2[x2.length() - 1] == '0' ){
                continue;
            }
            string temp = x1  + '.' +  x2;

            ans.push_back(temp);
        }
        return ans;
    }
    vector<string> ambiguousCoordinates(string s) {
        n = s.length();
        vector<string> ans;
        for(int i = 1; i < n-2; i++){
            string f = s.substr(1, i);
            string se = s.substr(i+1, (n-(i+1)) -1);
            vector<string> fAll =  getAll(f);
            vector<string> seAll = getAll(se);
            int l1 = fAll.size();
            int l2 = seAll.size();
            for(int i = 0; i< l1; i++){
                for(int j = 0; j < l2; j++){
                    ans.push_back("(" + fAll[i] + ", " + seAll[j] + ")");
                }
            }

        }
        return ans;
    }
};