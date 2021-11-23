class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int upLimit = sqrt(1e5) + 1;
        vector<bool> isPrime(100001, true);
        for (int i = 2; i <= upLimit; ++i) {
            if (!isPrime[i]) 
                continue;
            for (int j = 2 * i; j <= 100000; j += i) {
                isPrime[j] = false;
            }
        }
        vector<int> primes;
        unordered_map<int, int> parent;
        for (int i = 2; i <= 100000; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
                parent[i] = i;
            }
        }
        unordered_map<int, int> len;
        for (int num : nums) {
            if (num == 1)
                continue;
            int prevFactor = -1;
            for (int prime : primes) {
                int currFactor = -1;
                if (num == 1)
                    break;
                if (prime * prime > num) {
                    currFactor = num;
                    num = 1;
                }
                else if (num % prime == 0) {
                    currFactor = prime;
                    while (num % prime == 0)
                        num /= prime;
                }
                if (currFactor > 0) {
                    if (prevFactor < 0)
                        ++len[currFactor];
                    else
                        join(prevFactor, currFactor, parent);
                    prevFactor = currFactor;
                }              
            }
        }
        unordered_map<int, int> comp;
        for (auto it = len.begin(); it != len.end(); ++it) {
            comp[find(it->first, parent)] += it->second;
        }
        int ans = 1;
        for (auto it = comp.begin(); it != comp.end(); ++it)
            ans = max(ans, it->second);
        return ans;
    }
    
    void join(int i, int j, unordered_map<int, int>& parent) {
        parent[find(i, parent)] = find(j, parent);
    }
    
    int find(int i, unordered_map<int, int>& parent) {
        if (parent[i] == i)
            return i;
        else {
            parent[i] = find(parent[i], parent);
            return parent[i];
        }
    }
};