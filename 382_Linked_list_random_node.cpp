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