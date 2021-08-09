class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        bool neg = false;
        long a = numerator;
        long b = denominator;
        if (a < 0) {
            a = -a;
            neg = !neg;
        }
        if (b < 0) {
            b = -b;
            neg = !neg;
        }
        long before = a / b;
        a %= b;
        vector<int> after;
        unordered_map<int, int> visited;
        int pos = 0;
        int loop = -1;
        while (loop < 0 && a > 0) {
            a *= 10;
            if (!visited.count(a)) {
                after.push_back(a/b);
                visited[a] = pos;
                pos++;
            }
            else 
                loop = visited[a];
            a %= b;
        }
        string ans;
        if (neg)
            ans.push_back('-');
        ans += to_string(before);
        if (!after.empty()) {
            ans.push_back('.');
            if (loop < 0) {
                for (int i : after)
                    ans += to_string(i);
            }
            else {
                for (int i = 0; i < loop; i++)
                    ans += to_string(after[i]);
                ans += '(';
                for (int i = loop; i < pos; i++)
                    ans += to_string(after[i]);
                ans += ')';
            }
        }
        return ans;
    }
};