class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // edge case: empty or single-element input
        if (prices.size() < 2) {
            return 0;
        }

        // initialize the array for storing the maximum profit from 0 to i
        vector<int> max_profit_left(prices.size());
        int min_price_so_far = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            max_profit_left[i] = max(max_profit_left[i - 1], prices[i] - min_price_so_far);
            min_price_so_far = min(min_price_so_far, prices[i]);
        }

        // initialize the array for storing the maximum profit from i to len(prices) - 1
        vector<int> max_profit_right(prices.size());
        int max_price_so_far = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--) {
            max_profit_right[i] = max(max_profit_right[i + 1], max_price_so_far - prices[i]);
            max_price_so_far = max(max_price_so_far, prices[i]);
        }

        // calculate the maximum profit by combining the left and right arrays
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            max_profit = max(max_profit, max_profit_left[i] + max_profit_right[i]);
        }

        return max_profit;
    }
};