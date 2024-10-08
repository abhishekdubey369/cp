/*
 * Created by: Abhishek Dubey
 * Created on: 2023-10-14
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane's algo
        int cur_sum = 0, max_sum = INT_MIN;
        for(const int x : nums) {
            cur_sum += x;
            max_sum = max(max_sum, cur_sum);
            if(cur_sum < 0)
                cur_sum = 0;
        }
        return max_sum;
    }
};