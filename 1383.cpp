#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> players;
        for (int i = 0; i < n; i++) {
            players.emplace_back(efficiency[i], speed[i]);
        }

        // Sort the players based on efficiency 
        sort(players.begin(), players.end(), [](auto& p1, auto& p2) {
            return p2.first < p1.first;
        });

        // Priority-Queue to maintain players with highest relative speeds 
        priority_queue<int, vector<int>, greater<int>> speedQueue;
        long teamPerformance = 0, teamSpeed = 0;

        for (int i = 0; i < n; i++) {
            // a team can have at most `k` players.
            if (speedQueue.size() >= k) {
                teamSpeed -= speedQueue.top();
                speedQueue.pop();
            }
            speedQueue.push(players[i].second);
            teamSpeed += players[i].second;

            teamPerformance = max(teamPerformance, teamSpeed * players[i].first);
        }
        return teamPerformance % 1000000007;
    }
};
