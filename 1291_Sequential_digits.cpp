class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> lowDigits;
        int num = low;
        while (num > 0) {
            lowDigits.push_back(num % 10);
            num /= 10;
        }
        vector<int> ans;
        int n = lowDigits.size();
        int start = lowDigits.back();
        int curr = 0;
        while (true) {
            if (start + n <= 10) {
                curr = 0;
                for (int i = 0; i < n; ++i) 
                    curr = 10 * curr + start + i;
                if (curr >= low && curr <= high)
                    ans.push_back(curr);
                else if (curr > high)
                    break;
                ++start;
            }
            else {
                ++n;
                start = 1;
                if (n >= 10)
                    break;
            }
        }
        return ans;
    }
};