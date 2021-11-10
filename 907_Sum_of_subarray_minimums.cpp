#define M 1000000007ll

using ll = long long;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int left[n];
        int right[n];
        stack<int> sk;
        for (int i = 0; i < n; ++i) {
            while (!sk.empty() && arr[i] < arr[sk.top()]) 
                sk.pop();            
            if (sk.empty()) 
                left[i] = i + 1;            
            else 
                left[i] = i - sk.top();            
            sk.push(i);
        }
        while (!sk.empty())
            sk.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!sk.empty() && arr[i] <= arr[sk.top()]) 
                sk.pop();
            if (sk.empty()) 
                right[i] = n - i;
            else
                right[i] = sk.top() - i;
            sk.push(i);
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) 
            ans = (ans + static_cast<ll>(arr[i]) * left[i] * right[i]) % M;
        return ans;
    }
};