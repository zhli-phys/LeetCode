class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++) 
            mp[arr[i]]++;
        vector<int> vec;
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) 
            vec.push_back(it->second);
        sort(vec.begin(), vec.end(), greater<int>());
        int m = vec.size();
        int count = 0;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans++;
            count += vec[i];
            if (count >= (n+1)/2)
                break;
        }
        return ans;
    }
};













class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        int half = arr.size() / 2;
        for (int num : arr)
            ++mp[num];
        vector<int> counts;
        for (auto it = mp.begin(); it != mp.end(); ++it)
            counts.push_back(it->second);
        sort(counts.begin(), counts.end(), greater<int>());
        int sum = 0; 
        int ans = 0;
        for (int count : counts) {
            sum += count;
            ++ans;
            if (sum >= half)
                return ans;
        }
        return ans;
    }
};