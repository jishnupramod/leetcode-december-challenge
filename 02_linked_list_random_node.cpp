/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
*/




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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int length;
    ListNode* start;
    Solution(ListNode* head) {
        length = 0;
        start = head;
        ListNode* temp = head;
        while (temp) {
            ++length;
            temp = temp->next;
        }
    }

    /** Returns a random node's value. */
    int getRandom() {
        int idx = rand() % length;
        ListNode* temp = start;
        while (idx--)
            temp = temp->next;
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 *
 *


 

// Reservoir Sampling method (Algorithm R by Alan Waterman)
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* start;
    Solution(ListNode* head) {
        start = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* temp = start;
        int scope = 1, currVal = 0;
        while (temp) {
            if (((double)rand() / (RAND_MAX)) < 1.0 / scope)
                currVal = temp->val;
            temp = temp->next;
            ++scope;
        }
        return currVal;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
