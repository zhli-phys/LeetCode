class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        unsigned long long l = stoll(left);
        unsigned long long r = stoll(right);
        int n1 = left.size() / 2;
        int n2 = right.size() / 2 + 1;
        int count = 0;
        vector<string> numbers{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        for (int n = n1; n <= n2; ++n) {
            if (n == 0)
                continue;
            queue<string> q;
            if (n % 2 == 1) {
                for (string& number : numbers)
                    q.push(number);
            }
            else
                q.push("");
            for (int i = 0; i < n / 2; ++i) {
                int len = q.size();
                for (int j = 0; j < len; ++j) {
                    for (string& number : numbers)
                        q.push(number + q.front() + number);
                    q.pop();
                }
            }
            while (!q.empty()) {
                if (check(q.front(), l, r))
                    ++count;
                q.pop();
            }
        }
        return count;
    }
    
    bool check(string& s, unsigned long long l, unsigned long long r) {             
        unsigned long long ll = stoll(s);
        ll *= ll;
        string s2 = to_string(ll);
        return (ll >= l && ll <= r && s2 == string(s2.rbegin(), s2.rend()));
    }
};





















using ull = unsigned long long;

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        ull left_num = stoull(left);
        ull right_num = stoull(right);
        int n1 = max(static_cast<int>(left.size() / 2), 1);
        int n2 = right.size() / 2 + 1;
        int count = 0;
        for (int n = max(n1, n2 - 1); n <= n2; ++n) {
            if (n % 2 == 0) {
                bool flag = false;
                string upper = '1' + string(n / 2, '0');
                ull upper_num = stoull(upper);
                for (ull i = 1; i <= upper_num; ++i) {
                    string i_str = to_string(i);
                    string curr = i_str + string(i_str.rbegin(), i_str.rend());
                    count += check(curr, left_num, right_num, flag);
                    if (flag)
                        break;
                }
            }
            else {
                bool flag = false;
                string upper = '1' + string(n / 2 + 1, '0');
                ull upper_num = stoull(upper);
                for (ull i = 1; i <= upper_num; ++i) {
                    string i_str = to_string(i);
                    string curr = i_str + string(++i_str.rbegin(), i_str.rend());
                    count += check(curr, left_num, right_num, flag);
                    if (flag)
                        break;
                }
            }
        }
        return count;
    }
    
    bool check(string& s, ull left_num, ull right_num, bool& flag) {             
        ull num = stoll(s);
        num *= num;
        string s2 = to_string(num);
        if (num > right_num)
            flag = true;
        return (num >= left_num && num <= right_num && s2 == string(s2.rbegin(), s2.rend()));
    }
};