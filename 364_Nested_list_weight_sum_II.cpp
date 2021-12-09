/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int ans = 0;
        int sums = 0;
        int depth = 1;
        int maxDepth = 1;
        for (NestedInteger& ni : nestedList) {
            explore(ni, depth, maxDepth, sums, ans);
        }
        ans += maxDepth * sums;
        return ans;
    }
    
    void explore(NestedInteger& ni, int depth, int& maxDepth, int& sums, int& ans) {
        if (ni.isInteger()) {
            ans += (1 - depth) * ni.getInteger();
            sums += ni.getInteger();
        }            
        else {
            ++depth;
            maxDepth = max(maxDepth, depth);
            for (NestedInteger& next : ni.getList()) 
                explore(next, depth, maxDepth, sums, ans);
        }
    }
};