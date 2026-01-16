// problem: 560. Subarray Sum Equals K
// difficulty: medium 
// topic: hash table, array, prefix sum.
// Approach:
// We store the prefix sum (current sum till each index) and its frequency.
// At index i, the sum of any subarray ending at i is:
//     currsum(i) - currsum(j), where j < i.
// If this value equals k, then currsum(j) must be currsum(i) - k.
// So, for each index, we check whether (currsum - k) exists in the map.
// If it exists, we add its frequency to the answer, because each occurrence
// represents a valid subarray ending at the current index.
// We initialize the map with sum 0 having frequency 1 to handle subarrays that start from index 0
// time: O(n)
// space: O(n)
// link: https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution { 
public: 
int subarraySum(vector<int>& nums, int k) { 
    unordered_map<int, int> mp;
    mp[0] = 1; 
    int count = 0,currsum=0;
    for(int x:nums) 
    { 
        currsum += x; 
        if(mp.find(currsum-k)!=mp.end())
        {
            count += mp[currsum-k];
        }
        mp[currsum]++;
    } 
    return count;
    }
};



