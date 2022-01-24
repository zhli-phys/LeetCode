class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1)
            return true;
        bool firstCapital = false;        
        if (word[0] >= 'A' && word[0] <= 'Z')
            firstCapital = true;
        if (!firstCapital) {
            for (int i = 1; i < n; ++i) 
                if (word[i] >= 'A' && word[i] <= 'Z') 
                    return false;
        }
        else {
            bool secondCapital = false;
            if (word[1] >= 'A' && word[1] <= 'Z')
                secondCapital = true;
            if (secondCapital) {
                for (int i = 2; i < n; ++i)
                    if (word[i] >= 'a' && word[i] <= 'z')
                        return false;
            }
            else {
                for (int i = 2; i < n; ++i) 
                    if (word[i] >= 'A' && word[i] <= 'Z') 
                        return false;
            }
        }        
        return true;
    }
};