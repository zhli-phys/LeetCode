//Using linked list to store ends
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        list<pair<int, int>> ends;
        vector<vector<int>> ans;
        int curr_height = 0;
        for (int i = 0; i < n; i++) {
            while (!ends.empty() && ends.begin()->first < buildings[i][0]) {
                vector<int> bi(2);
                bi[0] = ends.begin()->first;
                ends.erase(ends.begin());
                curr_height = ends.begin()->second;
                bi[1] = curr_height;
                ans.push_back(bi);
            }
            if (buildings[i][2] > curr_height) {
                curr_height = buildings[i][2];
                if (!ans.empty() && ans[ans.size()-1][0] == buildings[i][0]) 
                    ans[ans.size()-1][1] = curr_height;
                else {
                    vector<int> bi(2);
                    bi[0] = buildings[i][0];
                    bi[1] = curr_height;
                    ans.push_back(bi);
                }
            }
            list<pair<int, int>>::iterator it = ends.begin();
            while (it != ends.end() && it->first < buildings[i][1]) {
                if (it->second <= buildings[i][2])
                    it = ends.erase(it);
                else
                    it++;
            }
            if (it->first == buildings[i][1]) 
                it->second = max(it->second, buildings[i][2]);
            else if (it->second < buildings[i][2])
                ends.insert(it, pair<int, int>(buildings[i][1], buildings[i][2]));
        }
        while (!ends.empty()) {
            vector<int> bi(2);
            bi[0] = ends.begin()->first;
            ends.erase(ends.begin());
            curr_height = ends.begin()->second;
            bi[1] = curr_height;
            ans.push_back(bi);
        }
        return ans;
    }
};






//Divide and conquer
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return getSkyline(0, buildings.size(), buildings);
    }
    
    vector<vector<int>> getSkyline(int left, int right, vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        if (left >= right)
            return ans;
        if (left == right - 1) {
            vector<int> bi(2);
            bi[0] = buildings[left][0];
            bi[1] = buildings[left][2];
            ans.push_back(bi);
            bi[0] = buildings[left][1];
            bi[1] = 0;
            ans.push_back(bi);
            return ans;
        }
        int mid = (left + right) / 2;
        vector<vector<int>> l = getSkyline(left, mid, buildings);
        vector<vector<int>> r = getSkyline(mid, right, buildings);
        int left_height = 0;
        int right_height = 0;
        int curr_height = 0;
        int lpos = 0;
        int rpos = 0;
        int lsize = l.size();
        int rsize = r.size();
        while (true) {
            int curr;
            if (rpos >= rsize || (lpos < lsize && l[lpos][0] < r[rpos][0])) {
                left_height = l[lpos][1];
                curr = l[lpos][0];
                lpos++;
            }
            else if (lpos >= lsize || (rpos < rsize && l[lpos][0] > r[rpos][0])) {
                right_height = r[rpos][1];
                curr = r[rpos][0];
                rpos++;
            }
            else {
                curr = l[lpos][0];
                left_height = l[lpos][1];
                right_height = r[rpos][1];
                lpos++;
                rpos++;
            }
            int height = max(left_height, right_height);
            if (height != curr_height) {
                vector<int> bi(2);
                bi[0] = curr;
                bi[1] = height;
                curr_height = height;
                ans.push_back(bi);
            }
            if (lpos >= lsize && rpos>= rsize)
                break;
        }
        return ans;
    }
};