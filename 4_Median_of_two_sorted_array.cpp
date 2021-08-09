class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 == 0) {
            if (len2 % 2 == 0)
                return (float)(nums2[len2 / 2 - 1] + nums2[len2 / 2]) / 2;
            else
                return nums2[len2 / 2];
        }
        if (len2 == 0) {
            if (len1 % 2 == 0)
                return (float)(nums1[len1 / 2 - 1] + nums1[len1 / 2]) / 2;
            else
                return nums1[len1 / 2];
        }
        int remains = (len1 + len2) / 2 + 1;
        int i1(0), i2(0);
        while (true) {
            if (remains < 10) {
                vector<int> middle;
                int temp1 = i1;
                int temp2 = i2;
                for (int i = 0; i < remains; i++) {
                    if (temp1 < len1 && temp2 < len2) {
                        if (nums1[temp1] <= nums2[temp2]) {
                            middle.push_back(nums1[temp1]);
                            temp1++;
                        }
                        else {
                            middle.push_back(nums2[temp2]);
                            temp2++;
                        }
                    }
                    else {
                        if (temp1 < len1) {
                            middle.push_back(nums1[temp1]);
                            temp1++;
                        }
                        else {
                            if (temp2 < len2) {
                                middle.push_back(nums2[temp2]);
                                temp2++;
                            }
                            else
                                break;
                        }
                    }
                }
                if ((len1 + len2) % 2 == 0)
                    return (float)(middle[remains - 2] + middle[remains - 1]) / 2.;
                else
                    return middle[remains - 1];
            }
            int j1 = min(i1 + remains / 2 - 1, len1 - 1);
            int j2 = min(i2 + remains / 2 - 1, len2 - 1);
            if (nums1[j1] <= nums2[j2]) {
                remains -= j1 - i1;
                i1 = j1;
            } 
            else {
                remains -= j2 - i2;
                i2 = j2;
            }
        }
    }
};