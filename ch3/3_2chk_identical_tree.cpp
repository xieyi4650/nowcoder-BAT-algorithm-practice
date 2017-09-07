/*
   struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
   TreeNode(int x) :
   val(x), left(NULL), right(NULL) {
   }
   };*/

class IdenticalTree {
    public:
        // 广度优先,序列化树,前序遍历
        void serialize_tree(TreeNode* A, string &serial)
        {
            stack<TreeNode*> q;
            q.push(A);
            while(!q.empty()){
                TreeNode* curr = q.top();
                q.pop();
                if(curr){
                    serial += to_string(curr->val) + "!";
                    q.push(curr->right);
                    q.push(curr->left);
                }else{
                    serial += "#!";
                }
            }
        }

        // 前序遍历，递归
        void serialize_tree_R(TreeNode* A, string &serial)
        {
            if(!A){
                serial += "#!";
                return;
            }
            serial += to_string(A->val) + "!";
            serialize_tree_R(A->left, serial);
            serialize_tree_R(A->right, serial);
        }

        // 常规字符串匹配，O(N*M)
        bool compare_str(string A, string B)
        {
            for(int i=0; i<=(A.size()-B.size()); ++i){
                if(A.substr(i, B.size()) == B){
                    return true;
                }
            }
            return false;
        }

        bool chkIdentical(TreeNode* A, TreeNode* B) {
            // write code here
            string a, b;
            // 广度优先，前序遍历，非递归
            // serialize_tree(A, a);
            // serialize_tree(B, b);

            // 前序遍历，递归
            serialize_tree_R(A, a);
            serialize_tree_R(B, b);
            
            // 用自带的find函数查找
            // return a.find(b) == string::npos ? false : true;
            // 用自己写的常规字符串匹配查找
            return compare_str(a, b);
        }
};
