class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> todo(26, 0);
        int len = tasks.size();
        for (int i = 0; i < len; i++) 
            todo[tasks[i] - 65]++;
        int ans = 0;
        queue<char> doing;
        while (true) {
            if (doing.size() > n) {
                int temp = doing.front() - 65;
                if (temp >= 0)
                    todo[temp] = - todo[temp];
                doing.pop();
            }
            int next;
            int most = 0;
            int least = 0;
            for (int i = 0; i < 26; i++) {
                if (todo[i] > most) {
                    most = todo[i];
                    next = i;
                }
                if (todo[i] < least)
                    least = todo[i];
            }
            if (most > 0) {
                doing.push(next + 65);
                todo[next]--;
                todo[next] = -todo[next];
                ans++;
            }
            else if (least < 0) {
                doing.push(0);
                ans++;
            }
            else
                break;
        }
        return ans;
    }
};














class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> todo(26, 0);
        int len = tasks.size();
        for (int i = 0; i < len; i++) 
            todo[tasks[i] - 65]++;
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (todo[i] > 0)
                pq.push(todo[i]);
        }
        int ans = 0;
        queue<int> doing;
        while (len > 0) {
            if (doing.size() > n) {
                int done = doing.front();
                doing.pop();
                if (done > 0)
                    pq.push(done);
            }
            if (!pq.empty()) {
                int next = pq.top();
                pq.pop();
                doing.push(next - 1);
                len--;
            }
            else 
                doing.push(0);
            ans++;           
        }
        return ans;
    }
};