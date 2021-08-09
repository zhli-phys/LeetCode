/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        return findCelebrity(0, n);
    }
    
    int findCelebrity(int left, int right) {
        if (left == right - 1)
            return left;
        int mid = (left + right) / 2;
        int c1 = findCelebrity(left, mid);
        int c2 = findCelebrity(mid, right);
        if (c1 < 0 && c2 < 0)
            return -1;
        else if (c1 < 0) {
            for (int i = left; i < mid; i++) {
                if (!knows(i, c2) || knows(c2, i))
                    return -1;
            }
            return c2;
        }
        else if (c2 < 0 || knows(c2, c1)) {
            for (int i = mid; i < right; i++) {
                if (!knows(i, c1) || knows(c1, i))
                    return -1;
            }
            return c1;
        }
        else {
            if (knows(c1, c2)) {
                for (int i = left; i < mid; i++) {
                    if (!knows(i, c2) || knows(c2, i))
                        return -1;
                }
                return c2;
            }
            else if (knows(c2, c1)) {
                for (int i = mid; i < right; i++) {
                    if (!knows(i, c1) || knows(c1, i))
                        return -1;
                }
                return c1;
            }
            else
                return -1;
        }
    }
};












/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        bool stop = false;
        while (!stop) {
            stop = true;
            for (int i = candidate + 1; i < n; i++) {
                if (knows(candidate, i)) {
                    stop = false;
                    candidate = i;
                }
            }
        }
        for (int i = 0; i < candidate; i++) {
            if (knows(candidate, i) || !knows(i, candidate))
                return -1;
        }
        for (int i = candidate + 1; i < n; i++) {
            if (!knows(i, candidate))
                return -1;
        }
        return candidate;
    }
};