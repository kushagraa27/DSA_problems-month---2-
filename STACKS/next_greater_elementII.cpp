// problem: 503. Next Greater Element II
// difficulty: medium 
// topic: array, stack, monotonic stack.
// approach: unlilke using hash map to store the next greater element, here we simply search the next greater element after the current element in array, through monotonic stack and store it in a ans vector since we 
// need the value for all elemnts and not a seperate subset like previous problem, to solve the problem of circular movement, we, instead of moving i from 0 to n, we move it to 0-> 2n, hence by that we can check all
// the elemnts at right easily in a linear way. in this problem out monotonic stack stores the indices instead of values because we are not using hashmaps and storing the result directly in ans array, so to get 
// the required index we store them in stack. even if loop runs from 0 to 2n, we have to push elemnts from 0 to n only in the stack.
// time:O(n)
// space: O(n)
// link: https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<2*n;i++)
        {
            while(!st.empty()&&nums[i%n]>nums[st.top()])
            {
                ans[st.top()]=nums[i%n]; st.pop();
            }
            if(i<n)
            st.push(i);
        }
        return ans;
    }
};

