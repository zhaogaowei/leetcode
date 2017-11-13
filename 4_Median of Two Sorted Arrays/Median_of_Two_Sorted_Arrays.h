#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int sum = nums1.size() + nums2.size();
			vector<int> v;
			int m = 0, n = 0;
			if (!nums1.size())
				v = nums2;
			else if (!nums2.size())
				v = nums1;
			else {
				for (int i = 0; i < sum / 2 + 1; ++i) {
					if (nums1[m] < nums2[n]) {
						v.push_back(nums1[m]);
						m++;
						if (m == nums1.size())
							break;
					}
					else
					{
						v.push_back(nums2[n]);
						n++;
						if (n == nums2.size())
							break;
					}
				}
			}
			if (m == nums1.size()) {
				for (int i = n; i < nums2.size(); ++i) {
					v.push_back(nums2[i]);
				}
			}
			else if(n == nums2.size())
			{
				for (int i = m; i < nums1.size(); ++i) {
					v.push_back(nums1[i]);
				}
			}
			if (sum % 2 == 1)
				return (double)v[sum / 2];
			else
				return (double)(v[sum / 2] + v[sum / 2 - 1]) / 2;
		}
};