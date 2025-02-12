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
class BSTIterator {
public:
    vector<int> flatTree; 
    int currIndex = -1;

    void traverse(TreeNode* curr) {
        if (curr->left != nullptr) traverse(curr->left);
        flatTree.push_back(curr->val);
        if (curr->right != nullptr) traverse(curr->right);
    }

    BSTIterator(TreeNode* root) {
        traverse(root);
    }
    
    int next() {
        currIndex++;
        return flatTree[currIndex];
    }
    
    bool hasNext() {
        return currIndex + 1< flatTree.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */