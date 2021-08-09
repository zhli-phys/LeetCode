class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        int lenA = 0;
        int lenB = 0;
        while (nodeA) {
            lenA++;
            nodeA = nodeA->next;
        }
        while (nodeB) {
            lenB++;
            nodeB = nodeB->next;
        }
        nodeA = headA;
        nodeB = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++)
                nodeA = nodeA->next;
        }
        else {
            for (int i = 0; i < lenB - lenA; i++)
                nodeB = nodeB->next;
        }
        while (nodeA) {
            if (nodeA == nodeB)
                return nodeA;
            else {
                nodeA = nodeA->next;
                nodeB = nodeB->next;
            }
        }
        return NULL;
    }
};