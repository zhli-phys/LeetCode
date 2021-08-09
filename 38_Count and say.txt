class Solution {
public:
    string countAndSay(int n) {
        string prev = "";
        string curr = "1";
        for (int i = 1; i < n; i++) {
            prev = curr;
            curr = "";
            int len = prev.size();
            int j = 0;
            int count = 0;
            while (j < len) {
                count++;
                if (j == len - 1 || prev[j] != prev[j+1]) {
                    curr += ('0' + count);
                    curr += prev[j];
                    count = 0;
                }
                j++;
            }
        }
        return curr;
    }
};