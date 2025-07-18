class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        int times=0;
        string temp=a;
        while(true)
        {
            if( (1<=a.size() && a.size()<=1e4) && (1<=b.size() && b.size()<=1e4) )
            {
            if(a.find(b)!=-1)
             return times+1;
            else
             {
                a=a+temp;
                times++;
             }
            }
            else 
            {
                return -1;
            }

           
              
        }

        return -1;
        
    }
};