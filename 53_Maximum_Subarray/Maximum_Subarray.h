#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		int sum=nums[0], max1= nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			if (sum < 0)
				sum = nums[i];
			else
				sum += nums[i];
			max1 = max(sum, max1);
		}
		return max1;
	}
};