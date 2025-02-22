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
    TreeNode* recoverFromPreorder(string traversal) {
        // Determine the depth by counting the '-'. 
        // Use a map to keep track of the latest node found with each depth. 
        // For a node depth 'k', we attach it to a node depth 'k - 1'.
        vector<TreeNode*> depthMap(1000, nullptr);

        string numString = "";
        int i = 0;

        while (i < traversal.size() && traversal[i] != '-') {
            numString += traversal[i];
            i++;
        }
        int numInt = stoi(numString);

        TreeNode* root = new TreeNode(numInt);
        depthMap[0] = root;

        int dashCount = 0;
        while (i < traversal.size()) {
            if (traversal[i] == '-') {
                dashCount++;
                i++;
                continue;
            } 

            string numString = "";
            while (i < traversal.size() && traversal[i] != '-') {
                numString += traversal[i];
                i++;
            }
            int numInt = stoi(numString);
        
            TreeNode* parent = depthMap[dashCount - 1];
            

            if (parent->left == nullptr) {
                TreeNode* newNode = new TreeNode(numInt);
                parent->left = newNode;
                depthMap[dashCount] = newNode;
            } else {
                TreeNode* newNode = new TreeNode(numInt);
                parent->right = newNode;
                depthMap[dashCount] = newNode;
            }

            dashCount = 0;
        }

        return root;
    }
};