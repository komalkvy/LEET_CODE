class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int>rightClosestL(n); //Nearest 'L' on right \U0001f449
        vector<int>lefClosestR(n);  //Nearest 'R' on left \U0001f448

        //Fill the rightClosestL (Right to Left Pass)
        for(int i=n-1;i>=0;i--)
        {
            if(dominoes[i]=='L') rightClosestL[i]=i;
            else if(dominoes[i]=='.')rightClosestL[i]=i<n-1?rightClosestL[i+1]:-1;
            else rightClosestL[i]=-1;
        }

        //Fill the lefClosestR(Left to Right Pass)
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]=='R') lefClosestR[i]=i;//Already decided \U0001f4a5
            else if(dominoes[i]=='.') lefClosestR[i]=i>0 ? lefClosestR[i-1] : -1;  // Balanced forces \U0001f91d
            else lefClosestR[i]=-1; // Stronger force wins \U0001f4aa

        }

        string ans(n,' ');
        for(int i=0;i<n;i++)
        {
        int disRightL=rightClosestL[i] == -1 ? INT_MAX : abs(i-rightClosestL[i]);
        int disLeftR=lefClosestR[i] ==-1 ? INT_MAX : abs(i-lefClosestR[i]);

            if(dominoes[i]!='.') ans[i]=dominoes[i];
            else if(disRightL==disLeftR) ans[i]='.';
            else ans[i]=disRightL<disLeftR ? 'L' : 'R';
        }
        return ans;

    }
};