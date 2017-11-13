#pragma once
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() == 1)
			return s;
		string subStr,temp;
		for (auto i = s.cbegin(); i != s.cend()-1;++i) {
			for (auto j = i; j !=s.cend(); ++j) {
				temp = string(i, j+1);
				if (isPalindromic(temp) && temp.length() > subStr.length())
					subStr = temp;
			}
		}
		return subStr;
	}
	string longestPalindrome_1(string &s) {
		int a[256] = { 0 }, left = 0, res = 0;
		string substr;
		for (auto i = 0; i < s.size(); ++i) {
			if (a[s[i]] == 0 || a[s[i]] < left) {
				res = res > i - left + 1 ? res : i - left + 1;
			}
			else
			{
				left = a[s[i]];
			}
			a[s[i]] = i + 1;
		}
		substr = string(s.begin() + left-1, s.begin() + left + res);
		return substr;
	}

private:
	bool isPalindromic(string &s) {
		for (auto i = 0; i < s.length() / 2 + 1; ++i) {
			if (s[i] != s[s.length() - i - 1])
				return false;
		}
		return true;
	}
};