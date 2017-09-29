/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreeToSequence {
public:
    void pre(TreeNode* root, vector<int>& result)
    {
        if(NULL == root){
            return;
        }
        result.push_back(root->val);
        pre(root->left, result);
        pre(root->right, result);
    }
    void mid(TreeNode* root, vector<int>& result)
    {
        if(NULL == root){
            return;
        }
        pre(root->left, result);
        result.push_back(root->val);
        pre(root->right, result);
    }
    void post(TreeNode* root, vector<int>& result)
    {
        if(NULL == root){
            return;
        }
        pre(root->left, result);
        pre(root->right, result);
        result.push_back(root->val);
    }
    vector<vector<int> > convert(TreeNode* root) {
        // write code here
        vector<vector<int>> res;
        pre(root, res[0]);
        mid(root, res[1]);
        post(root, res[2]);
        return res;
    }
};
