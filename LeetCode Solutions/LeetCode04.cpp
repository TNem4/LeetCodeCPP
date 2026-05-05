class Solution {
public:
    double binarySearch(const vector<int>& v1, const vector<int>& v2, int target)
    {
        int leftV1{ 0 };
        int rightV1{ static_cast<int>(v1.size()) - 1 };
        while (leftV1 <= rightV1)
        {
            int index{ leftV1 + (rightV1 - leftV1) / 2 };
            int count{ static_cast<int>(upper_bound(v2.begin(), v2.end(), v1[index]) - v2.begin()) };
            int result{ index + count };
            if (result == target)
            {
                return static_cast<double>(v1[index]);
            }
            if (result < target)
            {
                leftV1 = index + 1;
            }
            else
            {
                rightV1 = index - 1;
            }
        }
        int leftV2{ 0 };
        int rightV2{ static_cast<int>(v2.size()) - 1 };
        while (leftV2 <= rightV2)
        {
            int index{ leftV2 + (rightV2 - leftV2) / 2 };
            int count{ static_cast<int>(upper_bound(v1.begin(), v1.end(), v2[index]) - v1.begin()) };
            int result{ index + count };
            if (result == target)
            {
                return static_cast<double>(v2[index]);
            }
            if (result < target)
            {
                leftV2 = index + 1;
            }
            else
            {
                rightV2 = index - 1;
            }
        }
        leftV1 = 0;
        rightV1 = static_cast<int>(v1.size()) - 1;
        leftV2 = 0;
        rightV2 = static_cast<int>(v2.size()) - 1;
        while (leftV1 <= rightV1)
        {
            int index{ leftV1 + (rightV1 - leftV1) / 2 };
            int count{ static_cast<int>(lower_bound(v2.begin(), v2.end(), v1[index]) - v2.begin()) };
            int result{ index + count };
            if (result == target)
            {
                return static_cast<double>(v1[index]);
            }
            if (result < target)
            {
                leftV1 = index + 1;
            }
            else
            {
                rightV1 = index - 1;
            }
        }
        while (leftV2 <= rightV2)
        {
            int index{ leftV2 + (rightV2 - leftV2) / 2 };
            int count{ static_cast<int>(lower_bound(v1.begin(), v1.end(), v2[index]) - v1.begin()) };
            int result{ index + count };
            if (result == target)
            {
                return static_cast<double>(v2[index]);
            }
            if (result < target)
            {
                leftV2 = index + 1;
            }
            else
            {
                rightV2 = index - 1;
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total{ static_cast<int>((nums1.size() + nums2.size())) };
        if (total % 2 == 0)
        {
            int target1{ total / 2 - 1 };
            int target2{ total / 2 };
            return (binarySearch(nums1, nums2, target1) + binarySearch(nums1, nums2, target2)) / 2.0;
        }
        else
        {
            int target1{ total / 2 };
            return binarySearch(nums1, nums2, target1);
        }

    }
};