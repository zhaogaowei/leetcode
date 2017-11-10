#include "two_sum.h"

using namespace std;

int main() {
	vector<int> nums = { 3,2,4 },v;
	int target = 6;
	Solution s;
	v = s.twoSum(nums, target);
	cout << "[" << v[0] << "," << v[1] <<"]" <<endl;
	system("pause");
	return 0;
}