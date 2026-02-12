// problem: 1011. Capacity To Ship Packages Within D Days
// difficulty: medium 
// topic: senior staff, array, binary search, weekly contest
// approach: this is also an example of binary search on answer, our range of answers will be from max of weights to sum of all weights, then we will apply binary search 
// on that range and find the minimum capacity which can satisfy the constraint and reuturn it.
// time: o(n log S)
// space: O(1)
// link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        long long high = accumulate(weights.begin(),weights.end(),0);
        while(low<high)
        {
            int mid = low + (high-low)/2;
            int sum = 0,d=1;
            for(int i =0;i<weights.size();i++)
            {
                if(sum+weights[i]>mid)
                {
                    d++;
                    sum = 0;
                }
                sum += weights[i];
            }
            if(d>days)
            low = mid+1;
            else
            high = mid;
        }
        return low;
    }
};
