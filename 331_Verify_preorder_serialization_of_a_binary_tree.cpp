class Solution {
public:
    bool isValidSerialization(string preorder) {
        int intCount = 0;
        int pondCount = 0;
        int i = 0;
        int n = preorder.size();
        bool finished = false;
        while (i < n) {
            if (preorder[i] == '#')
                ++pondCount;
            else
                ++intCount;
            if (pondCount > intCount)
                finished = true;
            i = preorder.find(',', i);
            if (i == string::npos)
                break;
            else if (finished)
                return false;
            ++i;
        }
        return pondCount == intCount + 1;
    }
};