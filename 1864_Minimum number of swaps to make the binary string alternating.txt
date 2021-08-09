class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int count_zero = 0;
        for (char ch : s) 
            count_zero += (ch == '0');
        if (n % 2 == 0) {
            if (count_zero != n / 2)
                return -1;
            int zero_first = 0;
            for (int i = 0; i < n; ++i)
                zero_first += (s[i] != ('0' + (i % 2)));
            int one_first = 0;
            for (int i = 0; i < n; ++i)
                one_first += (s[i] != ('1' - (i % 2)));
            return min(one_first, zero_first) / 2;
        }
        else {
            if (count_zero == n / 2) {
                int one_first = 0;
                for (int i = 0; i < n; ++i)
                    one_first += (s[i] != ('1' - (i % 2)));
                return one_first / 2;
            }
            else if (count_zero == n / 2 + 1) {
                int zero_first = 0;
                for (int i = 0; i < n; ++i)
                    zero_first += (s[i] != ('0' + (i % 2)));
                return zero_first / 2;
            }
            else
                return -1;
        }
    }
};