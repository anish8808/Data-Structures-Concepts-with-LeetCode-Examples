// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
// https://leetcode.com/problems/maximum-score-from-removing-stones/description/
#include <bits/stdc++.h>

using namespace std;

/*
        class Twitter {
private:
    int time;
    unordered_map<int , vector<pair<int , int>>>tweetMap;
    unordered_map<int , unordered_set<int>> followerMap;
public:
    Twitter() {
        time =0;
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++ , tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int , int>>pq;

        //add tweets from user itself
        for(auto i : tweetMap[userId])
        {
            pq.push(i);
        }

        //add tweets from folwers of users
        for(auto i : followerMap[userId])
        {
            for(auto it : tweetMap[i])
            {
                pq.push(it);
            }
        }

        vector<int>ans;
        while(!pq.empty() && ans.size()<10)
        {
            auto ele = pq.top();
            pq.pop();
            ans.push_back(ele.second);
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        {
            followerMap[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
    }
};

*/
int main()
{

    return 0;
}