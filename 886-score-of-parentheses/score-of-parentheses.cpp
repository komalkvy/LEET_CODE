class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int count = 0;
        
        for(int i=0; i<s.length()-1; i++){
            if(s[i] == '(' && s[i+1] == ')'){
                ans += pow(2,  count);
                i++;
            } else if(s[i] == '(') {
                count++;
            } else {
                count--;
            }
        }
        
        return ans;
    }
};