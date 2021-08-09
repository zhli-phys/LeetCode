class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int front = 0;
        int n = chars.size();
        while (front < n) {
            char ch = chars[front];
            chars[index] = chars[front];
            front++;
            index++;
            int count = 1;
            while (front < n && chars[front] == ch) {
                count++;
                front++;
            }
            if (count > 1) {
                string temp = to_string(count);
                for (char temp_ch : temp) {
                    chars[index] = temp_ch;
                    index++;
                }
            }
        }
        return index;
    }
};