// problem: 234. Palindrome Linked List
// difficulty: easy
// topic: linked list, two pointers, stack, recursion.
// approach: in this problem first i used stack approach which took space complexity of - O(n)
// then to optimize it further we first moved slow and fast pointer, and when slow reaches the middle node, and after considering both odd and even lenth of the list, we then will reverse the second half of the list
// then we will take 2 pointers, first on starting from head, and next one from the starting of second half, and compare them one by one, if at any point they are not equal then return false else at last return true
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            //st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast != NULL)
        slow = slow->next;
        ListNode *prev = NULL;
        ListNode *curr = slow; 
        while(curr!=NULL)
        {
            ListNode *next= curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode *p1=prev;
        ListNode *p2 = head;
        while(p1!=NULL)
        {
            if(p1->val!=p2->val)
            return false;
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }
};
