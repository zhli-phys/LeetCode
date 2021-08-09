class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        if (s.empty())
            return true;
        if (wrong_answers.find(s) != wrong_answers.end())
            return false;
        for (int i = 0; i < wordDict.size(); i++)
        {
            int j = wordDict[i].size();
            if (wordDict[i] == s.substr(0, j) && wordBreak(s.substr(j, s.size() - j), wordDict))
                return true;
        }
        wrong_answers.insert(s);
        return false;
    }

private:
    unordered_set<string> wrong_answers;
};