// problem: 523. Continuous Subarray Sum
// difficulty: medium 
// topic: array, hash table, prefix sum, math

// Approach:
// If k == 0, we check whether the array contains two consecutive zeros,
// because only then can a subarray of length ≥ 2 have sum 0.
//
// For k != 0, we use prefix sum modulo k and a hashmap.
// The map stores: remainder → earliest index where it occurred.
//
// If two prefix sums have the same remainder modulo k, their difference
// is divisible by k. So at index i, if the same remainder was seen earlier
// at index j and (i - j >= 2), a valid subarray exists.
//
// We initialize remainder 0 at index -1 to handle subarrays starting
// from index 0. We iterate through the array, update the running remainder,
// check the length condition, and store the earliest occurrence only.

// time: O(n)
// space: O(n)
// link: https://leetcode.com/problems/continuous-subarray-sum/?source=submission-ac

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum=0;
        mp[0] = -1;
          if(k==0)
        {
            for(int i=1;i<nums.size();i++)
            {
          if(nums[i]==0 && nums[i-1]==0)
          return true;
            } 
            return false;
        }
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            int rem = sum%k;
            
            if(mp.find(rem)!=mp.end())
            {
                if(i-mp[rem]>=2)
                return true;
            }
            else
            mp[rem] = i;
        }
        return false;
    }
};

