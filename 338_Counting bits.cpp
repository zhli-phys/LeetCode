class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 1)
                bits[i] = bits[i - 1] + 1;
            else
                bits[i] = bits[i >> 1];
        }
        return bits;
    }
};





class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for (int i = 1; i <= num; i++) 
                bits[i] = bits[i >> 1] + (i & 1);
        return bits;
    }
};