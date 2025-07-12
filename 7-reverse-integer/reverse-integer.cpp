class Solution {
public:
    int reverse(int x) {
     long long reversenum=0;
     while(x!=0){
        int temp=x%10;
        x/=10;
        reversenum=reversenum*10+temp;
     }
     if(reversenum>INT_MAX || reversenum<INT_MIN) return 0;
     else return reversenum;
    }
};