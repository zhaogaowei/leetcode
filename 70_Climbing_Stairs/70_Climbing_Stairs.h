#pragma once
#include <iostream>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n < 4)
			return n;
		int a[100] = {1,2,3};
		for (int i = 3; i < n; i++) {
			a[i] = a[i - 1] + a[i - 2];
		}
		return a[n-1];
	}
};