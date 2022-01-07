class Solution {
public:
    Solution(ListNode* head) {
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
    
private:
    vector<int> vec;
};
















class Solution {
public:
    Solution(ListNode* head) : head(head) {

    }
    
    int getRandom() {
        auto curr = head;
        int ans = curr->val;
        int n = 1;
        while (curr->next) {
            ++n;
            if (rand() % n == 0)
                ans = curr->next->val;
            curr = curr->next;
        }
        return ans;
    }
    
private:
    ListNode* head;
};