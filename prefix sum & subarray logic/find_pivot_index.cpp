// problem: 724. Find Pivot Index
// difficulty: easy
// topic: array, prefix sum.
// approach: we take two variables, Lsum and Rsum to calculate left and right sum at each index or pivot, then we run loop one time to calculate total Rsum at starting 
// then we again start a loop after computing Rsum, and i will become the pivot, Rsum will keep decreasing by Rsum-nums[i] and we will check if Rsum==Lsum, if yes then 
// return i else simply update Lsum to Lsum+nums[i] and keep repeating this until u reach an end.
// if loop ends then return -1.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int Lsum=0;
        int Rsum = 0;
        for(int i=0;i<nums.size();i++)
        Rsum += nums[i];
        for(int i=0;i<nums.size();i++)
        {
            Rsum -= nums[i];
            if(Rsum == Lsum)
            return i;
            Lsum += nums[i];
        }
        return -1;
    }
};
