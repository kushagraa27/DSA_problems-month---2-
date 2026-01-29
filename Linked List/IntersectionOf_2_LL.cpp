// problem: 160. Intersection of Two Linked Lists
// difficulty: easy 
// topic: hash table, linked list, two pointers
// approach: brute force approach will take O(n^2) time so we will use another approach
// in the optimized approach, we took two pointers having values of headA and headB respectively
// then while the value of p1 and p2 is not same, we will iterate them node by node, and when p1 reaches null then we will assign headB to it and same with p2. if both lists intersect, they will come to same node,
// and if not then at lasty both will become NULL. return the resultant node (either p1 or p2).
// time: O(m+n).
// space: O(1)
// link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        while(p1!=p2)
        {
            p1= (p1==NULL)? headB: p1->next;
            p2= (p2==NULL)? headA: p2->next;
        }
         return p1;
    }
};

