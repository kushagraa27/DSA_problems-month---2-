// problem: 974. Subarray Sums Divisible by K
// difficulty: medium 
// topic: prefixsum, array, hash table.
// approach: so its almost same pattern as subarray sum equals k, we use prefix sum and hash map here, at each index what we do is compute the prefix sum and then
// compute the remainder of that sum, if its found in hash map then add the frequency of that key to the count variable and increase the frequency of current key by 1 
// we need to normalise the remainder in this case because it can give negative remainders for negative value in cpp, and also we took care of base condition by adding 
// frequency of zero remainder as 1, because if we have only one element like 5, it may give correct output.
// time: O(n)
// space: O(n)
// link: https://leetcode.com/problems/subarray-sums-divisible-by-k/description/?source=submission-ac

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            int rem = ((sum%k)+k)%k;
            if(mp.find(rem)!=mp.end())
            count += mp[rem];
            mp[rem]++;
        }
        return count;
    }
};

