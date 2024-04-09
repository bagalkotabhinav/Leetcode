class Twitter {
public:

    vector<pair<int,int>> tweets;
    unordered_map<int,unordered_set<int>> following;

    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        this->tweets.push_back({userId,tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(int i=this->tweets.size()-1,count=0;i>=0&&count<10;i--){
            int friendId=this->tweets[i].first;
            if(this->following[userId].count(friendId) || userId==friendId){
                int friendtweetId=this->tweets[i].second;
                ans.push_back(friendtweetId);
                count++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        this->following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        this->following[followerId].erase(followeeId);
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