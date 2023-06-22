// https://leetcode.com/problems/design-twitter

class Twitter {
public:
    unordered_map<int,unordered_map<int,int>> followers;
    vector<pair<int,int>> tweets;
    
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int> res;
        int cnt=10, i=res.size();

        for(auto it = tweets.rbegin(); it != tweets.rend(); ++it)
        {
            if(cnt==0) break;

            int uid=it->first;

            if(followers[userId][uid]==1 or uid==userId) 
            {
                res.push_back(it->second);
                cnt--;
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId][followeeId]=1;
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId][followeeId]=0;
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
