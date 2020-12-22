/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/




// Initial Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int findLen(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(findLen(root->left), findLen(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int leftLen = findLen(root->left);
        int rightLen = findLen(root->right);
        if (abs(leftLen - rightLen) > 1) return false;
        return isBalanced(root->left) and isBalanced(root->right);
    }
};




// Efficient method
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair<bool, int> checkBalance(TreeNode* root) {
        if (!root) return {true, 0};
        auto left = checkBalance(root->left);
        auto right = checkBalance(root->right);
        bool balance = left.first and right.first and abs(left.second - right.second) < 2;
        int height = 1 + max(left.second, right.second);
        return {balance, height};
    }
public:
    bool isBalanced(TreeNode* root) {
        return checkBalance(root).first;
    }
};


