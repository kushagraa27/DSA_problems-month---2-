// problem: 303. Range Sum Query - Immutable
// difficulty: easy
// topic: array, design, prefixsum
// approach: first i tried brute force approach wehre the contructor takes time O(n) and the sumRange func also takes O(n)
// then in order to optimize sumRange to O(1) i implemented prefix sum.
// in prefix sum method, i calculated prefix sum at all index and stored them in an array, so that in sumRange func the sum simply becomes prefix[right+1]-prefix{left] 
// time: The constructor runs in O(n) time to build the prefix sum array
// Each sumRange query runs in O(1) time using precomputed sums
// space: The space complexity is O(n) due to the prefix sum array
// link: https://leetcode.com/problems/range-sum-query-immutable/description/

class NumArray {
public:
 vector<int> prefix;
    NumArray(vector<int>& nums) {
       prefix.resize(nums.size()+1);
       prefix[0]=0;
       for(int i=0;i<nums.size();i++)
       prefix[i+1] = prefix[i]+nums[i]; 
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1]-prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
