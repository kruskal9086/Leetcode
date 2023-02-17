#include <algorithm>

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> dp(n + 1);
        for (int j = 0; j <= n; j++) {
            dp[j] = j;
        }
        for (int i = 1; i <= m; i++) {
            int prev = i - 1;
            dp[0] = i;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                } else {
                    dp[j] = std::min(prev, std::min(dp[j], dp[j - 1])) + 1;
                }
                prev = temp;
            }
        }
        return dp[n];
    }
};