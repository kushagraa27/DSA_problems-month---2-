// problem: 61. Rotate List
// difficulty: medium 
// topic: liniked list, two pointers
// approach: it is very simple, 
// first iterate through the list one time and find its length, and connect the last node with head to make it circular,
// then find the tail of the new list after doing roation and break the link after the tail, to find the tail we will simple do lenth-k and that node will be tail.
// if k>length then for that case we use k=k%c to normalize it. also handle the edge cases accordingly.
// time: O(n)
// sapce: O(1)
// link: https://leetcode.com/problems/rotate-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0) return head;
        ListNode* curr = head;
        ListNode* tN = head;
        int c=1;
        while(curr->next!=NULL)
        {
            c++;
            curr=curr->next;
        }
        if(k%c==0) return head;
        curr->next = head;
        int tail = c-(k%c);
        c=1;
        while (c!=tail)
        {
            c++;
            tN = tN->next;
        }
        ListNode* start =tN->next;
        tN->next = NULL;
        return start;
    }
};

