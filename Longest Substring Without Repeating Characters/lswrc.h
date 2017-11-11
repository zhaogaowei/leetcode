#pragma once
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string &s) {
		string substr;
		if (s == "")
			return 0;
		int maxlen = 1;
		for (auto i = s.cbegin(); i != s.cend()-1; ++i) {
			for (auto j = i; j != s.cend(); ++j) {
				substr = string(i, j+1);
				if (!unique(substr))
					continue;
				else {
					maxlen = maxlen > substr.length() ? maxlen : substr.length();
				}
			}
		}
		return maxlen;
	}
	int lengthOfLongestSubstring_1(string &s) {
		int m[256] = { 0 }, res = 0, left = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (m[s[i]] == 0 || m[s[i]] < left) {
				res = res > i - left + 1 ? res : i - left + 1;
			}
			else
			{
				left = m[s[i]];
			}
			m[s[i]] = i + 1;
		}
		return res;
	}

private:
	bool unique(string &s) {
		for (int i = 0; i < s.length()-1; ++i) {
			for (int j = i + 1; j < s.length(); ++j) {
				if (s[i] == s[j])
					return false;
			}
		}
		return true;
	}
};