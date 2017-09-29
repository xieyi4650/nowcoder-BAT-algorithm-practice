/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreeToString {
public:
    void preoder(const TreeNode* root, string& res)
    {
        if(NULL == root) {
            res += "#!";
            return;
        }
        res += to_string(root->val) + "!";
        preoder(root->left, res);
        preoder(root->right, res);
    }

    string toString(TreeNode* root) {
        // write code here
        string res;
        preoder(root, res);
        return res;
    }
};

