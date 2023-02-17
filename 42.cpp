class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stacc;
        int ans = 0;
        
        // Forward pass, will look at bounders behind the current element
        for(int i = 0; i < height.size(); i++) {
            int thisHeight = height[i];
            int maxPoppedHeight = INT_MIN;
            // Remove smaller elements from the stack, the last element removed will be the biggest of the smaller elements
            // The current element will only account for (currentElementHeight - lastPoppedElementHeight)
            while(!stacc.empty() && height[stacc.top()] < thisHeight) {
                int thisTop = stacc.top();
                stacc.pop();
                maxPoppedHeight = height[thisTop];
            }
            // At this point, maxPoppedHeight is the greatest height between i and stack.top().
            
            // If we reach the end of stack or there is just no smaller element before current element, continue
            if (stacc.empty() || maxPoppedHeight == INT_MIN) {
                stacc.push(i);
                continue;
            }
            
            int bounder = stacc.top();
            int accountedHeight = height[i] - maxPoppedHeight; // Only account for the excess height
            ans += accountedHeight * (i - bounder - 1);
            stacc.push(i);
        }
        
        stacc = stack<int>();
        
        // Backward pass. Will look at bounders in front of the current element
        for(int i = height.size() - 1; i >= 0; i--) {
            int thisHeight = height[i];
            int maxPoppedHeight = INT_MIN;
            // Remove smaller elements from the stack, the last element removed will be the biggest of the smaller elements
            // The current element will only account for (currentElementHeight - lastPoppedElementHeight)
            while(!stacc.empty() && height[stacc.top()] < thisHeight) {
                int thisTop = stacc.top();
                stacc.pop();
                maxPoppedHeight = height[thisTop];
            }
            // At this point, maxPoppedHeight is the greatest height between i and stack.top().
            
            // If we reach the end of stack or there is just no smaller element before current element, continue
            if (stacc.empty() || maxPoppedHeight == INT_MIN) {
                stacc.push(i);
                continue;
            }
            
            // If the heights are equal, the water between these heights will be double counted (once each in forward and back pass)
            // So in back pass, just don't add it if equal heights
            if (height[stacc.top()] != height[i]) {
                int bounder = stacc.top();
                int accountedHeight = height[i] - maxPoppedHeight; // Only account for the excess height
                ans += accountedHeight * (bounder - i - 1);   
            }
            stacc.push(i);
        }
        
        return ans;
    }
};