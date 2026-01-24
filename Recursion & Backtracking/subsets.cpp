// problem: 78. Subsets
// difficulty: medium 
// topic: array, backtracking, bit manipulation.
// Approach:
// We create a helper function that performs recursion and backtracking.
// The helper function takes:
// - the current index (to track which element we are deciding about)
// - the current subset vector (stores chosen elements so far)
// - the answer vector (stores all subsets)
// - the input array nums

// At each index, we have two decisions:
// 1. Include nums[index]
// 2. Exclude nums[index]

// Include decision:
// - Push nums[index] into the current subset
// - Recursively call helper with index + 1 to process the next element

// Base case:
// - When index == nums.size(), it means we have made decisions
//   for all elements
// - Push the current subset into the answer vector
// - Return to the previous recursive call

// Backtracking step:
// - After returning from the include branch,
//   pop the last element from current to undo the decision

// Exclude decision:
// - Call helper(index + 1) again without including nums[index]

// By exploring both include and exclude branches at every index,
// we generate all possible combinations (2^n subsets).

// time: O(n.2^n)
// space: O(n.2^n)
// link: https://leetcode.com/problems/subsets/description/

class Solution {
public:
    void helper(int index, vector<vector<int>>& ans, vector<int>& current,const vector<int>& nums)
    {
        if(index == nums.size())
        {
            ans.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        helper(index+1,ans,current,nums);

        current.pop_back();
        helper(index+1,ans,current,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        helper(0,ans,current,nums);
        return ans;
    }
};

