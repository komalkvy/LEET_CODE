class Solution {
public:
    bool check(int &id, string &pre){
        if(id>=pre.length()) return false;
        if(pre[id]=='#') return true;
        bool ans = true;//Node Done

        //For Left Branch Of Tree
        while(id<pre.length() and pre[id]!=',') id++;
        ans = ans and check(++id, pre);

        //For Right Branch Of Tree
        while(id<pre.length() and pre[id]!=',') id++;
        ans = ans and check(++id, pre);
        return ans;
    }

    bool isValidSerialization(string preorder){
        int id = 0; check(id, preorder);
        return id!=(preorder.length()-1) ? 0 : 1;
    }
};