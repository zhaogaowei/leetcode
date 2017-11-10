#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> v;
		for (auto i = 0; i < nums.size(); ++i) {
			for (auto j = 1; j <nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					v.push_back(i);
					v.push_back(j);
				}
			}
		}
		return v;
	}
};
