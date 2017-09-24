/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        // write code here
        // 偶数个节点也可以是回文
        ListNode *p1 = pHead, *p2 = pHead;
        stack<int> stk;
        while(p2->next){
            stk.push(p1->val);
            if(p2->next->next){
                p2 = p2->next->next;
                p1 = p1->next;
            }else{
                p2 = p2->next;
            }
        }
        p1 = p1->next;
        while(p1){
            if(p1->val != stk.top()){
                return false;
            }
            p1 = p1->next;
            stk.pop();
        }
        return true;
    }
};

