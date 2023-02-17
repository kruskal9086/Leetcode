class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int z= n+m;
        vector<int>nums3(n+m);
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums3.begin());
        if(z%2 != 0)
            return (double) nums3[z/2];
        else
            return (double) (nums3[(z-1)/2]+nums3[(z/2)])/2;
    }
};