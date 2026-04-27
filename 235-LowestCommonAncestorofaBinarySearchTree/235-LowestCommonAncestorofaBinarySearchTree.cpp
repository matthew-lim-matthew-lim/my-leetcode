// Last updated: 4/27/2026, 6:27:25 PM
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
11class Solution {
12private:
13    TreeNode* p;
14    TreeNode* q;
15    TreeNode* res;
16public:
17    bool dfs(TreeNode* root) {
18        if (!root) {
19            return false;
20        }
21
22        bool thisIsARoot = false;
23        if (root == p || root == q) {
24            thisIsARoot = true;
25        }
26
27        bool l = dfs(root->left);
28        bool r = dfs(root->right);
29
30        if (l && r) {
31            res = root;
32        } else if (thisIsARoot && (l || r)) {
33            res = root;
34        }
35
36        return l || r || thisIsARoot;
37    }
38
39    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
40        this->p = p;
41        this->q = q;
42        dfs(root);
43
44        return res;
45    }
46};