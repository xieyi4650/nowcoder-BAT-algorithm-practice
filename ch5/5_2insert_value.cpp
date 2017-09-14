/*
   struct ListNode {
   int val;
   struct ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
   };*/
class InsertValue {
    public:
        // 构造环形链表
        ListNode* make_list(const vector<int> A, const vector<int> nxt)
        {
            struct ListNode *p_start = new ListNode(A[0]);
            struct ListNode *end = p_start;
            struct ListNode *head = p_start;
            int idx = nxt[0];
            while(idx != 0){
                struct ListNode *p_node = new ListNode(A[idx]);
                end->next = p_node;
                end = p_node;
                idx = nxt[idx];
                if(head->val > p_node->val){
                    head = p_node;
                }
            }
            end->next = NULL;
            return head;
        }



        ListNode* insert(vector<int> A, vector<int> nxt, int val) {
            // write code here

            if(A.size()<1){
                return NULL;
            }
            struct ListNode *new_node = new ListNode(val);
            ListNode *head = make_list(A, nxt);
            ListNode *p_curr = head, *p_pre = NULL;

            do{
                if(val < p_curr->val){
                    if(p_pre != NULL){
                        p_pre->next = new_node;
                        new_node->next = p_curr;
                        return head;
                    }else{
                        new_node->next = p_curr;
                        head = new_node;
                        return head;
                    }
                }
                p_pre = p_curr;
                p_curr = p_curr->next;
            }while(p_curr != NULL);
            p_pre->next = new_node;
            new_node->next = NULL;
            return head;
        }
};
