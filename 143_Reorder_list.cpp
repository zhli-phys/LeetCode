class Solution {
public:
    void reorderList(ListNode* head) {
        int n = 0;
        auto curr = head;
        while (curr) {
            ++n;
            curr = curr->next;
        }
        curr = head;
        for (int i = 0; i < (n - 1) / 2; ++i)
            curr = curr->next;
        ListNode* second = reverse(curr->next);
        curr->next = nullptr;
        while (head && second) {
            auto headNext = head->next;
            auto secondNext = second->next;
            head->next = second;
            second->next = headNext;
            head = headNext;
            second = secondNext;
        }
    }
    
    ListNode* reverse(ListNode* curr) {
        if (!curr || !curr->next)
            return curr;
        auto nxt = curr->next->next;
        auto cur = curr->next;
        cur->next = curr;
        curr->next = nullptr;
        while (nxt) {
            auto temp = nxt->next;
            nxt->next = cur;
            cur = nxt;
            nxt = temp;
        }
        return cur;
    }
};











class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        auto curr = head;
        while (curr) {
            vec.push_back(curr);
            curr = curr->next;
        }       
        int n = vec.size();
        if (n <= 2)
            return;
        vec[0]->next = vec.back();
        auto prev = vec.back();
        int i = 1;
        int j = n - 2;
        while (i < j) {
            prev->next = vec[i];
            vec[i]->next = vec[j];
            prev = vec[j];
            ++i;
            --j;
        }
        if (i == j) {
            prev->next = vec[i];
            vec[i]->next = nullptr;
        }
        else
            prev->next = nullptr;
    }
};