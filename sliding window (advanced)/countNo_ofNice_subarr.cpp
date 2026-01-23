// problem: 1248. Count Number of Nice Subarrays
// difficulty: medium 
// topic: array, hash table, math, sliding window, prefix sum.
// approach: we are given k odd numbers that must be present in a subarray.
// first, we convert the array into 0s and 1s using mod 2 (0 = even, 1 = odd),
// so now the problem becomes counting subarrays with sum exactly k.

// directly counting exactly k using sliding window is difficult,
// so we use the identity:
// exactly k = atMost(k) - atMost(k - 1).

// we create a helper function countAtMost(k) that counts subarrays
// having at most k odd numbers using sliding window.

// in countAtMost:
// - expand the right pointer and maintain count of odds
// - if odds exceed k, shrink from left
// - when window is valid (oddCount <= k),
//   add (right - left + 1) to result,
//   because all subarrays ending at 'right' and starting
//   between left and right are valid.

// finally, return:
// countAtMost(k) - countAtMost(k - 1).
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        nums[i] = nums[i]%2;
        return countAtmost(nums,k)-countAtmost(nums,k-1);

    }
    int countAtmost(vector<int>& arr, int k)
    {
       int left = 0,c=0,number=0;
       for(int right=0;right<arr.size();right++)
       {
        if(arr[right]==1)
        c++;
        while(c>k)
        {
            if(arr[left]==1) c--;
            left++;
        }
        number += right-left+1;
       }
       return number;
    }
};


