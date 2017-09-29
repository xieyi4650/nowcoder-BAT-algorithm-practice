/*
   struct ListNode {
   int val;
   struct ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
   };*/
class KInverse {
    public:
        ListNode* inverse(ListNode* head, int k) {
            // write code here
            int cnt = 1;
            ListNode *first = head, *curr = head, *next_gp = head,
                     *local_curr = head, *pre_end = head, *local_pre=head, *local_nxt = head;
            while(curr){
                if(k == cnt){
                    // 记录第一段需要反转的段前和段后
                    head = curr;
                    next_gp = curr->next;
                    local_pre = next_gp;
                    // 反转内部节点
                    while(local_curr != next_gp){
                        local_nxt = local_curr->next;
                        local_curr->next = local_pre;
                        local_pre = local_curr;
                        local_curr = local_nxt;
                    }
                    // 为下次做准备
                    curr = first;
                    first = next_gp;
                    pre_end = curr;
                }else if(cnt > k && 0 == cnt%k){
                    // 记录段前和段后，并将收尾相连
                    pre_end->next = curr;
                    next_gp = curr->next;
                    local_pre = next_gp;
                    local_curr = first;
                    // 反转内部节点
                    while(local_curr != next_gp){
                        local_nxt = local_curr->next;
                        local_curr->next = local_pre;
                        local_pre = local_curr;
                        local_curr = local_nxt;
                    }
                    // 为下次做准备
                    curr = first;
                    first = next_gp;
                    pre_end = curr;
                }
                curr = curr->next;
                ++cnt;
            }
            return head;
        }
};

