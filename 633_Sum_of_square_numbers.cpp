using ll = long long;

class Solution {
public:
    bool judgeSquareSum(int c) {
        ll upLimit = sqrt(c) + 0.00001;
        for (ll i = 0; i <= upLimit; ++i) {
            if (isSquare(c - i * i))
                return true;
        }
        return false;
    }
    
    bool isSquare(ll num) {
        ll root = sqrt(num) + 0.00001;
        if ((root - 1) * (root - 1) == num || root * root == num)
            return true;
        else
            return false;
    }
};











using ll = long long;

class Solution {
public:
    bool judgeSquareSum(int c) {
        ll upLimit = sqrt(c) + 0.1;
        unordered_set<ll> squares;
        for (ll i = 0; i <= upLimit; ++i) {
            ll square = i * i;
            squares.insert(square);
            if (squares.find(c - square) != squares.end())
                return true;
        }
        return false;
    }
};