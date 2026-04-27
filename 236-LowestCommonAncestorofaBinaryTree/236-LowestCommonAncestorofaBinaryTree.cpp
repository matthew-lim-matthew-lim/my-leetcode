// Last updated: 4/27/2026, 6:23:05 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10
11/* 
12If we found the node, return YES.
13If left or right returned YES, return YES. 
14If left and right returned YES, we set this node. 
15 */
16class Solution {
17private:
18    TreeNode* p;
19    TreeNode* q;
20    TreeNode* res;
21public:
22    bool dfs(TreeNode* root) {
23        if (!root) {
24            return false;
25        }
26
27        bool thisIsARoot = false;
28        if (root == p || root == q) {
29            thisIsARoot = true;
30        }
31
32        bool l = dfs(root->left);
33        bool r = dfs(root->right);
34
35        if (l && r) {
36            res = root;
37        } else if (thisIsARoot && (l || r)) {
38            res = root;
39        }
40
41        return l || r || thisIsARoot;
42    }
43
44    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
45        this->p = p;
46        this->q = q;
47        dfs(root);
48
49        return res;
50    }
51};