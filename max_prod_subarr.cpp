// problem: 152. Maximum Product Subarray
// difficulty: medium
// topic: array, DP
// Approach:
// At each index, we compute the maximum and minimum product of a subarray
// ending at that index. This is necessary because a negative number can
// turn a minimum product into a maximum one.
//
// For index i, we have three choices:
// 1) Start a new subarray: nums[i]
// 2) Extend the previous maximum product: nums[i] * oldMax
// 3) Extend the previous minimum product: nums[i] * oldMin
//
// The maximum of these becomes the new max product ending at i,
// and the minimum becomes the new min product ending at i.
// We store them in oldMax and oldMin to carry forward the state.
// A global variable keeps track of the maximum product seen so far.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/maximum-product-subarray/?source=submission-ac

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxProd=nums[0];
        int oldMax=nums[0],oldMin=nums[0];
        for(int i=1;i<n;i++)
        {

            int newMax = max(nums[i], max(nums[i]*oldMax,nums[i]*oldMin));
            
            int newMin = min(nums[i], min(nums[i]*oldMax,nums[i]*oldMin));
            oldMax = newMax;
            oldMin = newMin;
            maxProd = max(maxProd, oldMax);
            
        } 
        return maxProd;
    }
};
