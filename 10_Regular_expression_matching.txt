class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(0, 0, s, p);
    }

    bool isMatch(int s_pos, int p_pos, string& s, string& p) {
        unordered_map<int, unordered_set<int> >::iterator its = unmatched.find(p_pos);
        if (its != unmatched.end()) {
            if (its->second.find(s_pos) != its->second.end())
                return false;
        }
        int si = s_pos;
        int pi = p_pos;
        for (; pi < p.size() && si < s.size(); pi++, si++) {
            if (!(pi < p.size() - 1 && p[pi + 1] == '*')) {
                if (p[pi] != '.' && p[pi] != s[si]) {
                    add(s_pos, p_pos);
                    return false;
                }
            }
            else {
                for (; si < s.size(); si++) {
                    if (isMatch(si, pi + 2, s, p))
                        return true;
                    if (p[pi] != '.' && p[pi] != s[si])
                        break;
                }
                break;
            }
        }
        if (si == s.size() && nothing_left(pi, p))
            return true;
        add(s_pos, p_pos);
        return false;
    }

    void add(int s_pos, int p_pos) {
        unordered_map<int, unordered_set<int> >::iterator its = unmatched.find(p_pos);
        if (its != unmatched.end())
            its->second.insert(s_pos);
        else {
            unordered_set<int> set_s;
            set_s.insert(s_pos);
            unmatched.insert(pair<int, unordered_set<int> >(p_pos, set_s));
        }
    }

    bool nothing_left(int p_pos, string& p) {
        for (int i = p.size() - 1; i >= p_pos; i -= 2) {
            if (p[i] != '*')
                return false;
        }
        return true;
    }

private:
    unordered_map<int, unordered_set<int> > unmatched;
};