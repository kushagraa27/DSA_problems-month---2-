// problem: 90. Subsets II
// difficulty: medium 
// topic: array, backtracking 
// approach: The goal is to generate all unique subsets of an array that may contain duplicates.

// Step 1: Sort the array
// We sort the array so that duplicate elements are placed next to each other.
// This allows us to detect and skip duplicates easily.

// Step 2: Use backtracking with a loop
// Instead of binary include/exclude recursion, we use a loop-based approach.
// At each recursion level, we:
// - Add the current subset to the answer (because every state is a valid subset)
// - Try to include each element starting from 'start' index

// Step 3: Skip duplicate elements at the same recursion level
// The key line is:
//     if (i > start && nums[i] == nums[i - 1]) continue;
//
// Meaning:
// - If the current element is the same as the previous one
// - And we are at the same recursion depth (i > start)
// - Then skip it to avoid generating duplicate subsets.
//
// Why?
// Because starting two branches at the same level with identical values
// would generate identical subtrees (duplicate subsets).
//
// However, we only skip duplicates at the SAME level.
// In deeper recursion levels, duplicates are allowed.
// This allows subsets like [2,2] to be formed correctly.

// Step 4: Backtracking steps
// For each element in the loop:
// 1. Push nums[i] into the current subset
// 2. Recursively call helper with i + 1 (move forward)
// 3. Pop the element to undo the decision (backtrack)

// Step 5: Recursion continues until all combinations are explored.
//
// Time Complexity:
// In worst case (all elements distinct) → O(n * 2^n)
// With duplicates → fewer branches due to pruning
//
// Space Complexity:
// O(n) recursion stack
// O(n * 2^n) for storing all subsets (output space)
// link: https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    void helper(int index, vector<vector<int>>& ans,const vector<int>& nums,vector<int>& current)
    {
        ans.push_back(current);
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1])
            continue;

            current.push_back(nums[i]);
            helper(i+1,ans,nums,current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> current;
        helper(0,ans,nums,current);
        return ans;
    }
};

