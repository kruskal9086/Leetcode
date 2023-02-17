class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long totalSubarrays = 0;
        int n = nums.size();
        int start = 0, end = 0;
        int minCount = 0, maxCount = 0;

        while (end < n) {
            if (nums[end] == minK) {
                minCount++;
            }
            if (nums[end] == maxK) {
                maxCount++;
            }
            end++;

            while (minCount > 0 && maxCount > 0) {
                if (nums[start] == minK) {
                    minCount--;
                }
                if (nums[start] == maxK) {
                    maxCount--;
                }
                start++;
            }

            if (minCount == 0 && maxCount == 0) {
                totalSubarrays += end - start + 1;
            }
        }

        return totalSubarrays;
    }
};
