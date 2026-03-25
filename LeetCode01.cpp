#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map <int, int> map;
        //int temp{};
        for (size_t i{ 0 }; i < nums.size(); ++i)
        {
            int temp{ target - nums[i] };
            if (map.find(temp) != map.end())
            {
                return { static_cast<int>(i), map[temp] };
            }
            map[nums[i]] = i;
        }
        return { 0,0 };
    }
};