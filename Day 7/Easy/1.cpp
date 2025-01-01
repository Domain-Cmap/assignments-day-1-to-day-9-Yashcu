class Solution {
public:
    void dfs(TreeNode* node ,string current,vector<string>& ans){
            
            current+=to_string(node->val);

            if(!node->left && !node->right){
                ans.push_back(current);
            }
            current+="->";
            if(node->left) dfs(node->left,current,ans);
            if(node->right) dfs(node->right,current,ans);
            current.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;

    
        dfs(root,"",ans);
        return ans;
    }
};