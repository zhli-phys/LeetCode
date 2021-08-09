class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0; 
        int j = s.size() - 1;
        while (i < j) {
            char left = s[i];
            while (i < j && !((left >= 'a' && left <= 'z') || (left >= '0' && left <= '9') || (left >= 'A' && left <= 'Z'))) 
                left = s[++i];
            if (left >= 'A' && left <= 'Z')
                left = left - 'A' + 'a';
            char right = s[j];
            while (i < j && !((right >= 'a' && right <= 'z') || (right >= '0' && right <= '9') || (right >= 'A' && right <= 'Z'))) 
                right = s[--j];
            if (right >= 'A' && right <= 'Z')
                right = right - 'A' + 'a';
            if (left != right)
                return false;
            i++;
            j--;
        }
        return true;
    }
};