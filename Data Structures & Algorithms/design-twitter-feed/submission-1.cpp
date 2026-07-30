class Twitter {
public:
    int t;
    unordered_map<int,unordered_set<int>> followmap;
    unordered_map<int,vector<pair<int,int>>> postmap; //time stamp needed in postmap
    Twitter() {
        t=0;
    }
    
    void postTweet(int userId, int tweetId) {
        postmap[userId].push_back({t++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // need to construct feed forst and then display latest 10

        vector<pair<int,int>> feed=postmap[userId];

        for(auto followee: followmap[userId]){
            for(auto postfromfollowee:postmap[followee]){
                feed.push_back(postfromfollowee);
            }
        }

        sort(feed.begin(),feed.end());

        vector<int> res;
        for(int i=feed.size()-1;i>=0 && res.size()<10;i--){
            res.push_back(feed[i].second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId !=followeeId){
            followmap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId !=followeeId){
            followmap[followerId].erase(followeeId);
        }
    }
};
