// problem: 315. Count of Smaller Numbers After Self
// topic: array, binary search, divide and conquer, binary index tree, segment tree, merge sort, ordered set.
// difficulty: hard
// approach: in this problem, we will use fenwick tree and coordinate compression and perform order statistic queries. 
// a fenwick tree also called binary indexed tree (BIT) is used to update and compute the prefix sum in an array in logn time 
// coordinate compression is the conversion of large messy values in smaller and much simpler order 
// implementation - we will first make a duplicate array of nums and sort it and remove the duplicates in it by using unique func and erase function
// then we will a vector to store fenwick tree of size dup.size()+1 because we want it to be 1 indexed, and initially store zeroes in it,
// then we will move from right to left becase we want to calculate number of smaller elements at right, 
// now we will compute the rank of current index, by finding the lower bound of nums[i] in our duplicate array, and adding +1 since we are using 1 indexed tree
// then our ith position of result array will become query(bit, rank-1)
// the query() function tells how many elements are there right now in our tree, having rank<=input rank
// its done by computing prefix sum of rank-1, since our tree has frequencies not values so it will give number of elements.
// then we will use update(bit, rank) function to finally update the tree by adding current rank to it for upcoming elements.
// at last we will return our result array.
// time: O(n log n)
// space: O(n)
// link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/

class Solution {
public:
    void update(vector<int> &bit, int i)
    {
        while(i<bit.size())
        {
            bit[i] += 1;
            i += (i&-i);
        }
    }
    int query (vector<int> &bit, int i)
    {
        int sum = 0;
        while(i>0)
        {
            sum += bit[i];
            i -= (i&-i);
        }
        return sum;
    }

    vector<int> countSmaller(vector<int>& nums) {
        
       vector<int> dup = nums;
       int n = nums.size();
       vector<int> result(n);
       
       sort(dup.begin(),dup.end());
       dup.erase(unique(dup.begin(),dup.end()),dup.end());
       vector<int> bit (dup.size()+1, 0);

       for(int i=n-1;i>=0;i--)
       {
        
        auto it = lower_bound(dup.begin(),dup.end(),nums[i]);
        int rank = (it-dup.begin())+1;

        result[i]=query(bit, rank-1);

        update(bit, rank);
       }
       return result;
    }
};
