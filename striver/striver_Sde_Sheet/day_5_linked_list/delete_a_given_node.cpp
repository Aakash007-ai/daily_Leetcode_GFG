class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next && node->next->next){
            int nextVal = node->next->val;
            node->val = nextVal;
            node = node->next; 
        }
        node->val = node->next->val
        node->next = NULL;
    }
};