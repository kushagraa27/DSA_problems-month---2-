// problem: 496. Next Greater Element I
// difficulty: easy 
// topic: array, hash map, stack, monotonic stack
// approach: in this problem we used both stack and hash table, 
// in the second array, we need to find the next greater elemnt to the present element, at its right side and if does not exist then assume it -1, so we use hash map to store the vale and its next greater elemnent
// at right. to do this efficiently we use montonic stack, wehre we push each element one by one, and if we get a value which is greater than top of the stack then we pop the top until it becomes less than the top value
// or stack becomes empty and store it as mp[st.top()] = nums2[i];  in map in that way we will get next greater elemnts in map, and if our iteration is done and there are still nodes left in stack then we will 
// pop them until stack gets empty and store them in map as mp[st.top()]=-1; since their next greater elemnt does not exist, after this we simply iterate through each elemnt of nums1 and store ans[i]=mp[nums1[i]]
// and return ans vector
// time: O(n)
// sapce:O(n)
// link: https://leetcode.com/problems/next-greater-element-i/description/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        int n=nums1.size();
        vector<int> ans(n);
        for(int x:nums2)
        {
            while(!st.empty()&&x>st.top())
            {
                int a=st.top(); st.pop();
                mp[a]=x;
            }
            st.push(x);
        }
        while(!st.empty())
           { mp[st.top()]=-1; st.pop();}
            for(int i=0;i<nums1.size();i++)
            {
                ans[i]=mp[nums1[i]]; 
            }
            return ans;
    }
};
