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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int>ans;
        struct TreeNode* curr = root;
       
        while(curr!= nullptr || !stack.empty()){
            while(curr!=nullptr){
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            ans.push_back(curr->val);
            stack.pop();
            curr = curr->right;
        }
        return ans;

        
    }
};