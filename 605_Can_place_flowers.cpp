class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if (m == 0)
            return n == 0;
        else if (m == 1)
            return n <= 1 - flowerbed[0];
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            --n;
            flowerbed[0] = 1;
        }
        for (int i = 1; i < m - 1; ++i) {
            if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                --n;
                flowerbed[i] = 1;
            }
        }
        if (flowerbed[m-2] == 0 && flowerbed[m-1] == 0) {
            --n;
            flowerbed.back() = 1;
        }            
        return n <= 0;
    }
};