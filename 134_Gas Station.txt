class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int curr = 0;
        int min_pos = 0;
        int min_gas = 0;
        for (int i = 1; i <= n; i++) {
            curr = curr + gas[i-1] - cost[i-1];
            if (curr < min_gas) {
                min_pos = i;
                min_gas = curr;
            }
        }
        if (curr < 0)
            return -1;
        else 
            return min_pos;
    }
};