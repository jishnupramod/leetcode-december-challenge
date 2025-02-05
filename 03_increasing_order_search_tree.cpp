/*
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 

Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]
 

Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
*/




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
    TreeNode* newRoot = new TreeNode(-1);
    TreeNode* temp = newRoot;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        newRoot->right = new TreeNode(root->val);
        newRoot = newRoot->right;
        inorder(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return temp->right;
    }
};




// O(H) - Recursive stack space complexity solution - Relinking the BST nodes
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
    TreeNode* curr;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        root->left = nullptr;
        curr->right = root;
        curr = curr->right;
        inorder(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode(-1);
        curr = ans;
        inorder(root);
        return ans->right;
    }
};
