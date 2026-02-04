// Design Twitter
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;
class Twitter {
    public:
    
    unordered_map<int, unordered_set<int> > following;
    unordered_map<int, vector<pair<int,int>> > tweet_post;
    int times;

    Twitter() {
        times=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet_post[userId].push_back({times,tweetId});
        times++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        
        // 我自己
        for(auto& mine:tweet_post[userId])
        {
            pq.push(mine);
        }
        // 我追蹤的人
        for(auto& people:following[userId])
        {
            for(auto& post:tweet_post[people])
            {
                pq.push(post);
            }
        }
        
        vector<int> result;
        int t=0;
        while(!pq.empty() && t<10)
        {
            result.push_back(pq.top().second);
            pq.pop();
            t++;
        }
        
        return result;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId) following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

// Twitter* obj = new Twitter();
// obj->postTweet(userId,tweetId);
// vector<int> param_2 = obj->getNewsFeed(userId);
// obj->follow(followerId,followeeId);
// obj->unfollow(followerId,followeeId);

