#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
            m[nums[i]] = i;
        
        for (int i = 0; i < nums.size(); ++i) {
            auto match = m.find(target - nums[i]);
            if (match != m.end() && match->second != i)
                return { i, match->second };
        }
        
        return {0, 0};
    }
};
