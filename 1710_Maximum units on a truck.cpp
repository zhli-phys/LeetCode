class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), my_comp);
        int max_units = 0;
        for (auto& box : boxTypes) {
            if (truckSize >= box[0]) {
                max_units += box[0] * box[1];
                truckSize -= box[0];
            }
            else {
                max_units += truckSize * box[1];
                return max_units;
            }
        }
        return max_units;
    }
    
    static inline bool my_comp(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }
};


















class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), 
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });
        int max_units = 0;
        for (auto& box : boxTypes) {
            if (truckSize >= box[0]) {
                max_units += box[0] * box[1];
                truckSize -= box[0];
            }
            else {
                max_units += truckSize * box[1];
                return max_units;
            }
        }
        return max_units;
    }
};