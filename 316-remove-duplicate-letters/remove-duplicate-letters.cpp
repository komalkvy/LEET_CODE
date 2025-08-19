class Solution {
public:
//We must keep the relative order of characters from the original string
//and then consider lexicographical order
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>freq; 
        unordered_set<char>visited; //maintain elements stored in stack so we dont have to traverse stack each time
        stack<char>st; //store current chars in order
        for(int i=0;i<s.size();i++){
            freq[s[i]]++; //freq of each char
        }
        for(int i=0;i<s.size();i++){
            freq[s[i]]--; //reduce freq left of current char
            if(visited.find(s[i])!=visited.end())continue; //already in stack
            while(st.size() && st.top()>s[i] && freq[st.top()]>=1){ //smaller char found and top has still freq left ahead
                visited.erase(st.top()); //keep removing top
                st.pop();  
            }
            st.push(s[i]); //add current char
            visited.insert(s[i]);
        }
        string ans="";
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end()); //in ascending order
        return ans;
    }
};