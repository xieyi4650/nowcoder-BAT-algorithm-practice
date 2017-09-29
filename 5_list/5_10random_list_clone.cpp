/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    // 复制节点
    void duplicate(RandomListNode* pHead)
    {
        RandomListNode* idx = pHead;
        while(idx){
            RandomListNode* duplicate_node = new RandomListNode(idx->label);
            duplicate_node->next = idx->next;
            idx->next = duplicate_node;
            idx = duplicate_node->next;
        }
    }

    // 调整复制后的节点的random
    void adjust_dp(RandomListNode* pHead)
    {
        RandomListNode* idx = pHead;
        RandomListNode* duplicate_node = idx->next;
        while(idx){
            duplicate_node = idx->next;
            if(idx->random){
                duplicate_node->random = idx->random->next;
            }
            idx = duplicate_node->next;
        }
    }

    // 分离大链表
    RandomListNode* split_list(RandomListNode* pHead)
    {
        RandomListNode* pHead_dp = pHead->next;
        RandomListNode* idx = pHead, *idx_dp = pHead_dp;
        while(idx->next->next){
            idx->next = idx_dp->next;
            idx_dp->next = idx_dp->next->next;
            idx = idx->next;
            idx_dp = idx_dp->next;
        }
        idx->next = NULL;
        return pHead_dp;
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        // 一定要检查是否为空，坑了我一下午 T_T
        if(!pHead){return NULL;}
        // 复制节点
        duplicate(pHead);
        // 调整复制节点的random指针
        adjust_dp(pHead);
        // 分离复制的链表
        return split_list(pHead);
//        return pHead;
    }
};

