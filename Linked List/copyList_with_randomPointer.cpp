// problem: 138. Copy List with Random Pointer
// difficulty: medium 
// topics: hash table, linked list
// approach: 
// time: O(n)
// sapce: O(1)
// link: https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* curr = head;
        while(curr!=NULL)
        {
         Node* newNode = new Node(curr->val);
         newNode->next = curr->next;
         curr->next = newNode;
         curr = newNode->next;
        }
        curr = head;
        
        while(curr!=NULL)
        {
            if(curr->random !=NULL)
            curr->next->random = curr->random->next;
            else
            curr->next->random = NULL;
            curr=curr->next->next;
        }
        curr=head;
        Node* copy = curr->next;
        Node* temp = copy;
        while(curr!=NULL)
        {
            curr->next = curr->next->next;
            if(temp->next!=NULL)
            temp->next = temp->next->next;
            curr=curr->next;
            temp=temp->next;
        }
        return copy;
    }
};
