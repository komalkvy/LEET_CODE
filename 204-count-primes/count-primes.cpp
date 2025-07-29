class Solution {
public:
    int countPrimes(int n) {
        vector<int>primes(n);
        for(long long i=2;i<n;i++){
            //if(i*i>n) break;
            for(long long j=i*i;j<n;j+=i){
                primes[j] = 1;
            }
        }
        int count = 0;
        for(int i=2;i<n;i++){
            if(primes[i]==0) count++;
        }
        return count;
    }
};