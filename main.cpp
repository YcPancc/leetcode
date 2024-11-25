#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
	int largestSumAfterKNegations(vector<int> &nums, int k) {
		sort(nums.begin(), nums.end());
		int cur = 0;
		while (nums[cur] < 0 && k > 0 && cur < nums.size()) {
			nums[cur] = nums[cur] * -1;
			k--;
			cur++;
		}
		int sum = 0;
		for (const int &num : nums) {
			sum += num;
		}
		if (k % 2 == 0) {
			return sum;
		} else {
			int min_num;
			if (cur == 0) {
				min_num = nums[0];
			} else if (cur == nums.size()) {
				min_num = nums[nums.size() - 1];
			} else {
				min_num = min(nums[cur - 1], nums[cur]);
			}
			return sum - 2 * min_num;
		}
	}
};

int main() {
	Solution s;
	vector<int> arr = {-4, -2};
	int nums = s.largestSumAfterKNegations(arr, 5);
	cout << nums << '\n';
}