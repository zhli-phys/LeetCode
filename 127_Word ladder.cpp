class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int m = beginWord.size();
        vector<unordered_map<string, vector<string>>> mps(m);
        int n = wordList.size();
        for (int i = 0; i < m; ++i) 
            for (auto& word : wordList) 
                mps[i][word.substr(0, i) + word.substr(i+1)].push_back(word);
        int step = 1;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> seen;
        seen.insert(beginWord);
        while (!q.empty()) {
            ++step;
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                auto& curr = q.front();
                // cout << curr << '\t';
                for (int j = 0; j < m; ++j) {
                    string seg = curr.substr(0, j) + curr.substr(j+1);
                    if (mps[j].find(seg) == mps[j].end())
                        continue;
                    for (auto& s : mps[j][seg]) {
                        if (s == endWord)
                            return step;
                        if (seen.find(s) == seen.end()) {
                            q.push(s);
                            seen.insert(s);
                        }
                    }
                }
                q.pop();
            }
            // cout << step << endl;
        }
        return 0;
    }
};


















class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                pos = i;
                break;
            }
        }
        if (pos < 0)
            return 0;
        vector<int> distance(n, 0);
        queue<int> qu;
        for (int i = 0; i < n; i++) {
            if (similar(beginWord, wordList[i])) {
                qu.push(i);
                distance[i] = 2;
            }
        }
        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            for (int i = 0; i < n; i++) {
                if (distance[i] == 0 && similar(wordList[curr], wordList[i])) {
                    distance[i] = distance[curr] + 1;
                    qu.push(i);
                }
            }
        }
        return distance[pos];
    }
       
    bool similar(string str1, string str2) {
        int count = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i])
                count++;
        }
        return (count == 1);
    }
};












class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int m = beginWord.size();
        unordered_map<string, int> distances;
        vector<unordered_map<string, unordered_set<string>>> lists(m);
        for (int i = 0; i < n; i++) {
            string str = wordList[i];
            vector<string> str_stems = stems(str);
            for (int j = 0; j < m; j++) 
                lists[j][str_stems[j]].insert(str);
        }
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                found = true;
                break;
            }
        }
        if (!found)
            return 0;
        queue<string> qu;
        qu.push(beginWord);
        distances[beginWord] = 1;
        cout << beginWord << distances[beginWord] <<endl;
        while (!qu.empty()) {
            string curr = qu.front();
            qu.pop();
            vector<string> curr_stems = stems(curr);
            for (int j = 0; j < m; j++) {
                unordered_map<string, unordered_set<string>>::iterator it = lists[j].find(curr_stems[j]);
                if (it != lists[j].end()) {
                    for (unordered_set<string>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
                        if (*it2 == endWord)
                            return distances[curr] + 1;
                        unordered_map<string, int>::iterator it3 = distances.find(*it2);
                        if (it3 == distances.end()) {
                            distances[*it2] = distances[curr] + 1;
                            qu.push(*it2);
                            cout << *it2 << distances[*it2] << endl;
                        }
                    }
                }
            }
        }
        return 0;
    }
    
    vector<string> stems(string str) {
        int n = str.size();
        vector<string> ans(0);
        for (int i = 0; i < n; i++) {
            string temp = str;
            ans.push_back(temp.erase(i, 1));
        }
        return ans;
    }
    
    bool similar(string str1, string str2) {
        int count = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i])
                count++;
        }
        return (count == 1);
    }
};