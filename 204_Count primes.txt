class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        for (int i = 2; i < n; i++) {
            bool isprime = true;
            double sq = sqrt(i);
            for (int prime : primes) {
                if (i % prime == 0) {
                    isprime = false;
                    break;
                }
                else if (prime > sq)
                    break;
            }
            if (isprime)
                primes.push_back(i);
        }
        return primes.size();
    }
};




class Solution {
public:
    int countPrimes(int n) {
        vector<int> isprime(n, true);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isprime[i]) {
                count++;
                int up = (n-1)/i;
                for (int j = 2; j <= up; j++) 
                    isprime[i*j] = false;
            }
        }
        return count;
    }
};






class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;
        vector<bool> is_prime(n, true);
        is_prime[0] = false;
        is_prime[1] = false;
        int sq = static_cast<int>(sqrt(n) + 0.01);
        for (int i = 2; i <= sq; ++i) {
            if (is_prime[i]) {
                for (int j = 2 * i; j < n; j += i) 
                    is_prime[j] = false;
            }
        }
        return accumulate(is_prime.begin(), is_prime.end(), 0);
    }
};