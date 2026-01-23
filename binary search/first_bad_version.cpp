// problem: 278. First Bad Version
// difficulty: easy 
// topic: binary search, interactive 
// approach: in this problem, we are using binary search, therefore we need 3 pointers - high, mid, low. we are given n (length of array) so first we will set high = n and low=0, then we will set mid as low+(high-low)/2
// and check, if mid is a bad version (using api), if yes that means first faulty probduct is at left side therefore set high as mid. and if its not a bad version means first bad version is at right side, therefore 
// set low as mid+1 and keep repeating these steps while low is smaller than high.
// at last return the value of low.
// time: O(log n)
// space: O(1)
// link: https://leetcode.com/problems/first-bad-version/description/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int high=n,low=0;
        while(low<high)
        {
            int mid = low+ (high-low)/2;
            if(isBadVersion(mid))
            high = mid;
            else
            low = mid+1;
        }
        return low;
    }
};

