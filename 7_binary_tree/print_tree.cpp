/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
 
class TreePrinter {
public:
    vector< vector<int> > printTree(TreeNode* root) {
        // write code here
        vector< vector<int> >  results;
        queue<TreeNode *> myq;
        myq.push(root);
        struct TreeNode * temp;
        struct TreeNode * nlast = root;
        struct TreeNode* last  = root;
        vector<int> temp_row;
        while (!myq.empty()) {
            temp = myq.front();
            if (temp->left) {
                myq.push(temp->left);
                nlast = temp->left;
            }
            if (temp->right) {
                myq.push(temp->right);
                nlast = temp->right;
            }
            temp_row.push_back(temp->val);
            if (temp==last) {
                results.push_back(temp_row);
                temp_row.clear();
                last = nlast;
            }
            myq.pop();
        }
        return results;
 
    }
};
