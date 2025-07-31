class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // first sort the array coz its a best among , type question and 
        // now use a 2 pointer coz max limit is 2 per boat 
        // and check if sum of the small and large one 
    sort(people.begin(),people.end());
    int n=people.size();
    int boats=0;
    int i=0;
    int j =n-1;
    while(i<=j){
        if(people[i]+people[j]<=limit){
            i++;
        }
        j--;
        boats++;
    }
    return boats;
    }
};