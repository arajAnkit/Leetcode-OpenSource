class Solution
{
public:
    Solution()
    {
        ios_base ::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    // Solutin 1 - Brute Force
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nums(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
        sort(nums.begin(), nums.end());
        if (nums.size() % 2 == 0)
        {
            return (float)(nums[((nums.size()) / 2) - 1] + nums[((nums.size()) / 2)]) / 2;
        }
        else
        {
            return nums[((nums.size() + 1) / 2) - 1];
        }
    }

    ____________________________________________________________________________________________________
    // Solution 2 - Brute Force
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                merged.push_back(nums1[i++]);
            }
            else
            {
                merged.push_back(nums2[j++]);
            }
        }
        while (i < nums1.size())
            merged.push_back(nums1[i++]);
        while (j < nums2.size())
            merged.push_back(nums2[j++]);

        int mid = merged.size() / 2;
        if (merged.size() % 2 == 0)
        {
            return (merged[mid - 1] + merged[mid]) / 2.0;
        }
        else
        {
            return merged[mid];
        }
    }

    ____________________________________________________________________________________________________
    // Solution 3 - Binary Search Optimized Code
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        // Perform the Binary Search on Small Array
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1); // Change the parameters
        }

        // Find the size of both array
        int m = nums1.size();
        int n = nums2.size();

        // Take 2 pointer as we use in normal binary search
        int start = 0;
        int end = m;

        // Perform binary search
        while (start <= end)
        {
            // Find the partitions
            int partition1 = (start + end) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            // Find the four element
            int maxLeftNums1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
            int maxLeftNums2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];

            int minRightNums1 = partition1 == m ? INT_MAX : nums1[partition1];
            int minRightNums2 = partition2 == n ? INT_MAX : nums2[partition2];

            if (maxLeftNums1 <= minRightNums2 && maxLeftNums2 <= minRightNums1)
            {
                if ((m + n) % 2 == 0)
                {
                    return (double)(max(maxLeftNums1, maxLeftNums2) + min(minRightNums1, minRightNums2)) / 2;
                }
                else
                    return (double)max(maxLeftNums1, maxLeftNums2);
            }
            else if (maxLeftNums1 > minRightNums2)
                end = partition1 - 1;
            else
                start = partition1 + 1;
        }

        return -1;
    }
};