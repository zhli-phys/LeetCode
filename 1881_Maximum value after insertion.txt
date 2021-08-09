class Solution {
public:
    string maxValue(string n, int x) {
        size_t len = n.size();
        if (n[0] == '-') {
            size_t index = 1;
            while (index < len && n[index] - '0' <= x)
                ++index;
            return n.substr(0, index) + static_cast<char>('0' + x) + n.substr(index);
        }
        else {
            size_t index = 0;
            while (index < len && n[index] - '0' >= x)
                ++index;
            return n.substr(0, index) + static_cast<char>('0' + x) + n.substr(index);
        }
    }
};