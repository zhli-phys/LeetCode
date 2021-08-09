class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty())
            return "";
        vector<vector<bool>> smaller(26, vector<bool>(26, false));
        vector<bool> indict(26, false);
        int n = words.size();
        if (n == 1)
            return words[0];
        string prev;
        string curr = words[0];
        for (int i = 0; i < n; i++) {
            for (char ch : words[i])
            indict[ch-'a'] = true;
        }
        for (int i = 1; i < n; i++) {
            prev = curr;
            curr = words[i];
            int len1 = prev.size();
            int len2 = curr.size();
            int len = min(len1, len2);
            bool identical = true;
            for (int j = 0; j < len; j++) {
                if (prev[j] != curr[j]) {
                    if (smaller[curr[j]-'a'][prev[j]-'a'])
                        return "";
                    else {
                        smaller[prev[j]-'a'][curr[j]-'a'] = true;
                        identical = false;
                        break;
                    }
                }
            }
            if (identical && len1 > len2)
                return "";
        }
        
        string ans = "";
        bool head_exist = true;
        while (head_exist) {
            head_exist = false;
            for (int i = 0; i < 26; i++) {
                if (!indict[i])
                    continue;
                bool head = true;
                for (int j = 0; j < 26; j++) {
                    if (smaller[j][i]) {
                        head = false;
                        break;
                    }
                }
                if (head) {
                    indict[i] = false;
                    for (int k = 0; k < 26; k++) 
                        smaller[i][k] = false;
                    ans += ('a' + i);
                    head_exist = true;
                } 
            }
        }   
        for (int i = 0; i < 26; i++) {
            if (indict[i])
                    return "";
        }
        return ans;
    }
};