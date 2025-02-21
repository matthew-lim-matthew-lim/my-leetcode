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
class FindElements {
public:
    unordered_set<int> vals;
    FindElements(TreeNode* root) {
        // We can just use BFS for this. And use a set to keep track of all the nodes we have.
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            vals.insert(curr->val);

            if (curr->left != nullptr) {
                curr->left->val = 2 * curr->val + 1;
                q.push(curr->left);
            }
            if (curr->right != nullptr){
                curr->right->val = 2 * curr->val + 2;
                q.push(curr->right);
            }
        }
    }
    
    bool find(int target) {
        return vals.contains(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */