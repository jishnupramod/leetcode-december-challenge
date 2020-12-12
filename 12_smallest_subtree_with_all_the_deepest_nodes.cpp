/*
Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is tree consisting of that node, plus the set of all descendants of that node.

Note: This question is the same as 1123: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
 

Constraints:

The number of nodes in the tree will be in the range [1, 500].
0 <= Node.val <= 500
The values of the nodes in the tree are unique.
*/




// Enumerating all possible paths and finding the last common node among the longest paths
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
    int maxPathLen = 0;
    void enumeratePaths(vector<vector<TreeNode*>>& paths, vector<TreeNode*>& path, TreeNode* root) {
        if (!root) return;
        path.push_back(root);
        if (!root->left and !root->right) {
            paths.push_back(path);
            int size = path.size();
            maxPathLen = max(maxPathLen, size);
            path.pop_back();
            return;
        }
        enumeratePaths(paths, path, root->left);
        enumeratePaths(paths, path, root->right);
        path.pop_back();
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<vector<TreeNode*>> paths;
        vector<TreeNode*> path;
        enumeratePaths(paths, path, root);
        vector<vector<TreeNode*>> longestPaths;
        for (vector<TreeNode*> path : paths) {
            if (path.size() == maxPathLen)
                longestPaths.push_back(path);
        }
        int enumPaths = longestPaths.size();
        TreeNode* deepRoot = nullptr;
        int idx = 0, i;
        if (enumPaths == 1) return longestPaths[0].back();
        while (idx < maxPathLen) {
            for (i=0; i<enumPaths-1; ++i) {
                if (longestPaths[i][idx] != longestPaths[i+1][idx])
                    goto out;
            }
            deepRoot = longestPaths[i][idx];
            ++idx;
        }
        out:
        return deepRoot;
    }
};





// Postorder traversal Solution
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
    pair<int, TreeNode*> depth(TreeNode* root) {
        if (!root) return {0, nullptr};
        pair<int, TreeNode*> left = depth(root->left);
        pair<int, TreeNode*> right = depth(root->right);
        int dl = left.first, dr = right.first;
        if (dl == dr)
            return {dl + 1, root};
        if (dl > dr)
            return {dl + 1, left.second};
        return {dr + 1, right.second};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return depth(root).second;
    }
};

