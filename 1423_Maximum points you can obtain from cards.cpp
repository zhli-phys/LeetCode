class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> front(k+1, 0);
        vector<int> back(k+1, 0);
        int n = cardPoints.size();
        for (int i = 1; i <= k; ++i) {
            front[i] = front[i-1] + cardPoints[i-1];
            back[i] = back[i-1] + cardPoints[n-i];            
        }
        int max_score = 0;
        for (int i = 0; i <= k; ++i) 
            max_score = max(max_score, front[i] + back[k-i]);
        return max_score;
    }
};










//No extra space
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int front_score = 0;
        int back_score = 0;
        for (int i = 0; i < k; ++i)
            front_score += cardPoints[i];
        int max_score = front_score;
        for (int i = 0; i < k; ++i) {
            front_score -= cardPoints[k-i-1];
            back_score += cardPoints[n-i-1];
            max_score = max(max_score, front_score + back_score);
        }
        return max_score;
    }
};