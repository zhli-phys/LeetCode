class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        auto curr = head;
        int n = 0;
        while (curr) {
            curr = curr->next;
            ++n;
        }
        int m = n / k;
        int r = n % k;
        curr = head;
        vector<ListNode*> ans;
        for (int i = 0; i < k; ++i) {
            int len = m;
            if (i < r)
                ++len;
            ans.push_back(curr);
            ListNode* prev = nullptr;
            for (int j = 0; j < len; ++j) {
                if (j == len - 1)
                    prev = curr;
                curr = curr->next;                
            }
            if (prev) 
                prev->next = nullptr;
        }
        return ans;
    }
};