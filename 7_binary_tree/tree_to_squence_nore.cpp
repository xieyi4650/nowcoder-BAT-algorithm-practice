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
        if(NULL == root) return;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* tmp = stk.top();
            stk.pop();
            result.push_back(tmp->val);
            if(NULL != tmp->right) stk.push(tmp->right);
            if(NULL != tmp->left) stk.push(tmp->left);
        }
    }
     
    // 找到以当前点为起始点的，所有的左子树
    void find_left(stack<TreeNode*>& stk, TreeNode* curr)
    {
        if(NULL == curr) return;
        while(NULL != curr){
            stk.push(curr);
            curr = curr->left;
        }
    }
     
    void mid(TreeNode* root, vector<int>& result)
    {
        if(NULL == root) return;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        find_left(stk, curr);
        while(!stk.empty() || NULL != curr){
            TreeNode* tmp = stk.top();
            stk.pop();
            result.push_back(tmp->val);
            curr = tmp->right;
            // 以右子树为当前点，找到当前点的所有的左子树
            find_left(stk, curr);
        }
    }
     
    void post(TreeNode* root, vector<int>& result)
    {
        if(NULL == root) return;
        stack<TreeNode*> stk;
        stk.push(root);
        // 前序遍历，但是，顺序为 父->右->左,最后reverse, 相当于左->右->父
        while(!stk.empty()){
            TreeNode* tmp = stk.top();
            stk.pop();
            result.push_back(tmp->val);
            if(NULL != tmp->left) stk.push(tmp->left);
            if(NULL != tmp->right) stk.push(tmp->right);
        }
        reverse(result.begin(), result.end());
    }
 
    vector<vector<int> > convert(TreeNode* root) {
        // write code here
        vector<vector<int>> result(3);
        pre(root, result[0]);
        mid(root, result[1]);
        post(root, result[2]);
        return result;
    }
};

