#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
	string convert(string &s, int numRows) {
		if (s.length() == 0 || s.length() == 1 || numRows == 1)
			return s;
		vector<string> v;
		v.resize(numRows);
		int row = 0, delta = 1;
		for (int i = 0; i < s.length(); ++i) {
			v[row].push_back(s[i]);
			row += delta;
			if (row >= numRows) {
				row = numRows - 2;
				delta = -1;
			}
			if (row < 0) {
				row = 1;
				delta = 1;
			}
		}
		string str="";
		for (int i = 0; i < numRows; i++) {
			str += v[i];
		}
		return str;
	}
};