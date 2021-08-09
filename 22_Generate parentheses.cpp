class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return generateParenthesis(0, 2*n);
    }
    
    vector<string> generateParenthesis(int count, int remains) {
        unordered_map<int, unordered_map<int, vector<string>>>::iterator it = series.find(remains);
        if (it != series.end()) {
            unordered_map<int, vector<string>>::iterator it2 = it->second.find(count);
            if (it2 != it->second.end())
                return it2->second;
        }
        if (count == remains) {
            string s = "";
            for (int i = 0; i < count; i++)
                s += ")";
            vector<string> sol(1);
            sol[0] = s;
            series[remains][count] = sol;
            return sol;
        }
        if (count == 0) {
            vector<string> temp = generateParenthesis(1, remains-1);
            vector<string> sol = add("(", temp);
            series[remains][count] = sol;
            return sol;
        }
        else {
            vector<string> temp = generateParenthesis(count+1, remains-1);
            vector<string> sol = add("(", temp);
            temp = generateParenthesis(count-1, remains-1);
            vector<string> sol2 = add(")", temp);
            sol.insert(sol.end(), sol2.begin(), sol2.end());
            series[remains][count] = sol;
            return sol;
        }
    }
    
    vector<string> add(string s, vector<string>& vec) {
        int len = vec.size();
        vector<string> sol(len);
        for (int i = 0; i < len; i++) 
            sol[i] = s + vec[i];
        return sol;
    }
    
private:
    unordered_map<int, unordered_map<int, vector<string>>> series;
};


















//brute force; 24 ms 8%; 30.4 MB 6%
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, 0, 0, "", ans);
        return ans;
    }
    
    void generate(int n, int count, int len, string curr, vector<string>& ans) {
        if (len > 2 * n || count < 0 || count > n)
            return;
        if (len == 2 * n && count == 0)
            ans.push_back(curr);
        generate(n, count + 1, len + 1, curr + '(', ans);
        generate(n, count - 1, len + 1, curr + ')', ans);
    }
};














//brute force with backtracking; 8 ms 37%; 17.4 MB 13%
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, 0, 0, "", ans);
        return ans;
    }
    
    void generate(int n, int count, int len, string curr, vector<string>& ans) {
        if (len > 2 * n || count < 0 || count > n || count > 2 * n - len)
            return;
        if (len == 2 * n && count == 0)
            ans.push_back(curr);
        generate(n, count + 1, len + 1, curr + '(', ans);
        generate(n, count - 1, len + 1, curr + ')', ans);
    }
};