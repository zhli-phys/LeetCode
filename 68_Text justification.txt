class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;
        queue<string> q;
        int curr = 0;
        for (auto && word : words) {
            if (curr + word.size() <= maxWidth) {
                q.push(word);
                curr += (word.size() + 1);
            }
            else {
                string temp = "";
                int m = q.size();
                if (m == 1) {
                    temp += q.front();
                    temp += string(maxWidth - curr + 1, ' ');
                    q.pop();
                }
                else {
                    int space = (maxWidth - curr + m) / (m - 1);
                    int residule = (maxWidth - curr + m) % (m - 1);
                    for (int i = 0; i < m - 1; ++i) {
                        temp += q.front();
                        temp += i < residule ? string(space + 1, ' ') : string(space, ' ');
                        q.pop();
                    }
                    temp += q.front();
                    q.pop();
                }
                output.push_back(temp);
                q.push(word);
                curr = word.size() + 1;
            }
        }
        string last;
        while (!q.empty()) {
            last += q.front();
            last += ' ';
            q.pop();
        }
        if (curr > maxWidth) 
            last = last.substr(0, maxWidth);
        else 
            last += string(maxWidth - last.size(), ' ');
        output.push_back(last);
        return output;
    }
};