// Last updated: 4/27/2026, 9:48:49 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12/* 
13Probably do left + root + right. 
14Or only left
15or only right
16or only root
17or left + root
18or root + right. 
19 */
20class Solution {
21private:
22    int res = -1000;
23
24public:
25    int traverse(TreeNode* root) {
26        if (!root) {
27            return -1000;
28        }
29
30        int left = traverse(root->left);
31        int right = traverse(root->right);
32
33        // cout << left << " " << right << endl;
34
35        // This one needs to be saved in res, because it means 
36        // we can't add anything to the path.
37        res = max(res, left + root->val + right);
38
39        // These two are paths that start/end and don't go through the root.
40        res = max(res, left);
41        res = max(res, right);
42
43        // cout << res << endl;
44
45        return max({root->val + left, root->val + right, root->val});
46    }
47
48    int maxPathSum(TreeNode* root) {
49        res = max(res, traverse(root));
50
51        return res;
52    }
53};