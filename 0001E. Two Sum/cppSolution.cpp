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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
    ____________________________________________________________________________________________________
    // Solution 2 - Optimized Code
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Declare an unordered map to store the numbers and their indices
        unordered_map<int, int> mp;

        // Loop through the array
        for (int i = 0; i < nums.size(); i++)
        {
            // Check if the complement of the current number exists in the map
            if (mp.find(target - nums[i]) == mp.end())
                // If not, add the current number and its index to the map
                mp[nums[i]] = i;
            else
                // If yes, return the indices of the current number and its complement
                return {mp[target - nums[i]], i};
        }

        // If no pair is found, return {-1, -1} as a default value
        return {-1, -1};
    }

    ____________________________________________________________________________________________________
    // Solution 3 - Single Pass Optimized Code
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Declare a hash map to store the numbers and their indices
        unordered_map<int, int> mp;
        // Loop through the array
        for (int i = 0; i < nums.size(); i++)
        {
            // Calculate the complement of the current number
            int complement = target - nums[i];
            // Check if the complement exists in the hash map
            if (mp.count(complement))
            {
                // If yes, return the indices of the current number and its
                // complement
                return {mp[complement], i};
            }
            // If not, add the current number and its index to the hash map
            mp[nums[i]] = i;
        }
        // If no pair is found, return an empty vector as a default value
        return {-1, -1};
    }
};