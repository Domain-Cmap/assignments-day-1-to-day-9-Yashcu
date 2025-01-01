class Solution { 
public: 
    void inorder(TreeNode* node, vector<int>& res) { 
        if (node == nullptr) { 
            return; 
        } 
        inorder(node->left, res); 
        res.push_back(node->val); 
        inorder(node->right, res); 
    } 
    vector<int> inorderTraversal(TreeNode* root) { 
        vector<int> result; 
        inorder(root, result); 
        return result; 
    } 
};