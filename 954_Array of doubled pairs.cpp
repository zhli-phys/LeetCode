class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> pos;
        map<int, int, greater<int>> neg;
        int countZero = 0;
        for (int num : arr) {
            if (num > 0)
                ++pos[num];
            else if (num < 0)
                ++neg[num];
            else
                ++countZero;
        }
        if (countZero % 2 == 1)
            return false;
        for (auto it = pos.begin(); it != pos.end(); ++it) {
            if (it->second > 0) {
                auto twice = pos.find(2 * it->first);
                if (twice == pos.end() || twice->second < it->second)
                    return false;
                else
                    twice->second -= it->second;
            }
        }
        for (auto it = neg.begin(); it != neg.end(); ++it) {
            if (it->second > 0) {
                auto twice = neg.find(2 * it->first);
                if (twice == neg.end() || twice->second < it->second)
                    return false;
                else
                    twice->second -= it->second;
            }
        }
        return true;
    }
};