// Last updated: 4/27/2026, 1:25:18 AM
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
13For each column, keep a vector. 
14
15Best to traverse in-order.
16 */
17class Solution {
18private:
19    unordered_map<int, vector<int>> colMap;
20    int lowestCol = 0;
21
22public:
23    vector<vector<int>> verticalTraversal(TreeNode* root) {
24        priority_queue<
25            pair<vector<int>, TreeNode*>,
26            vector<pair<vector<int>, TreeNode*>>,
27            greater<>
28        > q;
29        q.push({{0, root->val, 0}, root});
30
31        while (!q.empty()) {
32            auto curr = q.top().second;
33            int row = q.top().first[0];
34            int col = q.top().first[2];
35            q.pop();
36
37            colMap[col].push_back(curr->val);
38            lowestCol = min(lowestCol, col);
39
40            if (curr->left) q.push({{row+1, curr->left->val, col-1}, curr->left});
41            if (curr->right) q.push({{row+1, curr->right->val, col+1}, curr->right});
42        }
43
44        vector<vector<int>> res;
45        for (int i = lowestCol; colMap.contains(i); i++) {
46            res.push_back(move(colMap[i]));
47        }
48
49        return res;
50    }
51};