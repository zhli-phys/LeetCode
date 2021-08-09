class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<int> avaliable;
        vector<int> counts(k);
        for (int i = 0; i < k; i++) {
            avaliable.insert(i);
            avaliable.insert(i + k);
        }
        int n = arrival.size();
        for (int i = 0; i < n; i++) {
            int server = i % k;
            while (!pq.empty() && pq.top().first <= arrival[i]) {
                avaliable.insert(pq.top().second);
                pq.pop();
            }
            set<int>::iterator it = avaliable.lower_bound(server);
            if (it != avaliable.end()) {
                server = (*it) % k;
                //cout << i << server << endl;
                avaliable.erase(server);
                avaliable.erase(server + k);
                counts[server]++;
                pq.push(pair<int, int>(arrival[i] + load[i], server));
                pq.push(pair<int, int>(arrival[i] + load[i], server + k));
            }
        }
        int max_count = *max_element(counts.begin(), counts.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            //cout << i << counts[i] << endl;
            if (counts[i] == max_count)
                ans.push_back(i);
        }
        return ans;
    }
};