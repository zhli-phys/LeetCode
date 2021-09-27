class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;
        for (auto& email : emails) {
            string curr;
            for (int i = 0; i < email.size(); ++i) {
                if (email[i] == '@') {
                    curr += email.substr(i);
                    break;
                }
                else if (email[i] == '+') {
                    while (email[i] != '@')
                        ++i;
                    --i;
                }
                else if (email[i] != '.')
                    curr += email[i];
            }
            unique.insert(curr);
        }
        return unique.size();
    }
};