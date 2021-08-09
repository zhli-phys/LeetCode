class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int dir_x = 0;
        int dir_y = 1;
        for (int i = 0; i < 4; ++i) {
            for (char ch : instructions) {
                if (ch == 'G') {
                    x += dir_x;
                    y += dir_y;
                }
                else if (ch == 'R') {
                    swap(dir_x, dir_y);
                    if (dir_x == 0)
                        dir_y = -dir_y;
                }
                else {
                    swap(dir_x, dir_y);
                    if (dir_y == 0)
                        dir_x = -dir_x;
                }
            }
        }
        return (x == 0 && y == 0);
    }
};











class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        for (int i = 0; i < 4; ++i) {
            for (char ch : instructions) {
                if (ch == 'G') {
                    x += directions[dir].first;
                    y += directions[dir].second;
                }
                else if (ch == 'R') 
                    dir = (dir + 1) % 4;
                else
                    dir = (dir + 3) % 4;
            }
        }
        return (x == 0 && y == 0);
    }
};












class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        for (char ch : instructions) {
            if (ch == 'G') {
                x += directions[dir].first;
                y += directions[dir].second;
            }
            else if (ch == 'R') 
                dir = (dir + 1) % 4;
            else
                dir = (dir + 3) % 4;
        }
        return (x == 0 && y == 0) || (dir != 0);
    }
};