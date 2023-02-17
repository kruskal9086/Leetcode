class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpet, int carpetLen) {
        int N = floor.size(), sum = 0;
        std::vector<int> cover(N);
        for (int i = 0, white = 0; i < N; ++i) {
            sum += floor[i] - '0';
            white += floor[i] - '0';
            if (i - carpetLen >= 0) white -= floor[i - carpetLen] - '0'; 
            cover[i] = white;
        }
        vector<vector<int>> dp(numCarpet + 1, std::vector<int>(N + 1));
        for (int i = 1; i <= numCarpet; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j + 1] = max(dp[i][j], (j - carpetLen + 1 >= 0 ? dp[i - 1][j - carpetLen + 1] : 0) + cover[j]);
            }
        }
        return sum - dp[numCarpet][N];
    }
};