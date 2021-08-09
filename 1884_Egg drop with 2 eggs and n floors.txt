class Solution {
public:
    int twoEggDrop(int n) {
        int floor = 0;
        int moves = 1;
        while (floor < n) 
            floor += moves++;
        return --moves;
    }
};














class Solution {
public:
    int twoEggDrop(int n) {
        return ceil(sqrt(2 * n + 0.25) - 0.5);
    }
};