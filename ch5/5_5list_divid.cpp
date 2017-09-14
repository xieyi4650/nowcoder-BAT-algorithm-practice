/*
   struct ListNode {
   int val;
   struct ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
   };*/
class Divide {
    public:
        ListNode* listDivide(ListNode* head, int val) {
            // write code here
            if(NULL == head){
                return NULL;
            }
            ListNode *left_a = NULL, *right_a = NULL;
            ListNode *left_e = NULL, *right_e = NULL;
            // 如果小于就放到左边的链表，如果大于就放到右边的链表
            while(head != NULL){
                if(head->val <= val){
                    if(NULL == left_a){
                        left_a = head;
                        left_e = head;
                    }else{
                        left_e->next = head;
                        left_e = head;
                    }
                }else{
                    if(NULL == right_a){
                        right_a = head;
                        right_e = head;
                    }else{
                        right_e->next = head;
                        right_e = head;
                    }
                }
                head = head->next;
            }
            // 合并两个链表
            if(NULL != left_e){
                if(NULL != right_a){
                    left_e->next = right_a;
                    right_e->next = NULL;
                }
                //cout<< 1 << endl;
                return left_a;
            }else{
                //cout<< 2 << endl;
                return right_a;
            }
        }
};
