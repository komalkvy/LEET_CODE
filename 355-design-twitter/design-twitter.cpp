class Twitter {
    vector<pair<int,int>> feed;
    unordered_map<int,vector<int>> mp;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        feed.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int n=feed.size(),c=0;
        vector<int> ans;
        while(n>0 && c<10){
            int user=feed[n-1].first;
            int tweet=feed[n-1].second;
            if(user==userId){
                ans.push_back(tweet);
                c++;
            }
            else{
                for(auto &it:mp[userId]){
                    if(it==user){
                        ans.push_back(tweet);
                        c++;
                    }
                    if(c>=10)
                    break;
                }
            }
            n--;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        int f=0;
        for(auto &it:mp[followerId]){
            if(it==followeeId){
                f=1;
                break;
            }
        }
        if(f==0)
        mp[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto &it=mp[followerId];
        for(int i=0;i<it.size();i++){
            if(it[i]==followeeId){
                it[i]=it.back();
                it.pop_back();
                break;
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */