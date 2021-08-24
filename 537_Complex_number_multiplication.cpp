class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto pos = num1.find('+');
        int a = stoi(num1.substr(0, pos));
        int b = stoi(num1.substr(pos+1, num1.size()-pos-2));
        pos = num2.find('+');
        int c = stoi(num2.substr(0, pos));
        int d = stoi(num2.substr(pos+1, num2.size()-pos-2));
        int ans_a = a * c - b * d;
        int ans_b = a * d + b * c;
        return to_string(ans_a) + '+' + to_string(ans_b) + 'i';
    }
};