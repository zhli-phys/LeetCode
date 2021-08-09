class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dist(len1 + 1);
        for (int i = 0; i <= len1; i++) {
            vector<int> temp(len2 + 1, -1);
            dist[i] = temp;
        }
        return minDistance(word1, word2, dist, 0, 0);
    }
    
    int minDistance(string& word1, string& word2, vector<vector<int>>& dist, int pos1, int pos2) {
        if (dist[pos1][pos2] >= 0)
            return dist[pos1][pos2];
        int len1 = word1.size();
        int len2 = word2.size();
        if (pos1 == len1)
            return len2 - pos2;
        if (pos2 == len2)
            return len1 - pos1;
        int a[3];
        a[0] = minDistance(word1, word2, dist, pos1, pos2 + 1) + 1;
        a[1] = minDistance(word1, word2, dist, pos1 + 1, pos2) + 1;
        if (word1[pos1] == word2[pos2])
            a[2] = minDistance(word1, word2, dist, pos1 + 1, pos2 + 1);
        else
            a[2] = minDistance(word1, word2, dist, pos1 + 1, pos2 + 1) + 1;
        int sol = *min_element(a, a + 3);   
        dist[pos1][pos2] = sol;
        return sol;
    }
};