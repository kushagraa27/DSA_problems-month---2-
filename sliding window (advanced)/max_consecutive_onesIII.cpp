// problem: 1004. Max Consecutive Ones III
// difficulty: medium 
// topic: array, binary search, sliding window, prefix sum.
//I use a sliding window where I allow at most k zeros inside the window. I expand the right pointer and count zeros. If the zero count exceeds k, I shrink the window from the left until it becomes valid again.
// At each step, I update the maximum window length.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, Maxnum=0;
        int c=0;
        for(int right=0;right<nums.size();right++)
        {
            if (nums[right]==0)
            c++;
            while(c>k)
            {
                if(nums[left]==0)
                c--;
                left++;
            }
            Maxnum = max(Maxnum,right-left+1);
        }
        return Maxnum;
    }
};



