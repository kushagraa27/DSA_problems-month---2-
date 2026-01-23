// problem: 1658. Minimum Operations to Reduce X to Zero
// difficulty: medium 
// topic: array, sliding window, prefix sum.
// approach: initially, greedy from both ends seems natural,
// but choosing larger/smaller elements does not guarantee minimum operations.

// instead, we calculate total sum of array.
// if we remove elements summing to x from ends,
// the remaining middle subarray must have sum = total - x.

// so we convert the problem to:
// find the longest subarray with sum = target (where target = total - x).

// if we find such longest subarray of length maxL,
// then minimum operations = nums.size() - maxL.

// edge cases:
// if target == 0 → we must remove all elements → return nums.size().
// if target < 0 → impossible → return -1.
// if no subarray has sum = target → return -1.

// we use sliding window to find longest subarray with sum = target
// because all numbers are positive.

// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s=0;
        for(int x: nums)
        s += x;
        int target = s-x;
        if(target<0) return -1;
        if(target == 0) return nums.size();
        int left=0,maxL=-1,sum=0;
        for(int right=0;right<nums.size();right++)
        {
            sum += nums[right];
            while(sum>target)
            {
                sum -= nums[left];
                left++;
            }
            if(sum == target)
            maxL = max(maxL,right-left+1);

        }
        if(maxL==-1) return -1;
        return nums.size()-maxL;
    }
};
