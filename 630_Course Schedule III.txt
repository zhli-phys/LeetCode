bool mySmaller(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), mySmaller);
        int curr = 0;
        priority_queue<int> pq;
        for (auto&& course : courses) {
            if (curr + course[0] <= course[1]) {
                pq.push(course[0]);
                curr += course[0];
            }
            else {
                if (!pq.empty() && pq.top() > course[0]) {
                    curr += (course[0] - pq.top());
                    pq.pop();
                    pq.push(course[0]);
                }
            }
        }
        return pq.size();
    }
};