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
	string longestPalindrome_1(string s) {
		int startIdx = 0, left = 0, right = 0, len = 0;
		for (int i = 0; i < s.size()-1; ++i) {
			if (s[i] == s[i + 1]) {
				left = i;
				right = i + 1;
				searchPalindrome(s, left, right, startIdx, len);
			}
			left = right = i;
			searchPalindrome(s, left, right, startIdx, len);
		}
		if (len == 0) len = s.size();
		return s.substr(startIdx, len);
	}
	string longestPalindrome_2(string s) {
		int dp[s.size()][s.size()] = { 0 }, left = 0, right = 0, len = 0;
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
				if (dp[j][i] && len < i - j + 1) {
					len = i - j + 1;
					left = j;
					right = i;
				}
			}
			dp[i][i] = 1;
		}
		return s.substr(left, right - left + 1);
	}

private:
	bool isPalindromic(string &s) {
		for (auto i = 0; i < s.length() / 2 + 1; ++i) {
			if (s[i] != s[s.length() - i - 1])
				return false;
		}
		return true;
	}
	void searchPalindrome(string s, int left, int right, int &startIdx, int &len) {
		int step = 1;
		while ((left - step) >= 0 && (right + step) < s.size()) {
			if (s[left - step] != s[right + step]) break;
			++step;
		}
		int wide = right - left + 2 * step - 1;
		if (len < wide) {
			len = wide;
			startIdx = left - step + 1;
		}
	}
};