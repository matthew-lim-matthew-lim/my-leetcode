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
public:
    struct nodeInfo {
        int level;
        int x;
        TreeNode* node;
    };

    vector<vector<int>> verticalOrder(TreeNode* root) {
        // Keep track of x coordinate. 
        // Use level-order traversal. 
        queue<nodeInfo> levelQ;

        map<int, vector<int>> orderMap;

        levelQ.push({ 0, 0, root });

        while (!levelQ.empty()) {
            nodeInfo curr = levelQ.front();
            levelQ.pop();
            if (curr.node == nullptr) {
                continue;
            } else {
                orderMap[curr.x].push_back(curr.node->val);
            }

            levelQ.push({ curr.level + 1, curr.x - 1, curr.node->left });
            levelQ.push({ curr.level + 1, curr.x + 1, curr.node->right });
        }

        vector<vector<int>> res;

        for (auto pair : orderMap) {
            res.push_back(pair.second);
        }

        return res;
    }
};