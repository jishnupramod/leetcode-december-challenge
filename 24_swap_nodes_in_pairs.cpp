/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes. Only nodes itself may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
*/




// O(n) time and O(1) space
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
    ListNode* swapPairs(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* prev = head, *curr = prev->next, *nxt = curr->next, *newHead = curr;
        while (curr) {
            curr->next = prev;
            if (nxt and nxt->next) {
                prev->next = nxt->next;
                curr = nxt->next;
                prev = nxt;
                nxt = curr->next;
            }
            else {
                prev->next = nxt;
                break;
            }
        }
        return newHead;
    }
};

