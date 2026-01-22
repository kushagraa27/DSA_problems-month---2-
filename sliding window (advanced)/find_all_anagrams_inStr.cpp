// problem: 438. Find All Anagrams in a String
// difficulty: medium 
// topic: string, hash table, sliding window.
// approach: in this problem, its given that all aphabets are lowecase so we can use frequency vector 
// so first of all we will make 2 freq vectors to store the strings and compare them, first we will store all the characters of string 'p' beacse we will use it to compare the window, 
// and we will store its length becase its length = size of the window (must for anagram), this makes the sliding window problem - fixed window size, then we will iterate right pointer from 0 to size of 's',
// and store the frequency of each char in respected frequency vector, and if the window size exceeds the stored size of first string 'p' then we will reduce the frequency of s[left] from the frequency vector,
// and increase the left pointer by 1. if the size of window becomes equal to the size of 'p' and both frequency vectors are equal, then we got our anagram and we store the left index in our ans vector
// keep repeating these steps till the last element of 's' and at last return ans vector.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freq1(26,0), freq2(26,0);
        int left=0;
        int k=p.size();
        for(char c: p)
         freq1[c - 'a']++;
        for(int right=0;right<s.size();right++)
        {
            freq2[s[right] - 'a']++;
            if((right-left+1)>k)
            {
                freq2[s[left] - 'a']--;
                left++;
            }
            if((right-left+1)==k)
            {
            if(freq1==freq2)
            ans.push_back(left);
            }
           
        }
        return ans;
    }
};
