class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        int m = (n / 4) * 4;
        int r = n % 4;
        for (int i = 0; i < m; i += 4) {
            count += read4(buf + i);
            if (count % 4 != 0)
                return count;
        }
        char last[4];
        int remain = read4(last);
        for (int j = 0; j < min(r, remain); ++j) {
            buf[m + j] = last[j];
            ++count;
        }
        return count;
    }
};