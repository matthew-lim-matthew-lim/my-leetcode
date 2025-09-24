// Last updated: 9/24/2025, 9:37:13 PM
/* 
Recursion.
Track pFound and qFound which track if p and q were found. 
Return the node if pFound and qFound are both true. 
Otherwise return nullptr.
If val is already set, pass that val back. 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* p_;
    TreeNode* q_;
public:
    pair<bool, bool> search(TreeNode* curr, TreeNode* &LCA) {
        bool pFound = false;
        bool qFound = false;
        if (curr->left) {
            auto [ p, q ] = search(curr->left, LCA);
            pFound |= p;
            qFound |= q;
        }
        if (curr->right) {
            auto [ p, q ] = search(curr->right, LCA);
            pFound |= p;
            qFound |= q;
        }
        if (curr == p_) {
            pFound |= true;
        }
        if (curr == q_) {
            qFound |= true;
        }
        if (pFound && qFound && !LCA) {
            LCA = curr;
        }
        return { pFound, qFound };
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        p_ = p;
        q_ = q;
        bool pFound = false;
        bool qFound = false;
        TreeNode* LCA = nullptr;
        search(root, LCA);
        return LCA;
    }
};