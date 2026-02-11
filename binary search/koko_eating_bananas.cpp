// problem: 875. Koko Eating Bananas
// difficulty: medium 
// topics:senior staff, array, binary search, weekly contest 
// approach: in this problem we will apply binary search on the range of answers our ans range will be from 1 to max element in the array, and then we will compute mid
// for each low and high, if that mid makes monkey eat all bananas withing h hours then ans can be at left otherwise at right and at last return low,
// time: O(n log m)
// space: O(1)
// link: https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int n = piles.size();
        int high = *max_element(piles.begin(),piles.end());
        while(low<high)
        {
            int mid = low + (high-low)/2;
            int hr = 0;
            for(int i=0;i<n;i++)
            {
                hr += (piles[i] + mid - 1) / mid;

            }
            if(hr>h)
            low = mid+1;
            else
            high = mid;
        }
        return low;
    }
};
