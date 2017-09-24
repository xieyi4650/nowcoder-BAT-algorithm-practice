/*
   struct ListNode {
   int val;
   struct ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
   };*/
class ChkLoop {
    public:
        int chkLoop(ListNode* head, int adjust) {
            // write code here
            if(!head){return -1;}

            ListNode *p1 = head, *p2 = head;
            while(p2){

                if(p2->next){
                    p2 = p2->next->next;
                }else{
                    return -1;
                }
                p1 = p1->next;
                if(p2 == p1){
                    break;
                }
            }
            if(NULL == p2){
                return -1;
            }
            p2 = head;
            while(p1 != p2){
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1->val;
        }
};

