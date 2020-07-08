//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//
//
//
//示例 :
//
//给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/two-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> sum;
		vector<int> temp = nums;
		sort(temp.begin(), temp.end());
		int i = 0, j = temp.size() - 1;

		bool isTarget = true;
		while (temp[i] + temp[j] != target) {
			if (temp[i] + temp[j] < target) {
				++i;
			}
			else if (temp[i] + temp[j] > target) {
				--j;
			}

			if (i >= j) {
				break;
				isTarget = false;
			}
		}

		if (isTarget) {
			for (int p = 0; p < nums.size(); ++p) {
				if (nums[p] == temp[i]) {
					sum.push_back(p);
				}
				else if (nums[p] == temp[j]) {
					sum.push_back(p);
				}
			}
		}

		return sum;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	int target = 9;

	Solution solution;
	vector<int> result = solution.twoSum(nums, target);

	for (size_t i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;

	std::cout << "OK!" << endl;
}