//4 ms, 5.8 MB
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        ans += string(num / 1000, 'M');
        num %= 1000;
        if (num >= 900) {
            ans += "CM";
            num -= 900;
        }
        if (num >= 500) {
            ans += 'D';
            num -= 500;
        }
        if (num >= 400) {
            ans += "CD";
            num -= 400;
        }
        ans += string(num / 100, 'C');
        num %= 100;
        if (num >= 90) {
            ans += "XC";
            num -= 90;
        }
        if (num >= 50) {
            ans += 'L';
            num -= 50;
        }
        if (num >= 40) {
            ans += "XL";
            num -= 40;
        }
        ans += string(num / 10, 'X');
        num %= 10;
        if (num >= 9) {
            ans += "IX";
            num -= 9;
        }
        if (num >= 5) {
            ans += 'V';
            num -= 5;
        }
        if (num >= 4) {
            ans += "IV";
            num -= 4;
        }
        ans += string(num, 'I');
        return ans;
    }
};
















//16 ms, 8.6 MB
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        vector<int> values{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int n = values.size();
        for (int i = 0; i < n; ++i) {
            while (num >= values[i]) {
                ans += symbols[i];
                num -= values[i];
            }
        }
        return ans;
    }
};