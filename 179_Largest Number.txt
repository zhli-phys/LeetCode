class Solution {
public:
    struct mysmaller {
        bool operator() (int a, int b) {
            string str_a = to_string(a);
            string str_b = to_string(b);
            return (str_a + str_b > str_b + str_a);
        }
    };
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), mysmaller());
        int n = nums.size();
        string ans = "";
        for (int num : nums)
            ans += to_string(num);
        if (!ans.empty() && ans[0] == '0')
            return "0";
        return ans;
    }
};