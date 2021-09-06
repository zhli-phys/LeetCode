class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int longestDuration = releaseTimes[0];
        char longestChar = keysPressed[0];
        int n = releaseTimes.size();
        for (int i = 1; i < n; ++i) {
            int currDuration = releaseTimes[i] - releaseTimes[i-1];
            if (currDuration > longestDuration) {
                longestDuration = currDuration;
                longestChar = keysPressed[i];
            }
            else if (currDuration == longestDuration)
                longestChar = max(keysPressed[i], longestChar);
        }
        return longestChar;
    }
};