class BSTIterator {
public:
    int n,i;
    vector<int> treeval;
    
    BSTIterator(TreeNode* root) {        
        inorder(root,treeval);
        n=treeval.size();
        i=0;
    }
    
    /** @return the next smallest number */
    int next() {
        i++;
        return treeval[i-1];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(i<n) return true;
        return false;
    }
    
    void inorder(TreeNode* root, vector<int>& treeval){
        if(root==NULL){
            return ;
        }
        inorder(root->left, treeval);
        treeval.push_back(root->val);
        inorder(root->right, treeval);
    }
};
