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
    int minimumOperations(TreeNode* root) {
        // Can traverse by level using a queue, while keeping track of depth. 
        // In each queue, find the number of swaps required. 
        // Make a vector from the queue, which notes the original positions of the nodes in the vector.
        // Sort the vector, then iterate through, counting the number of out of position nodes. 
        // Add these to the count of operations. 
        int operations = 0;

        queue<pair<TreeNode*, int>> q;  // { TreeNode*, depth }
        q.push({ root, 0 });
        
        int prev_level = 1;
        vector<int> level_vals; 
        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front();
            q.pop();

            // Check queue is currently made up of 1 level. 
            cout << "prev_level: " << prev_level << " " << curr.second << endl;
            if (prev_level < curr.second && curr.second >= 1) {
                cout << "entered" << endl;
                prev_level++;

                operations += getMinSwaps(level_vals);

                level_vals.clear();
            }

            if (curr.first == nullptr) {
                break;
            }

            // Add to the level_vals vector
            if (curr.second != 0) level_vals.push_back(curr.first->val);

            // Add the children
            if (curr.first->left != nullptr) q.push({ curr.first->left, curr.second + 1 });
            if (curr.first->right != nullptr) q.push({ curr.first->right, curr.second + 1 });

            if (q.empty()) {
                q.push({nullptr, curr.second + 1});
            }
        }

        return operations;
    }

    int getMinSwaps(vector<int>& original) {
        int swaps = 0;
        vector<int> target = original;
        sort(target.begin(), target.end());

        // Map each value to its current index in `original`
        unordered_map<int, int> pos;
        for (int i = 0; i < original.size(); i++) {
            pos[original[i]] = i;
        }

        // For each position, if the element is not in its sorted place,
        // swap it with the element that should be at that position.
        for (int i = 0; i < original.size(); i++) {
            if (original[i] != target[i]) {
                swaps++;

                // Find where target[i] currently is
                int curPos = pos[target[i]];
                // Update `pos` since we're about to swap
                pos[original[i]] = curPos;

                swap(original[i], original[curPos]);
            }
        }
        return swaps;
    }
};