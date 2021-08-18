class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int netLeft = 0;
        for (char ch : s) {
            if (ch == '(')
                ++netLeft;
            else {
                if (netLeft == 0)
                    ++count;
                else
                    --netLeft;
            }
        }
        count += netLeft;
        return count;
    }
};