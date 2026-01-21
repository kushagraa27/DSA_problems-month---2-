// problem: 1991. Find the Middle Index in Array
// difficulty: easy
// topic: prefix sum, array
// approach: 
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/find-the-middle-index-in-array/description/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
       
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
