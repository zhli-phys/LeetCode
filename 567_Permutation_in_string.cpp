class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26);
        int n1 = s1.size();
        for (char ch : s1)
            ++count1[ch - 'a'];
        vector<int> count2(26);
        int n2 = s2.size();
        int i = 0;
        for (int j = 0; j < n2; ++j) {
            int pos = s2[j] - 'a';
            ++count2[pos];
            while (count2[pos] > count1[pos] && i <= j) {
                --count2[s2[i] - 'a'];
                ++i;
            }
            if (j - i + 1 == n1)
                return true;
        }
        return false;
    }
};