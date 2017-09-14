/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ClearValue {
public:
    ListNode* clear(ListNode* head, int val) {
        // write code here
        ListNode *curr = head, *pre = NULL;
        while(curr){
            if(val == curr->val){
                if(curr == head){
                    head = head->next;
                    free(curr);
                    curr = head;
                    pre = head;
                }else{
                    pre->next = curr->next;
                    free(curr);
                    curr = pre->next;
                }
            }else{
                pre = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

