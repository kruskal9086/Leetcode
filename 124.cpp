class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // Initialize the maximum path sum to the minimum possible value
        int maxSum = INT_MIN;
        // Recursively compute the maximum path sum for the left and right subtrees
        maxPathSumRecursive(root, maxSum);
        // Return the overall maximum path sum
        return maxSum;
    }
    
    // Recursive helper function to compute the maximum path sum
    int maxPathSumRecursive(TreeNode* root, int& maxSum) {
        // Return 0 if the root is null
        if (!root) return 0;
        
        // Compute the maximum path sum of the left and right subtrees
        int leftMaxSum = maxPathSumRecursive(root->left, maxSum);
        int rightMaxSum = maxPathSumRecursive(root->right, maxSum);
        
        // Take the maximum of the current node's value, the left subtree's maximum path sum, and the right subtree's maximum path sum
        int maxPathSum = max(root->val, max(leftMaxSum, rightMaxSum) + root->val);
        
        // Update the overall maximum path sum by taking the maximum of the current maximum path sum and the sum of the left subtree's maximum path sum, the current node's value, and the right subtree's maximum path sum
        maxSum = max(maxSum, max(maxPathSum, leftMaxSum + root->val + rightMaxSum));
        
        // Return the maximum path sum that includes the current node
        return maxPathSum;
    }
};