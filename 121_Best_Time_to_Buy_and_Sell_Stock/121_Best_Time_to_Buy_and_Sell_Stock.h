#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
			return 0;
		int pro = 0, temp = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] - temp < 0)
				temp = prices[i];
			pro = max(pro, prices[i] - temp);
		}
		return pro;
	}
};