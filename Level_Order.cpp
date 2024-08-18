/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>>ans;
    if(!A)
        return ans;
    queue<TreeNode*>q;
    q.push(A);
    vector<int>curr;
    
    while(!q.empty()){
        int size = q.size();
        
        while(size--){
            TreeNode* current = q.front();
            q.pop();
            
            curr.push_back(current->val);
            
            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);
        }
        ans.push_back(curr);
        curr.clear();
    }
    return ans;
}
