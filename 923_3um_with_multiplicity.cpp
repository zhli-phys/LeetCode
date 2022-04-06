#define M 1000000007

typedef long long ll;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<int, ll> mp;
        for (int num : arr)
            ++mp[num];
        vector<pair<int, ll>> vec;
        for (auto& p : mp)
            vec.push_back(p);
        ll ans = 0;
        int n = vec.size();
        for (int i = 0; i < n; ++i) {
            auto& vi = vec[i];
            if (vi.first * 3 == target)
                ans += vi.second * (vi.second - 1) * (vi.second - 2) / 6;
            else if (mp.find(target - 2 * vi.first) != mp.end())
                ans += mp[target - 2 * vi.first] * vi.second * (vi.second - 1) / 2;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                if (vec[j].first + vec[k].first == target - vi.first) {
                    ans += vi.second * vec[j].second * vec[k].second;
                    ++j;
                    --k;
                }
                else if (vec[j].first + vec[k].first > target - vi.first) 
                    --k;
                else
                    ++j;
            }
            ans %= M;
        }
        return ans;
    }
};