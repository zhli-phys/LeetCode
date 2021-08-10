class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int stepsZero = 0;
        int stepsOne = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') 
                stepsOne = min(stepsOne, stepsZero) + 1;
            else {
                stepsOne = min(stepsZero, stepsOne);
                ++stepsZero;
            }
        }
        return min(stepsOne, stepsZero);
    }
};